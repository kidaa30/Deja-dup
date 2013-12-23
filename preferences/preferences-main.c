/* preferences-main.c generated by valac 0.16.1, the Vala compiler
 * generated from preferences-main.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <config.h>
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>
#include <common.h>
#include <widgets.h>
#include <gio/gio.h>


#define TYPE_PREFERENCES_APP (preferences_app_get_type ())
#define PREFERENCES_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PREFERENCES_APP, PreferencesApp))
#define PREFERENCES_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PREFERENCES_APP, PreferencesAppClass))
#define IS_PREFERENCES_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PREFERENCES_APP))
#define IS_PREFERENCES_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PREFERENCES_APP))
#define PREFERENCES_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PREFERENCES_APP, PreferencesAppClass))

typedef struct _PreferencesApp PreferencesApp;
typedef struct _PreferencesAppClass PreferencesAppClass;
typedef struct _PreferencesAppPrivate PreferencesAppPrivate;

#define DEJA_DUP_TYPE_PREFERENCES (deja_dup_preferences_get_type ())
#define DEJA_DUP_PREFERENCES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_PREFERENCES, DejaDupPreferences))
#define DEJA_DUP_PREFERENCES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_PREFERENCES, DejaDupPreferencesClass))
#define DEJA_DUP_IS_PREFERENCES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_PREFERENCES))
#define DEJA_DUP_IS_PREFERENCES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_PREFERENCES))
#define DEJA_DUP_PREFERENCES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_PREFERENCES, DejaDupPreferencesClass))

typedef struct _DejaDupPreferences DejaDupPreferences;
typedef struct _DejaDupPreferencesClass DejaDupPreferencesClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))

struct _PreferencesApp {
	GObject parent_instance;
	PreferencesAppPrivate * priv;
};

struct _PreferencesAppClass {
	GObjectClass parent_class;
};


static gpointer preferences_app_parent_class = NULL;
static gboolean preferences_app_show_version;
static gboolean preferences_app_show_version = FALSE;

GType preferences_app_get_type (void) G_GNUC_CONST;
enum  {
	PREFERENCES_APP_DUMMY_PROPERTY
};
static gboolean preferences_app_handle_console_options (gint* status);
static void preferences_app_activated (GtkApplication* app);
DejaDupPreferences* deja_dup_preferences_new (void);
DejaDupPreferences* deja_dup_preferences_construct (GType object_type);
GType deja_dup_preferences_get_type (void) G_GNUC_CONST;
gint preferences_app_main (gchar** args, int args_length1);
static void __lambda9_ (GApplication* app);
static void ___lambda9__g_application_activate (GApplication* _sender, gpointer self);
PreferencesApp* preferences_app_new (void);
PreferencesApp* preferences_app_construct (GType object_type);
static void preferences_app_finalize (GObject* obj);

static const GOptionEntry PREFERENCES_APP_options[2] = {{"version", (gchar) 0, 0, G_OPTION_ARG_NONE, &preferences_app_show_version, "Show version", NULL}, {NULL}};

static gboolean preferences_app_handle_console_options (gint* status) {
	gint _vala_status = 0;
	gboolean result = FALSE;
	gboolean _tmp0_;
	_vala_status = 0;
	_tmp0_ = preferences_app_show_version;
	if (_tmp0_) {
		g_print ("%s %s\n", "deja-dup-preferences", VERSION);
		result = FALSE;
		if (status) {
			*status = _vala_status;
		}
		return result;
	}
	result = TRUE;
	if (status) {
		*status = _vala_status;
	}
	return result;
}


static void preferences_app_activated (GtkApplication* app) {
	GtkApplication* _tmp0_;
	GList* _tmp1_ = NULL;
	GList* list;
	GList* _tmp2_;
	g_return_if_fail (app != NULL);
	_tmp0_ = app;
	_tmp1_ = gtk_application_get_windows (_tmp0_);
	list = _tmp1_;
	_tmp2_ = list;
	if (_tmp2_ != NULL) {
		GList* _tmp3_;
		gconstpointer _tmp4_;
		guint32 _tmp5_ = 0U;
		_tmp3_ = list;
		_tmp4_ = _tmp3_->data;
		_tmp5_ = gtk_get_current_event_time ();
		gtk_window_present_with_time ((GtkWindow*) _tmp4_, _tmp5_);
	} else {
		GtkWindow* _tmp6_;
		GtkWindow* _tmp7_;
		GtkWindow* dlg;
		GtkWindow* _tmp8_;
		const gchar* _tmp9_ = NULL;
		GtkWindow* _tmp10_;
		DejaDupPreferences* _tmp11_;
		DejaDupPreferences* _tmp12_;
		DejaDupPreferences* prefs;
		DejaDupPreferences* _tmp13_;
		GtkWindow* _tmp14_;
		DejaDupPreferences* _tmp15_;
		GtkWindow* _tmp16_;
		GtkApplication* _tmp17_;
		GtkWindow* _tmp18_;
		_tmp6_ = (GtkWindow*) gtk_window_new (GTK_WINDOW_TOPLEVEL);
		_tmp7_ = g_object_ref_sink (_tmp6_);
		dlg = _tmp7_;
		_tmp8_ = dlg;
		_tmp9_ = _ ("Backup");
		gtk_window_set_title (_tmp8_, _tmp9_);
		_tmp10_ = dlg;
		gtk_window_set_resizable (_tmp10_, FALSE);
		_tmp11_ = deja_dup_preferences_new ();
		_tmp12_ = g_object_ref_sink (_tmp11_);
		prefs = _tmp12_;
		_tmp13_ = prefs;
		gtk_container_set_border_width ((GtkContainer*) _tmp13_, (guint) 12);
		_tmp14_ = dlg;
		_tmp15_ = prefs;
		gtk_container_add ((GtkContainer*) _tmp14_, (GtkWidget*) _tmp15_);
		_tmp16_ = dlg;
		_tmp17_ = app;
		gtk_window_set_application (_tmp16_, _tmp17_);
		_tmp18_ = dlg;
		gtk_widget_show_all ((GtkWidget*) _tmp18_);
		_g_object_unref0 (prefs);
		_g_object_unref0 (dlg);
	}
}


static void __lambda9_ (GApplication* app) {
	GApplication* _tmp0_;
	g_return_if_fail (app != NULL);
	_tmp0_ = app;
	preferences_app_activated (GTK_IS_APPLICATION (_tmp0_) ? ((GtkApplication*) _tmp0_) : NULL);
}


static void ___lambda9__g_application_activate (GApplication* _sender, gpointer self) {
	__lambda9_ (_sender);
}


gint preferences_app_main (gchar** args, int args_length1) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	GOptionContext* _tmp1_;
	GOptionContext* context;
	GOptionContext* _tmp2_;
	GOptionContext* _tmp3_;
	GOptionGroup* _tmp4_ = NULL;
	gint status = 0;
	gint _tmp11_ = 0;
	gboolean _tmp12_ = FALSE;
	GtkIconTheme* _tmp13_ = NULL;
	gboolean _tmp14_ = FALSE;
	GtkApplication* _tmp15_;
	GtkApplication* app;
	GtkApplication* _tmp16_;
	GtkApplication* _tmp17_;
	gint _tmp18_ = 0;
	GError * _inner_error_ = NULL;
	deja_dup_i18n_setup ();
	_tmp0_ = _ ("Backup");
	g_set_application_name (_tmp0_);
	_tmp1_ = g_option_context_new ("");
	context = _tmp1_;
	_tmp2_ = context;
	g_option_context_add_main_entries (_tmp2_, PREFERENCES_APP_options, GETTEXT_PACKAGE);
	_tmp3_ = context;
	_tmp4_ = gtk_get_option_group (FALSE);
	g_option_context_add_group (_tmp3_, _tmp4_);
	{
		GOptionContext* _tmp5_;
		_tmp5_ = context;
		g_option_context_parse (_tmp5_, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp6_;
		const gchar* _tmp7_;
		GOptionContext* _tmp8_;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = e;
		_tmp7_ = _tmp6_->message;
		_tmp8_ = context;
		_tmp9_ = g_option_context_get_help (_tmp8_, TRUE, NULL);
		_tmp10_ = _tmp9_;
		g_printerr ("%s\n\n%s", _tmp7_, _tmp10_);
		_g_free0 (_tmp10_);
		result = 1;
		_g_error_free0 (e);
		_g_option_context_free0 (context);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (context);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp12_ = preferences_app_handle_console_options (&_tmp11_);
	status = _tmp11_;
	if (!_tmp12_) {
		result = status;
		_g_option_context_free0 (context);
		return result;
	}
	gtk_init (&args_length1, &args);
	_tmp13_ = gtk_icon_theme_get_default ();
	gtk_icon_theme_append_search_path (_tmp13_, THEME_DIR);
	gtk_window_set_default_icon_name (PACKAGE);
	_tmp14_ = deja_dup_gui_initialize (NULL, TRUE);
	if (!_tmp14_) {
		result = 1;
		_g_option_context_free0 (context);
		return result;
	}
	_tmp15_ = gtk_application_new ("org.gnome.DejaDup.Preferences", 0);
	app = _tmp15_;
	_tmp16_ = app;
	g_signal_connect ((GApplication*) _tmp16_, "activate", (GCallback) ___lambda9__g_application_activate, NULL);
	_tmp17_ = app;
	_tmp18_ = g_application_run ((GApplication*) _tmp17_, 0, NULL);
	result = _tmp18_;
	_g_object_unref0 (app);
	_g_option_context_free0 (context);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return preferences_app_main (argv, argc);
}


PreferencesApp* preferences_app_construct (GType object_type) {
	PreferencesApp * self = NULL;
	self = (PreferencesApp*) g_object_new (object_type, NULL);
	return self;
}


PreferencesApp* preferences_app_new (void) {
	return preferences_app_construct (TYPE_PREFERENCES_APP);
}


static void preferences_app_class_init (PreferencesAppClass * klass) {
	preferences_app_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = preferences_app_finalize;
}


static void preferences_app_instance_init (PreferencesApp * self) {
}


static void preferences_app_finalize (GObject* obj) {
	PreferencesApp * self;
	self = PREFERENCES_APP (obj);
	G_OBJECT_CLASS (preferences_app_parent_class)->finalize (obj);
}


GType preferences_app_get_type (void) {
	static volatile gsize preferences_app_type_id__volatile = 0;
	if (g_once_init_enter (&preferences_app_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PreferencesAppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) preferences_app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PreferencesApp), 0, (GInstanceInitFunc) preferences_app_instance_init, NULL };
		GType preferences_app_type_id;
		preferences_app_type_id = g_type_register_static (G_TYPE_OBJECT, "PreferencesApp", &g_define_type_info, 0);
		g_once_init_leave (&preferences_app_type_id__volatile, preferences_app_type_id);
	}
	return preferences_app_type_id__volatile;
}



