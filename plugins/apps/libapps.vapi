/* libapps.vapi generated by valac-0.16 0.16.1, do not modify. */

[CCode (cheader_filename = "AppsPlugin.h")]
public class AppsPlugin : Peas.ExtensionBase, Peas.Activatable {
	public AppsPlugin ();
	public virtual void activate ();
	public virtual void deactivate ();
	public virtual void update_state ();
}
[CCode (cheader_filename = "AppsPlugin.h")]
[ModuleInit]
public static void peas_register_types (GLib.TypeModule module);
