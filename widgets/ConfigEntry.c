/* ConfigEntry.c generated by valac 0.16.1, the Vala compiler
 * generated from ConfigEntry.vala, do not modify */

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
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <common.h>
#include <stdlib.h>
#include <string.h>
#include <atk/atk.h>
#include <gdk/gdk.h>


#define DEJA_DUP_TYPE_CONFIG_WIDGET (deja_dup_config_widget_get_type ())
#define DEJA_DUP_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidget))
#define DEJA_DUP_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))
#define DEJA_DUP_IS_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_IS_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_CONFIG_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))

typedef struct _DejaDupConfigWidget DejaDupConfigWidget;
typedef struct _DejaDupConfigWidgetClass DejaDupConfigWidgetClass;
typedef struct _DejaDupConfigWidgetPrivate DejaDupConfigWidgetPrivate;

#define DEJA_DUP_TYPE_CONFIG_ENTRY (deja_dup_config_entry_get_type ())
#define DEJA_DUP_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntry))
#define DEJA_DUP_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))
#define DEJA_DUP_IS_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_IS_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_CONFIG_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))

typedef struct _DejaDupConfigEntry DejaDupConfigEntry;
typedef struct _DejaDupConfigEntryClass DejaDupConfigEntryClass;
typedef struct _DejaDupConfigEntryPrivate DejaDupConfigEntryPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DejaDupConfigEntrySetFromConfigData DejaDupConfigEntrySetFromConfigData;

struct _DejaDupConfigWidget {
	GtkEventBox parent_instance;
	DejaDupConfigWidgetPrivate * priv;
	gboolean syncing;
	DejaDupSimpleSettings* settings;
	GList* all_settings;
};

struct _DejaDupConfigWidgetClass {
	GtkEventBoxClass parent_class;
	void (*set_from_config) (DejaDupConfigWidget* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*set_from_config_finish) (DejaDupConfigWidget* self, GAsyncResult* _res_);
};

struct _DejaDupConfigEntry {
	DejaDupConfigWidget parent_instance;
	DejaDupConfigEntryPrivate * priv;
	GtkEntry* entry;
};

struct _DejaDupConfigEntryClass {
	DejaDupConfigWidgetClass parent_class;
	void (*write_to_config) (DejaDupConfigEntry* self);
};

struct _DejaDupConfigEntrySetFromConfigData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupConfigEntry* self;
	DejaDupSimpleSettings* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* val;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	GtkEntry* _tmp6_;
	const gchar* _tmp7_;
};


static gpointer deja_dup_config_entry_parent_class = NULL;

GType deja_dup_config_widget_get_type (void) G_GNUC_CONST;
GType deja_dup_config_entry_get_type (void) G_GNUC_CONST;
enum  {
	DEJA_DUP_CONFIG_ENTRY_DUMMY_PROPERTY
};
DejaDupConfigEntry* deja_dup_config_entry_new (const gchar* key, const gchar* ns);
DejaDupConfigEntry* deja_dup_config_entry_construct (GType object_type, const gchar* key, const gchar* ns);
gchar* deja_dup_config_entry_get_text (DejaDupConfigEntry* self);
void deja_dup_config_entry_set_accessible_name (DejaDupConfigEntry* self, const gchar* name);
static void deja_dup_config_entry_real_set_from_config_data_free (gpointer _data);
static void deja_dup_config_entry_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_config_entry_real_set_from_config_co (DejaDupConfigEntrySetFromConfigData* _data_);
const gchar* deja_dup_config_widget_get_key (DejaDupConfigWidget* self);
void deja_dup_config_entry_write_to_config (DejaDupConfigEntry* self);
static void deja_dup_config_entry_real_write_to_config (DejaDupConfigEntry* self);
static gboolean deja_dup_config_entry_handle_focus_out (DejaDupConfigEntry* self);
static GObject * deja_dup_config_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
void deja_dup_config_widget_set_mnemonic_widget (DejaDupConfigWidget* self, GtkWidget* value);
void deja_dup_config_widget_set_from_config (DejaDupConfigWidget* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void deja_dup_config_widget_set_from_config_finish (DejaDupConfigWidget* self, GAsyncResult* _res_);
static gboolean _deja_dup_config_entry_handle_focus_out_gtk_widget_focus_out_event (GtkWidget* _sender, GdkEventFocus* event, gpointer self);
static void deja_dup_config_entry_finalize (GObject* obj);


DejaDupConfigEntry* deja_dup_config_entry_construct (GType object_type, const gchar* key, const gchar* ns) {
	DejaDupConfigEntry * self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (key != NULL, NULL);
	g_return_val_if_fail (ns != NULL, NULL);
	_tmp0_ = key;
	_tmp1_ = ns;
	self = (DejaDupConfigEntry*) g_object_new (object_type, "key", _tmp0_, "ns", _tmp1_, NULL);
	return self;
}


DejaDupConfigEntry* deja_dup_config_entry_new (const gchar* key, const gchar* ns) {
	return deja_dup_config_entry_construct (DEJA_DUP_TYPE_CONFIG_ENTRY, key, ns);
}


gchar* deja_dup_config_entry_get_text (DejaDupConfigEntry* self) {
	gchar* result = NULL;
	GtkEntry* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->entry;
	_tmp1_ = gtk_entry_get_text (_tmp0_);
	_tmp2_ = g_strdup (_tmp1_);
	result = _tmp2_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void deja_dup_config_entry_set_accessible_name (DejaDupConfigEntry* self, const gchar* name) {
	GtkEntry* _tmp0_;
	AtkObject* _tmp1_ = NULL;
	AtkObject* _tmp2_;
	AtkObject* accessible;
	AtkObject* _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = self->entry;
	_tmp1_ = gtk_widget_get_accessible ((GtkWidget*) _tmp0_);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	accessible = _tmp2_;
	_tmp3_ = accessible;
	if (_tmp3_ != NULL) {
		AtkObject* _tmp4_;
		const gchar* _tmp5_;
		_tmp4_ = accessible;
		_tmp5_ = name;
		atk_object_set_name (_tmp4_, _tmp5_);
	}
	_g_object_unref0 (accessible);
}


static void deja_dup_config_entry_real_set_from_config_data_free (gpointer _data) {
	DejaDupConfigEntrySetFromConfigData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupConfigEntrySetFromConfigData, _data_);
}


static void deja_dup_config_entry_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupConfigEntry * self;
	DejaDupConfigEntrySetFromConfigData* _data_;
	DejaDupConfigEntry* _tmp0_;
	self = (DejaDupConfigEntry*) base;
	_data_ = g_slice_new0 (DejaDupConfigEntrySetFromConfigData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_config_entry_real_set_from_config);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_config_entry_real_set_from_config_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_config_entry_real_set_from_config_co (_data_);
}


static void deja_dup_config_entry_real_set_from_config_finish (DejaDupConfigWidget* base, GAsyncResult* _res_) {
	DejaDupConfigEntrySetFromConfigData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean deja_dup_config_entry_real_set_from_config_co (DejaDupConfigEntrySetFromConfigData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = ((DejaDupConfigWidget*) _data_->self)->settings;
	_data_->_tmp1_ = deja_dup_config_widget_get_key ((DejaDupConfigWidget*) _data_->self);
	_data_->_tmp2_ = _data_->_tmp1_;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = g_settings_get_string ((GSettings*) _data_->_tmp0_, _data_->_tmp2_);
	_data_->val = _data_->_tmp3_;
	_data_->_tmp4_ = _data_->val;
	if (_data_->_tmp4_ == NULL) {
		_data_->_tmp5_ = g_strdup ("");
		_g_free0 (_data_->val);
		_data_->val = _data_->_tmp5_;
	}
	_data_->_tmp6_ = _data_->self->entry;
	_data_->_tmp7_ = _data_->val;
	gtk_entry_set_text (_data_->_tmp6_, _data_->_tmp7_);
	_g_free0 (_data_->val);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void deja_dup_config_entry_real_write_to_config (DejaDupConfigEntry* self) {
	DejaDupSimpleSettings* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GtkEntry* _tmp3_;
	const gchar* _tmp4_ = NULL;
	_tmp0_ = ((DejaDupConfigWidget*) self)->settings;
	_tmp1_ = deja_dup_config_widget_get_key ((DejaDupConfigWidget*) self);
	_tmp2_ = _tmp1_;
	_tmp3_ = self->entry;
	_tmp4_ = gtk_entry_get_text (_tmp3_);
	deja_dup_simple_settings_set_string (_tmp0_, _tmp2_, _tmp4_);
}


void deja_dup_config_entry_write_to_config (DejaDupConfigEntry* self) {
	g_return_if_fail (self != NULL);
	DEJA_DUP_CONFIG_ENTRY_GET_CLASS (self)->write_to_config (self);
}


static gboolean deja_dup_config_entry_handle_focus_out (DejaDupConfigEntry* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	deja_dup_config_entry_write_to_config (self);
	result = FALSE;
	return result;
}


static gboolean _deja_dup_config_entry_handle_focus_out_gtk_widget_focus_out_event (GtkWidget* _sender, GdkEventFocus* event, gpointer self) {
	gboolean result;
	result = deja_dup_config_entry_handle_focus_out (self);
	return result;
}


static GObject * deja_dup_config_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DejaDupConfigEntry * self;
	GtkEntry* _tmp0_;
	GtkEntry* _tmp1_;
	GtkEntry* _tmp2_;
	GtkEntry* _tmp3_;
	GtkEntry* _tmp4_;
	parent_class = G_OBJECT_CLASS (deja_dup_config_entry_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = DEJA_DUP_CONFIG_ENTRY (obj);
	_tmp0_ = (GtkEntry*) gtk_entry_new ();
	_tmp1_ = g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->entry);
	self->entry = _tmp1_;
	_tmp2_ = self->entry;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp2_);
	_tmp3_ = self->entry;
	deja_dup_config_widget_set_mnemonic_widget ((DejaDupConfigWidget*) self, (GtkWidget*) _tmp3_);
	deja_dup_config_widget_set_from_config ((DejaDupConfigWidget*) self, NULL, NULL);
	_tmp4_ = self->entry;
	g_signal_connect_object ((GtkWidget*) _tmp4_, "focus-out-event", (GCallback) _deja_dup_config_entry_handle_focus_out_gtk_widget_focus_out_event, self, 0);
	return obj;
}


static void deja_dup_config_entry_class_init (DejaDupConfigEntryClass * klass) {
	deja_dup_config_entry_parent_class = g_type_class_peek_parent (klass);
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config = deja_dup_config_entry_real_set_from_config;
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config_finish = deja_dup_config_entry_real_set_from_config_finish;
	DEJA_DUP_CONFIG_ENTRY_CLASS (klass)->write_to_config = deja_dup_config_entry_real_write_to_config;
	G_OBJECT_CLASS (klass)->constructor = deja_dup_config_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = deja_dup_config_entry_finalize;
}


static void deja_dup_config_entry_instance_init (DejaDupConfigEntry * self) {
}


static void deja_dup_config_entry_finalize (GObject* obj) {
	DejaDupConfigEntry * self;
	self = DEJA_DUP_CONFIG_ENTRY (obj);
	_g_object_unref0 (self->entry);
	G_OBJECT_CLASS (deja_dup_config_entry_parent_class)->finalize (obj);
}


GType deja_dup_config_entry_get_type (void) {
	static volatile gsize deja_dup_config_entry_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_config_entry_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupConfigEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_config_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupConfigEntry), 0, (GInstanceInitFunc) deja_dup_config_entry_instance_init, NULL };
		GType deja_dup_config_entry_type_id;
		deja_dup_config_entry_type_id = g_type_register_static (DEJA_DUP_TYPE_CONFIG_WIDGET, "DejaDupConfigEntry", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_config_entry_type_id__volatile, deja_dup_config_entry_type_id);
	}
	return deja_dup_config_entry_type_id__volatile;
}



