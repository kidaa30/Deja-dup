/* BackendRackspace.c generated by valac 0.16.1, the Vala compiler
 * generated from BackendRackspace.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>
#include <gnome-keyring.h>


#define DEJA_DUP_TYPE_BACKEND (deja_dup_backend_get_type ())
#define DEJA_DUP_BACKEND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_BACKEND, DejaDupBackend))
#define DEJA_DUP_BACKEND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_BACKEND, DejaDupBackendClass))
#define DEJA_DUP_IS_BACKEND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_BACKEND))
#define DEJA_DUP_IS_BACKEND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_BACKEND))
#define DEJA_DUP_BACKEND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_BACKEND, DejaDupBackendClass))

typedef struct _DejaDupBackend DejaDupBackend;
typedef struct _DejaDupBackendClass DejaDupBackendClass;
typedef struct _DejaDupBackendPrivate DejaDupBackendPrivate;

#define DEJA_DUP_TOOL_JOB_TYPE_MODE (deja_dup_tool_job_mode_get_type ())

#define DEJA_DUP_TYPE_BACKEND_RACKSPACE (deja_dup_backend_rackspace_get_type ())
#define DEJA_DUP_BACKEND_RACKSPACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_BACKEND_RACKSPACE, DejaDupBackendRackspace))
#define DEJA_DUP_BACKEND_RACKSPACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_BACKEND_RACKSPACE, DejaDupBackendRackspaceClass))
#define DEJA_DUP_IS_BACKEND_RACKSPACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_BACKEND_RACKSPACE))
#define DEJA_DUP_IS_BACKEND_RACKSPACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_BACKEND_RACKSPACE))
#define DEJA_DUP_BACKEND_RACKSPACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_BACKEND_RACKSPACE, DejaDupBackendRackspaceClass))

typedef struct _DejaDupBackendRackspace DejaDupBackendRackspace;
typedef struct _DejaDupBackendRackspaceClass DejaDupBackendRackspaceClass;
typedef struct _DejaDupBackendRackspacePrivate DejaDupBackendRackspacePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define DEJA_DUP_TYPE_CHECKER (deja_dup_checker_get_type ())
#define DEJA_DUP_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CHECKER, DejaDupChecker))
#define DEJA_DUP_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CHECKER, DejaDupCheckerClass))
#define DEJA_DUP_IS_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CHECKER))
#define DEJA_DUP_IS_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CHECKER))
#define DEJA_DUP_CHECKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CHECKER, DejaDupCheckerClass))

typedef struct _DejaDupChecker DejaDupChecker;
typedef struct _DejaDupCheckerClass DejaDupCheckerClass;

#define DEJA_DUP_TYPE_PYTHON_CHECKER (deja_dup_python_checker_get_type ())
#define DEJA_DUP_PYTHON_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_PYTHON_CHECKER, DejaDupPythonChecker))
#define DEJA_DUP_PYTHON_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_PYTHON_CHECKER, DejaDupPythonCheckerClass))
#define DEJA_DUP_IS_PYTHON_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_PYTHON_CHECKER))
#define DEJA_DUP_IS_PYTHON_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_PYTHON_CHECKER))
#define DEJA_DUP_PYTHON_CHECKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_PYTHON_CHECKER, DejaDupPythonCheckerClass))

typedef struct _DejaDupPythonChecker DejaDupPythonChecker;
typedef struct _DejaDupPythonCheckerClass DejaDupPythonCheckerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define DEJA_DUP_TYPE_NETWORK (deja_dup_network_get_type ())
#define DEJA_DUP_NETWORK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_NETWORK, DejaDupNetwork))
#define DEJA_DUP_NETWORK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_NETWORK, DejaDupNetworkClass))
#define DEJA_DUP_IS_NETWORK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_NETWORK))
#define DEJA_DUP_IS_NETWORK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_NETWORK))
#define DEJA_DUP_NETWORK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_NETWORK, DejaDupNetworkClass))

typedef struct _DejaDupNetwork DejaDupNetwork;
typedef struct _DejaDupNetworkClass DejaDupNetworkClass;
typedef struct _DejaDupBackendRackspaceIsReadyData DejaDupBackendRackspaceIsReadyData;

#define DEJA_DUP_TYPE_SIMPLE_SETTINGS (deja_dup_simple_settings_get_type ())
#define DEJA_DUP_SIMPLE_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettings))
#define DEJA_DUP_SIMPLE_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettingsClass))
#define DEJA_DUP_IS_SIMPLE_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS))
#define DEJA_DUP_IS_SIMPLE_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_SIMPLE_SETTINGS))
#define DEJA_DUP_SIMPLE_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettingsClass))

typedef struct _DejaDupSimpleSettings DejaDupSimpleSettings;
typedef struct _DejaDupSimpleSettingsClass DejaDupSimpleSettingsClass;
typedef struct _DejaDupBackendRackspaceGetEnvpData DejaDupBackendRackspaceGetEnvpData;
#define __g_list_free__g_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_free0_ (var), NULL)))

typedef enum  {
	DEJA_DUP_TOOL_JOB_MODE_INVALID,
	DEJA_DUP_TOOL_JOB_MODE_BACKUP,
	DEJA_DUP_TOOL_JOB_MODE_RESTORE,
	DEJA_DUP_TOOL_JOB_MODE_STATUS,
	DEJA_DUP_TOOL_JOB_MODE_LIST,
	DEJA_DUP_TOOL_JOB_MODE_HISTORY
} DejaDupToolJobMode;

struct _DejaDupBackend {
	GObject parent_instance;
	DejaDupBackendPrivate * priv;
};

struct _DejaDupBackendClass {
	GObjectClass parent_class;
	gboolean (*is_native) (DejaDupBackend* self);
	GIcon* (*get_icon) (DejaDupBackend* self);
	gchar* (*get_location) (DejaDupBackend* self, gboolean* as_root);
	gchar* (*get_location_pretty) (DejaDupBackend* self);
	void (*is_ready) (DejaDupBackend* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*is_ready_finish) (DejaDupBackend* self, GAsyncResult* _res_, gchar** when);
	void (*get_envp) (DejaDupBackend* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*get_envp_finish) (DejaDupBackend* self, GAsyncResult* _res_, GError** error);
	void (*get_space) (DejaDupBackend* self, gboolean free, GAsyncReadyCallback _callback_, gpointer _user_data_);
	guint64 (*get_space_finish) (DejaDupBackend* self, GAsyncResult* _res_);
	gboolean (*space_can_be_infinite) (DejaDupBackend* self);
	void (*add_argv) (DejaDupBackend* self, DejaDupToolJobMode mode, GList** argv);
	DejaDupBackend* (*clone) (DejaDupBackend* self);
};

struct _DejaDupBackendRackspace {
	DejaDupBackend parent_instance;
	DejaDupBackendRackspacePrivate * priv;
};

struct _DejaDupBackendRackspaceClass {
	DejaDupBackendClass parent_class;
};

struct _DejaDupBackendRackspacePrivate {
	gchar* settings_id;
	gchar* id;
	gchar* secret_key;
};

struct _DejaDupBackendRackspaceIsReadyData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupBackendRackspace* self;
	gchar* when;
	gboolean result;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	DejaDupNetwork* _tmp2_;
	DejaDupNetwork* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gboolean _tmp6_;
	gboolean _tmp7_;
};

struct _DejaDupBackendRackspaceGetEnvpData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupBackendRackspace* self;
	DejaDupSimpleSettings* _tmp0_;
	DejaDupSimpleSettings* settings;
	DejaDupSimpleSettings* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	gboolean _tmp8_;
	const gchar* _tmp9_;
	const gchar* _tmp10_;
	gboolean _tmp11_;
	const gchar* _tmp12_;
	const gchar* _tmp13_;
};


static gpointer deja_dup_backend_rackspace_parent_class = NULL;

#define DEJA_DUP_RACKSPACE_ROOT "Rackspace"
#define DEJA_DUP_RACKSPACE_USERNAME_KEY "username"
#define DEJA_DUP_RACKSPACE_CONTAINER_KEY "container"
#define DEJA_DUP_RACKSPACE_SERVER "auth.api.rackspacecloud.com"
GType deja_dup_backend_get_type (void) G_GNUC_CONST;
GType deja_dup_tool_job_mode_get_type (void) G_GNUC_CONST;
GType deja_dup_backend_rackspace_get_type (void) G_GNUC_CONST;
#define DEJA_DUP_BACKEND_RACKSPACE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), DEJA_DUP_TYPE_BACKEND_RACKSPACE, DejaDupBackendRackspacePrivate))
enum  {
	DEJA_DUP_BACKEND_RACKSPACE_DUMMY_PROPERTY
};
GType deja_dup_checker_get_type (void) G_GNUC_CONST;
DejaDupChecker* deja_dup_backend_rackspace_get_checker (void);
GType deja_dup_python_checker_get_type (void) G_GNUC_CONST;
DejaDupPythonChecker* deja_dup_python_checker_get_checker (const gchar* module);
static DejaDupBackend* deja_dup_backend_rackspace_real_clone (DejaDupBackend* base);
DejaDupBackendRackspace* deja_dup_backend_rackspace_new (void);
DejaDupBackendRackspace* deja_dup_backend_rackspace_construct (GType object_type);
static gboolean deja_dup_backend_rackspace_real_is_native (DejaDupBackend* base);
static GIcon* deja_dup_backend_rackspace_real_get_icon (DejaDupBackend* base);
static void deja_dup_backend_rackspace_real_is_ready_data_free (gpointer _data);
static void deja_dup_backend_rackspace_real_is_ready (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_backend_rackspace_real_is_ready_co (DejaDupBackendRackspaceIsReadyData* _data_);
GType deja_dup_network_get_type (void) G_GNUC_CONST;
DejaDupNetwork* deja_dup_network_get (void);
void deja_dup_network_can_reach (DejaDupNetwork* self, const gchar* url, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean deja_dup_network_can_reach_finish (DejaDupNetwork* self, GAsyncResult* _res_);
static void deja_dup_backend_rackspace_is_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gchar* deja_dup_backend_rackspace_real_get_location (DejaDupBackend* base, gboolean* as_root);
GType deja_dup_simple_settings_get_type (void) G_GNUC_CONST;
DejaDupSimpleSettings* deja_dup_get_settings (const gchar* subdir);
gchar* deja_dup_get_folder_key (DejaDupSimpleSettings* settings, const gchar* key);
void deja_dup_simple_settings_set_string (DejaDupSimpleSettings* self, const gchar* k, const gchar* v);
static gchar* deja_dup_backend_rackspace_real_get_location_pretty (DejaDupBackend* base);
static void deja_dup_backend_rackspace_real_get_envp_data_free (gpointer _data);
static void deja_dup_backend_rackspace_real_get_envp (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_backend_rackspace_real_get_envp_co (DejaDupBackendRackspaceGetEnvpData* _data_);
static void deja_dup_backend_rackspace_got_secret_key (DejaDupBackendRackspace* self);
static void deja_dup_backend_rackspace_found_password (DejaDupBackendRackspace* self, GnomeKeyringResult _result_, GList* list);
static void _deja_dup_backend_rackspace_found_password_gnome_keyring_operation_get_list_callback (GnomeKeyringResult _result_, GList* list, gpointer self);
static void deja_dup_backend_rackspace_ask_password (DejaDupBackendRackspace* self);
static void deja_dup_backend_rackspace_save_password_callback (DejaDupBackendRackspace* self, GnomeKeyringResult _result_, guint32 val);
static void deja_dup_backend_rackspace_got_password_reply (DejaDupBackendRackspace* self, GMountOperation* mount_op, GMountOperationResult _result_);
static void _g_free0_ (gpointer var);
static void _g_list_free__g_free0_ (GList* self);
static void _deja_dup_backend_rackspace_save_password_callback_gnome_keyring_operation_get_int_callback (GnomeKeyringResult _result_, guint32 val, gpointer self);
GMountOperation* deja_dup_backend_get_mount_op (DejaDupBackend* self);
static void _deja_dup_backend_rackspace_got_password_reply_g_mount_operation_reply (GMountOperation* _sender, GMountOperationResult _result_, gpointer self);
DejaDupBackend* deja_dup_backend_construct (GType object_type);
static void deja_dup_backend_rackspace_finalize (GObject* obj);


DejaDupChecker* deja_dup_backend_rackspace_get_checker (void) {
	DejaDupChecker* result = NULL;
	DejaDupPythonChecker* _tmp0_ = NULL;
	_tmp0_ = deja_dup_python_checker_get_checker ("cloudfiles");
	result = (DejaDupChecker*) _tmp0_;
	return result;
}


static DejaDupBackend* deja_dup_backend_rackspace_real_clone (DejaDupBackend* base) {
	DejaDupBackendRackspace * self;
	DejaDupBackend* result = NULL;
	DejaDupBackendRackspace* _tmp0_;
	self = (DejaDupBackendRackspace*) base;
	_tmp0_ = deja_dup_backend_rackspace_new ();
	result = (DejaDupBackend*) _tmp0_;
	return result;
}


static gboolean deja_dup_backend_rackspace_real_is_native (DejaDupBackend* base) {
	DejaDupBackendRackspace * self;
	gboolean result = FALSE;
	self = (DejaDupBackendRackspace*) base;
	result = FALSE;
	return result;
}


static GIcon* deja_dup_backend_rackspace_real_get_icon (DejaDupBackend* base) {
	DejaDupBackendRackspace * self;
	GIcon* result = NULL;
	GThemedIcon* _tmp0_;
	self = (DejaDupBackendRackspace*) base;
	_tmp0_ = (GThemedIcon*) g_themed_icon_new ("deja-dup-cloud");
	result = (GIcon*) _tmp0_;
	return result;
}


static void deja_dup_backend_rackspace_real_is_ready_data_free (gpointer _data) {
	DejaDupBackendRackspaceIsReadyData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupBackendRackspaceIsReadyData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void deja_dup_backend_rackspace_real_is_ready (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupBackendRackspace * self;
	DejaDupBackendRackspaceIsReadyData* _data_;
	DejaDupBackendRackspace* _tmp0_;
	self = (DejaDupBackendRackspace*) base;
	_data_ = g_slice_new0 (DejaDupBackendRackspaceIsReadyData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_backend_rackspace_real_is_ready);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_backend_rackspace_real_is_ready_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_backend_rackspace_real_is_ready_co (_data_);
}


static gboolean deja_dup_backend_rackspace_real_is_ready_finish (DejaDupBackend* base, GAsyncResult* _res_, gchar** when) {
	gboolean result;
	DejaDupBackendRackspaceIsReadyData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	if (when) {
		*when = _data_->when;
	} else {
		_g_free0 (_data_->when);
	}
	_data_->when = NULL;
	result = _data_->result;
	return result;
}


static void deja_dup_backend_rackspace_is_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	DejaDupBackendRackspaceIsReadyData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	deja_dup_backend_rackspace_real_is_ready_co (_data_);
}


static gboolean deja_dup_backend_rackspace_real_is_ready_co (DejaDupBackendRackspaceIsReadyData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = _ ("Backup will begin when a network connection becomes available.");
	_data_->_tmp1_ = g_strdup (_data_->_tmp0_);
	_g_free0 (_data_->when);
	_data_->when = _data_->_tmp1_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = deja_dup_network_get ();
	_data_->_tmp3_ = _data_->_tmp2_;
	_data_->_tmp4_ = NULL;
	_data_->_tmp4_ = g_strdup_printf ("http://%s/", DEJA_DUP_RACKSPACE_SERVER);
	_data_->_tmp5_ = _data_->_tmp4_;
	_data_->_state_ = 1;
	deja_dup_network_can_reach (_data_->_tmp3_, _data_->_tmp5_, deja_dup_backend_rackspace_is_ready_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp6_ = FALSE;
	_data_->_tmp6_ = deja_dup_network_can_reach_finish (_data_->_tmp3_, _data_->_res_);
	_data_->_tmp7_ = _data_->_tmp6_;
	_g_free0 (_data_->_tmp5_);
	_g_object_unref0 (_data_->_tmp3_);
	_data_->result = _data_->_tmp7_;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static gchar* deja_dup_backend_rackspace_real_get_location (DejaDupBackend* base, gboolean* as_root) {
	DejaDupBackendRackspace * self;
	gchar* result = NULL;
	DejaDupSimpleSettings* _tmp0_ = NULL;
	DejaDupSimpleSettings* settings;
	DejaDupSimpleSettings* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* container;
	const gchar* _tmp3_;
	const gchar* _tmp8_;
	gchar* _tmp9_ = NULL;
	self = (DejaDupBackendRackspace*) base;
	_tmp0_ = deja_dup_get_settings (DEJA_DUP_RACKSPACE_ROOT);
	settings = _tmp0_;
	_tmp1_ = settings;
	_tmp2_ = deja_dup_get_folder_key (_tmp1_, DEJA_DUP_RACKSPACE_CONTAINER_KEY);
	container = _tmp2_;
	_tmp3_ = container;
	if (g_strcmp0 (_tmp3_, "") == 0) {
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		DejaDupSimpleSettings* _tmp6_;
		const gchar* _tmp7_;
		_tmp4_ = g_get_host_name ();
		_tmp5_ = g_strdup (_tmp4_);
		_g_free0 (container);
		container = _tmp5_;
		_tmp6_ = settings;
		_tmp7_ = container;
		deja_dup_simple_settings_set_string (_tmp6_, DEJA_DUP_RACKSPACE_CONTAINER_KEY, _tmp7_);
	}
	_tmp8_ = container;
	_tmp9_ = g_strdup_printf ("cf+http://%s", _tmp8_);
	result = _tmp9_;
	_g_free0 (container);
	_g_object_unref0 (settings);
	return result;
}


static gchar* deja_dup_backend_rackspace_real_get_location_pretty (DejaDupBackend* base) {
	DejaDupBackendRackspace * self;
	gchar* result = NULL;
	DejaDupSimpleSettings* _tmp0_ = NULL;
	DejaDupSimpleSettings* settings;
	DejaDupSimpleSettings* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* container;
	const gchar* _tmp3_;
	self = (DejaDupBackendRackspace*) base;
	_tmp0_ = deja_dup_get_settings (DEJA_DUP_RACKSPACE_ROOT);
	settings = _tmp0_;
	_tmp1_ = settings;
	_tmp2_ = g_settings_get_string ((GSettings*) _tmp1_, DEJA_DUP_RACKSPACE_CONTAINER_KEY);
	container = _tmp2_;
	_tmp3_ = container;
	if (g_strcmp0 (_tmp3_, "") == 0) {
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		_tmp4_ = _ ("Rackspace Cloud Files");
		_tmp5_ = g_strdup (_tmp4_);
		result = _tmp5_;
		_g_free0 (container);
		_g_object_unref0 (settings);
		return result;
	} else {
		const gchar* _tmp6_ = NULL;
		const gchar* _tmp7_;
		gchar* _tmp8_ = NULL;
		_tmp6_ = _ ("%s on Rackspace Cloud Files");
		_tmp7_ = container;
		_tmp8_ = g_strdup_printf (_tmp6_, _tmp7_);
		result = _tmp8_;
		_g_free0 (container);
		_g_object_unref0 (settings);
		return result;
	}
	_g_free0 (container);
	_g_object_unref0 (settings);
}


static void deja_dup_backend_rackspace_real_get_envp_data_free (gpointer _data) {
	DejaDupBackendRackspaceGetEnvpData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupBackendRackspaceGetEnvpData, _data_);
}


static void deja_dup_backend_rackspace_real_get_envp (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupBackendRackspace * self;
	DejaDupBackendRackspaceGetEnvpData* _data_;
	DejaDupBackendRackspace* _tmp0_;
	self = (DejaDupBackendRackspace*) base;
	_data_ = g_slice_new0 (DejaDupBackendRackspaceGetEnvpData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_backend_rackspace_real_get_envp);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_backend_rackspace_real_get_envp_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_backend_rackspace_real_get_envp_co (_data_);
}


static void deja_dup_backend_rackspace_real_get_envp_finish (DejaDupBackend* base, GAsyncResult* _res_, GError** error) {
	DejaDupBackendRackspaceGetEnvpData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void _deja_dup_backend_rackspace_found_password_gnome_keyring_operation_get_list_callback (GnomeKeyringResult _result_, GList* list, gpointer self) {
	deja_dup_backend_rackspace_found_password (self, _result_, list);
}


static gboolean deja_dup_backend_rackspace_real_get_envp_co (DejaDupBackendRackspaceGetEnvpData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = deja_dup_get_settings (DEJA_DUP_RACKSPACE_ROOT);
	_data_->settings = _data_->_tmp0_;
	_data_->_tmp1_ = _data_->settings;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = g_settings_get_string ((GSettings*) _data_->_tmp1_, DEJA_DUP_RACKSPACE_USERNAME_KEY);
	_g_free0 (_data_->self->priv->settings_id);
	_data_->self->priv->settings_id = _data_->_tmp2_;
	_data_->_tmp4_ = _data_->self->priv->settings_id;
	if (_data_->_tmp4_ == NULL) {
		_data_->_tmp3_ = "";
	} else {
		_data_->_tmp5_ = _data_->self->priv->settings_id;
		_data_->_tmp3_ = _data_->_tmp5_;
	}
	_data_->_tmp6_ = _data_->_tmp3_;
	_data_->_tmp7_ = g_strdup (_data_->_tmp6_);
	_g_free0 (_data_->self->priv->id);
	_data_->self->priv->id = _data_->_tmp7_;
	_data_->_tmp9_ = _data_->self->priv->id;
	if (g_strcmp0 (_data_->_tmp9_, "") != 0) {
		_data_->_tmp10_ = _data_->self->priv->secret_key;
		_data_->_tmp8_ = _data_->_tmp10_ != NULL;
	} else {
		_data_->_tmp8_ = FALSE;
	}
	_data_->_tmp11_ = _data_->_tmp8_;
	if (_data_->_tmp11_) {
		deja_dup_backend_rackspace_got_secret_key (_data_->self);
		_g_object_unref0 (_data_->settings);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp12_ = _data_->self->priv->id;
	if (g_strcmp0 (_data_->_tmp12_, "") != 0) {
		_g_free0 (_data_->self->priv->secret_key);
		_data_->self->priv->secret_key = NULL;
		_data_->_tmp13_ = _data_->self->priv->id;
		gnome_keyring_find_network_password (_data_->_tmp13_, NULL, DEJA_DUP_RACKSPACE_SERVER, NULL, "https", NULL, (guint32) 0, _deja_dup_backend_rackspace_found_password_gnome_keyring_operation_get_list_callback, g_object_ref (_data_->self), g_object_unref);
	} else {
		deja_dup_backend_rackspace_ask_password (_data_->self);
	}
	_g_object_unref0 (_data_->settings);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void deja_dup_backend_rackspace_found_password (DejaDupBackendRackspace* self, GnomeKeyringResult _result_, GList* list) {
	gboolean _tmp0_ = FALSE;
	GnomeKeyringResult _tmp1_;
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp1_ = _result_;
	if (_tmp1_ == GNOME_KEYRING_RESULT_OK) {
		GList* _tmp2_;
		_tmp2_ = list;
		_tmp0_ = _tmp2_ != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		GList* _tmp4_;
		gconstpointer _tmp5_;
		const gchar* _tmp6_;
		gchar* _tmp7_;
		_tmp4_ = list;
		_tmp5_ = _tmp4_->data;
		_tmp6_ = ((GnomeKeyringNetworkPasswordData*) _tmp5_)->password;
		_tmp7_ = g_strdup (_tmp6_);
		_g_free0 (self->priv->secret_key);
		self->priv->secret_key = _tmp7_;
		deja_dup_backend_rackspace_got_secret_key (self);
	} else {
		deja_dup_backend_rackspace_ask_password (self);
	}
}


static void deja_dup_backend_rackspace_save_password_callback (DejaDupBackendRackspace* self, GnomeKeyringResult _result_, guint32 val) {
	g_return_if_fail (self != NULL);
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_list_free__g_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_free0_, NULL);
	g_list_free (self);
}


static void _deja_dup_backend_rackspace_save_password_callback_gnome_keyring_operation_get_int_callback (GnomeKeyringResult _result_, guint32 val, gpointer self) {
	deja_dup_backend_rackspace_save_password_callback (self, _result_, val);
}


static void deja_dup_backend_rackspace_got_password_reply (DejaDupBackendRackspace* self, GMountOperation* mount_op, GMountOperationResult _result_) {
	GMountOperationResult _tmp0_;
	GMountOperation* _tmp3_;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	GMountOperation* _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	GMountOperation* _tmp11_;
	GPasswordSave _tmp12_;
	GPasswordSave _tmp13_;
	GPasswordSave remember;
	GPasswordSave _tmp14_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (mount_op != NULL);
	_tmp0_ = _result_;
	if (_tmp0_ != G_MOUNT_OPERATION_HANDLED) {
		GList* _tmp1_;
		const gchar* _tmp2_ = NULL;
		_tmp1_ = NULL;
		_tmp2_ = _ ("Permission denied");
		g_signal_emit_by_name ((DejaDupBackend*) self, "envp-ready", FALSE, _tmp1_, _tmp2_);
		__g_list_free__g_free0_0 (_tmp1_);
		return;
	}
	_tmp3_ = mount_op;
	_tmp4_ = g_mount_operation_get_username (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 (self->priv->id);
	self->priv->id = _tmp6_;
	_tmp7_ = mount_op;
	_tmp8_ = g_mount_operation_get_password (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strdup (_tmp9_);
	_g_free0 (self->priv->secret_key);
	self->priv->secret_key = _tmp10_;
	_tmp11_ = mount_op;
	_tmp12_ = g_mount_operation_get_password_save (_tmp11_);
	_tmp13_ = _tmp12_;
	remember = _tmp13_;
	_tmp14_ = remember;
	if (_tmp14_ != G_PASSWORD_SAVE_NEVER) {
		const gchar* _tmp15_ = NULL;
		GPasswordSave _tmp16_;
		const gchar* _tmp17_;
		gchar* _tmp18_;
		gchar* where;
		const gchar* _tmp19_;
		const gchar* _tmp20_;
		const gchar* _tmp21_;
		_tmp16_ = remember;
		if (_tmp16_ == G_PASSWORD_SAVE_FOR_SESSION) {
			_tmp15_ = "session";
		} else {
			_tmp15_ = GNOME_KEYRING_DEFAULT;
		}
		_tmp17_ = _tmp15_;
		_tmp18_ = g_strdup (_tmp17_);
		where = _tmp18_;
		_tmp19_ = where;
		_tmp20_ = self->priv->id;
		_tmp21_ = self->priv->secret_key;
		gnome_keyring_set_network_password (_tmp19_, _tmp20_, NULL, DEJA_DUP_RACKSPACE_SERVER, NULL, "https", NULL, (guint32) 0, _tmp21_, _deja_dup_backend_rackspace_save_password_callback_gnome_keyring_operation_get_int_callback, g_object_ref (self), g_object_unref);
		_g_free0 (where);
	}
	deja_dup_backend_rackspace_got_secret_key (self);
}


static void _deja_dup_backend_rackspace_got_password_reply_g_mount_operation_reply (GMountOperation* _sender, GMountOperationResult _result_, gpointer self) {
	deja_dup_backend_rackspace_got_password_reply (self, _sender, _result_);
}


static void deja_dup_backend_rackspace_ask_password (DejaDupBackendRackspace* self) {
	GMountOperation* _tmp0_;
	GMountOperation* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	GMountOperation* _tmp5_;
	GMountOperation* _tmp6_;
	const gchar* _tmp7_ = NULL;
	GMountOperation* _tmp8_;
	GMountOperation* _tmp9_;
	const gchar* _tmp10_ = NULL;
	GMountOperation* _tmp11_;
	GMountOperation* _tmp12_;
	const gchar* _tmp13_ = NULL;
	GMountOperation* _tmp14_;
	GMountOperation* _tmp15_;
	const gchar* _tmp16_ = NULL;
	GMountOperation* _tmp17_;
	GMountOperation* _tmp18_;
	GMountOperation* _tmp19_;
	GMountOperation* _tmp20_;
	const gchar* _tmp21_;
	g_return_if_fail (self != NULL);
	_tmp0_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _ ("You can sign up for a Rackspace Cloud Files account <a href=\"%s\">onl" \
"ine</a>.");
	_tmp3_ = g_strdup_printf (_tmp2_, "https://signup.rackspacecloud.com/signup");
	_tmp4_ = _tmp3_;
	g_object_set ((GObject*) _tmp1_, "label_help", _tmp4_, NULL);
	_g_free0 (_tmp4_);
	_tmp5_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp6_ = _tmp5_;
	_tmp7_ = _ ("Connect to Rackspace Cloud Files");
	g_object_set ((GObject*) _tmp6_, "label_title", _tmp7_, NULL);
	_tmp8_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp9_ = _tmp8_;
	_tmp10_ = _ ("_API access key");
	g_object_set ((GObject*) _tmp9_, "label_password", _tmp10_, NULL);
	_tmp11_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp12_ = _tmp11_;
	_tmp13_ = _ ("S_how API access key");
	g_object_set ((GObject*) _tmp12_, "label_show_password", _tmp13_, NULL);
	_tmp14_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp15_ = _tmp14_;
	_tmp16_ = _ ("_Remember API access key");
	g_object_set ((GObject*) _tmp15_, "label_remember_password", _tmp16_, NULL);
	_tmp17_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp18_ = _tmp17_;
	g_signal_connect_object (_tmp18_, "reply", (GCallback) _deja_dup_backend_rackspace_got_password_reply_g_mount_operation_reply, self, 0);
	_tmp19_ = deja_dup_backend_get_mount_op ((DejaDupBackend*) self);
	_tmp20_ = _tmp19_;
	_tmp21_ = self->priv->id;
	g_signal_emit_by_name (_tmp20_, "ask-password", "", _tmp21_, "", (G_ASK_PASSWORD_NEED_PASSWORD | G_ASK_PASSWORD_NEED_USERNAME) | G_ASK_PASSWORD_SAVING_SUPPORTED);
}


static void deja_dup_backend_rackspace_got_secret_key (DejaDupBackendRackspace* self) {
	DejaDupSimpleSettings* _tmp0_ = NULL;
	DejaDupSimpleSettings* settings;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GList* envp;
	const gchar* _tmp5_;
	gchar* _tmp6_ = NULL;
	const gchar* _tmp7_;
	gchar* _tmp8_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = deja_dup_get_settings (DEJA_DUP_RACKSPACE_ROOT);
	settings = _tmp0_;
	_tmp1_ = self->priv->id;
	_tmp2_ = self->priv->settings_id;
	if (g_strcmp0 (_tmp1_, _tmp2_) != 0) {
		DejaDupSimpleSettings* _tmp3_;
		const gchar* _tmp4_;
		_tmp3_ = settings;
		_tmp4_ = self->priv->id;
		deja_dup_simple_settings_set_string (_tmp3_, DEJA_DUP_RACKSPACE_USERNAME_KEY, _tmp4_);
	}
	envp = NULL;
	_tmp5_ = self->priv->id;
	_tmp6_ = g_strdup_printf ("CLOUDFILES_USERNAME=%s", _tmp5_);
	envp = g_list_append (envp, _tmp6_);
	_tmp7_ = self->priv->secret_key;
	_tmp8_ = g_strdup_printf ("CLOUDFILES_APIKEY=%s", _tmp7_);
	envp = g_list_append (envp, _tmp8_);
	g_signal_emit_by_name ((DejaDupBackend*) self, "envp-ready", TRUE, envp, NULL);
	__g_list_free__g_free0_0 (envp);
	_g_object_unref0 (settings);
}


DejaDupBackendRackspace* deja_dup_backend_rackspace_construct (GType object_type) {
	DejaDupBackendRackspace * self = NULL;
	self = (DejaDupBackendRackspace*) deja_dup_backend_construct (object_type);
	return self;
}


DejaDupBackendRackspace* deja_dup_backend_rackspace_new (void) {
	return deja_dup_backend_rackspace_construct (DEJA_DUP_TYPE_BACKEND_RACKSPACE);
}


static void deja_dup_backend_rackspace_class_init (DejaDupBackendRackspaceClass * klass) {
	deja_dup_backend_rackspace_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DejaDupBackendRackspacePrivate));
	DEJA_DUP_BACKEND_CLASS (klass)->clone = deja_dup_backend_rackspace_real_clone;
	DEJA_DUP_BACKEND_CLASS (klass)->is_native = deja_dup_backend_rackspace_real_is_native;
	DEJA_DUP_BACKEND_CLASS (klass)->get_icon = deja_dup_backend_rackspace_real_get_icon;
	DEJA_DUP_BACKEND_CLASS (klass)->is_ready = deja_dup_backend_rackspace_real_is_ready;
	DEJA_DUP_BACKEND_CLASS (klass)->is_ready_finish = deja_dup_backend_rackspace_real_is_ready_finish;
	DEJA_DUP_BACKEND_CLASS (klass)->get_location = deja_dup_backend_rackspace_real_get_location;
	DEJA_DUP_BACKEND_CLASS (klass)->get_location_pretty = deja_dup_backend_rackspace_real_get_location_pretty;
	DEJA_DUP_BACKEND_CLASS (klass)->get_envp = deja_dup_backend_rackspace_real_get_envp;
	DEJA_DUP_BACKEND_CLASS (klass)->get_envp_finish = deja_dup_backend_rackspace_real_get_envp_finish;
	G_OBJECT_CLASS (klass)->finalize = deja_dup_backend_rackspace_finalize;
}


static void deja_dup_backend_rackspace_instance_init (DejaDupBackendRackspace * self) {
	self->priv = DEJA_DUP_BACKEND_RACKSPACE_GET_PRIVATE (self);
}


static void deja_dup_backend_rackspace_finalize (GObject* obj) {
	DejaDupBackendRackspace * self;
	self = DEJA_DUP_BACKEND_RACKSPACE (obj);
	_g_free0 (self->priv->settings_id);
	_g_free0 (self->priv->id);
	_g_free0 (self->priv->secret_key);
	G_OBJECT_CLASS (deja_dup_backend_rackspace_parent_class)->finalize (obj);
}


GType deja_dup_backend_rackspace_get_type (void) {
	static volatile gsize deja_dup_backend_rackspace_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_backend_rackspace_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupBackendRackspaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_backend_rackspace_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupBackendRackspace), 0, (GInstanceInitFunc) deja_dup_backend_rackspace_instance_init, NULL };
		GType deja_dup_backend_rackspace_type_id;
		deja_dup_backend_rackspace_type_id = g_type_register_static (DEJA_DUP_TYPE_BACKEND, "DejaDupBackendRackspace", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_backend_rackspace_type_id__volatile, deja_dup_backend_rackspace_type_id);
	}
	return deja_dup_backend_rackspace_type_id__volatile;
}



