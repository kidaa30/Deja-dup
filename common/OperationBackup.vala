/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
/*
    This file is part of Déjà Dup.
    For copyright information, see AUTHORS.

    Déjà Dup is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Déjà Dup is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Déjà Dup.  If not, see <http://www.gnu.org/licenses/>.
*/

using GLib;

namespace DejaDup {

public class OperationBackup : Operation
{
  File metadir;

  public OperationBackup() {
    Object(mode: ToolJob.Mode.BACKUP);
  }
  
  internal async override void operation_finished(ToolJob job, bool success, bool cancelled, string? detail)
  {
    /* If successfully completed, update time of last backup and run base operation_finished */
    if (success)
      DejaDup.update_last_run_timestamp(DejaDup.TimestampType.BACKUP);

    if (metadir != null)
      new RecursiveDelete(metadir).start();

    if (success && !cancelled)
      yield chain_op(new OperationVerify(), _("Verifying backup…"), detail);
    else
      yield base.operation_finished(job, success, cancelled, detail);
  }

  protected override void send_action_file_changed(File file, bool actual)
  {
    // Intercept action_file_changed signals and ignore them if they are
    // metadata file, the user doesn't need to see them.
    if (!file.has_prefix(metadir))
      base.send_action_file_changed(file, actual);
  }

  protected void save_gsettings(string schema)
  {
    var appsetlist = DejaDup.get_app_settings(schema);
    var keys_val = appsetlist.list_keys();
    string result = "";
    foreach(string s in keys_val) {
        var t_val = appsetlist.get_value(s);
	string type = t_val.get_type_string();
        if("b" == type) {
                result = schema+" "+s+" "+appsetlist.get_boolean(s).to_string();
        }
        if("i" == type) {
                result = schema+" "+s+" "+appsetlist.get_int(s).to_string();
        }
        if("s" == type) {
                result = schema+" "+s+" "+(string)t_val;
        }
        if("as" == type) {
                result = schema+" "+s+" ";
                string*[] list = t_val.get_strv();
                foreach (string ss in list) {
			if(list[0] == ss)
                          result = result+ss;
			else
                          result = result+","+ss;
                }
        }
	string home_dir = Environment.get_home_dir();
        File file = File.new_for_path (home_dir+"/.apps-gsettings");
        FileOutputStream os;
        try {
          bool tmp = file.query_exists ();
          if (tmp == true) {
            os = file.append_to (FileCreateFlags.NONE);
            os.write ((result+"\n").data);
          } else {
            os = file.create (FileCreateFlags.PRIVATE);
            os.write ((result+"\n").data);
          }
        } catch (Error e) {
            stdout.printf ("Error: %s\n", e.message);
        }
    }
    var children_val = appsetlist.list_children();
    foreach(string child in children_val){
        save_gsettings(appsetlist.get_child(child).schema);
    }
  }

  protected override List<string>? make_argv()
  {
    var settings = get_settings();
    
    var include_val = settings.get_value(INCLUDE_LIST_KEY);
    var include_list = parse_dir_list(include_val.get_strv());
    var exclude_val = settings.get_value(EXCLUDE_LIST_KEY);
    var exclude_list = parse_dir_list(exclude_val.get_strv());

    var apps_settings = DejaDup.get_settings(APPS_ROOT);
    var apps_val = apps_settings.get_value(APPS_LIST_KEY);
    var apps_list = parse_dir_list(apps_val.get_strv());
    
    // Exclude directories no one wants to backup
    var always_excluded = get_always_excluded_dirs();
    foreach (string dir in always_excluded)
      job.excludes.prepend(File.new_for_path(dir));
    
    foreach (File s in exclude_list)
      job.excludes.prepend(s);
    foreach (File s in include_list)
      job.includes.prepend(s);
    foreach (File s in apps_list)
      job.includes.prepend(s);

    string home_dir = Environment.get_home_dir();
    File file_save = File.new_for_path (home_dir+"/.apps-gsettings");
    bool tmp = file_save.query_exists();
    if (tmp == true) {
      try {
        file_save.delete ();
      }catch (Error e) {
	stdout.printf ("Error: %s\n", e.message);
      }
    }
    else {
      try {
	file_save.create (FileCreateFlags.PRIVATE);
      }catch (Error e) {
        stdout.printf ("Error: %s\n", e.message);
      }
    }

    var app_settings = DejaDup.get_settings(APPS_ROOT);
    foreach (string app in app_settings.list_children()) {
      var file = File.new_for_path("/usr/bin/"+app);
      if(file.query_exists()) {
        var set = DejaDup.get_settings(APPS_ROOT+"."+app);
	var val = set.get_boolean(BACKUP_KEY);
	if(val == true) {
          var schema = set.get_string("settings");
	  if(schema!="")
	    save_gsettings(schema);
	}
      }
    }

    // Insert deja-dup meta info directory
    string cachedir = Environment.get_user_cache_dir();
    try {
      metadir = File.new_for_path(Path.build_filename(cachedir, Config.PACKAGE, "metadata"));
      fill_metadir();
      job.includes.prepend(metadir);
    }
    catch (Error e) {
      warning("%s\n", e.message);
    }
    
    job.local = File.new_for_path("/");

    return null;
  }
  
  List<string> get_always_excluded_dirs()
  {
    List<string> rv = new List<string>();
    
    // User doesn't care about cache
    string dir = Environment.get_user_cache_dir();
    if (dir != null) {
      rv.append(dir);
      // We also add our special cache dir because if the user still especially
      // includes the cache dir, we still won't backup our own metadata.
      rv.append(Path.build_filename(dir, Config.PACKAGE));
    }

    // Likewise, user doesn't care about cache-like directories in $HOME.
    // In an ideal world, all of these would be under ~/.cache.  But for
    // historical reasons or for those apps that are both popular enough to
    // warrant special attention, we add some useful exclusions here.
    // When changing this list, remember to update the help documentation too.
    dir = Environment.get_home_dir();
    if (dir != null) {
      rv.append(Path.build_filename(dir, ".adobe/Flash_Player/AssetCache"));
      rv.append(Path.build_filename(dir, ".gvfs"));
      rv.append(Path.build_filename(dir, ".Private")); // encrypted copies of stuff in $HOME
      rv.append(Path.build_filename(dir, ".recent-applications.xbel"));
      rv.append(Path.build_filename(dir, ".recently-used.xbel"));
      rv.append(Path.build_filename(dir, ".thumbnails"));
      rv.append(Path.build_filename(dir, ".xsession-errors"));
    }
    
    // Some problematic directories like /tmp and /proc should be left alone
    dir = Environment.get_tmp_dir();
    if (dir != null)
      rv.append(dir);
    
    rv.append("/proc");
    rv.append("/sys");
    
    return rv;
  }

  void fill_metadir() throws Error
  {
    if (metadir == null)
      return;

    // Delete old dir, if any, and replace it
    new RecursiveDelete(metadir).start();
    metadir.make_directory_with_parents(null);

    // Put a file in there that is one part always constant, and one part
    // always different, for basic sanity checking.  This way, it will be
    // included in every backup, but we can still check its contents for
    // corruption.  We'll stuff seconds-since-epoch in it.
    var now = new DateTime.now_utc();
    var msg = "This folder can be safely deleted.\n%s".printf(now.format("%s"));
    FileUtils.set_contents(Path.build_filename(metadir.get_path(), "README"), msg);
  }
}

} // end namespace

