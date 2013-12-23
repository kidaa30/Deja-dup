/* RecursiveOp.c generated by valac 0.16.1, the Vala compiler
 * generated from RecursiveOp.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define DEJA_DUP_TYPE_RECURSIVE_OP (deja_dup_recursive_op_get_type ())
#define DEJA_DUP_RECURSIVE_OP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_RECURSIVE_OP, DejaDupRecursiveOp))
#define DEJA_DUP_RECURSIVE_OP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_RECURSIVE_OP, DejaDupRecursiveOpClass))
#define DEJA_DUP_IS_RECURSIVE_OP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_RECURSIVE_OP))
#define DEJA_DUP_IS_RECURSIVE_OP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_RECURSIVE_OP))
#define DEJA_DUP_RECURSIVE_OP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_RECURSIVE_OP, DejaDupRecursiveOpClass))

typedef struct _DejaDupRecursiveOp DejaDupRecursiveOp;
typedef struct _DejaDupRecursiveOpClass DejaDupRecursiveOpClass;
typedef struct _DejaDupRecursiveOpPrivate DejaDupRecursiveOpPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block10Data Block10Data;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
typedef struct _DejaDupRecursiveOpStartAsyncData DejaDupRecursiveOpStartAsyncData;
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _DejaDupRecursiveOpDoDirData DejaDupRecursiveOpDoDirData;

struct _DejaDupRecursiveOp {
	GObject parent_instance;
	DejaDupRecursiveOpPrivate * priv;
	GFileType src_type;
	GFileType dst_type;
};

struct _DejaDupRecursiveOpClass {
	GObjectClass parent_class;
	void (*handle_file) (DejaDupRecursiveOp* self);
	void (*handle_dir) (DejaDupRecursiveOp* self);
	void (*finish_dir) (DejaDupRecursiveOp* self);
	DejaDupRecursiveOp* (*clone_for_info) (DejaDupRecursiveOp* self, GFileInfo* info);
};

struct _DejaDupRecursiveOpPrivate {
	GFile* _src;
	GFile* _dst;
	gint refs;
};

struct _Block10Data {
	int _ref_count_;
	DejaDupRecursiveOp * self;
	GMainLoop* loop;
};

struct _DejaDupRecursiveOpStartAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupRecursiveOp* self;
	GFile* _tmp0_;
	GFile* _tmp1_;
	GFileType _tmp2_;
	GFile* _tmp3_;
	GFile* _tmp4_;
	GFileType _tmp5_;
	GFileType _tmp6_;
};

struct _DejaDupRecursiveOpDoDirData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupRecursiveOp* self;
	GFile* _tmp0_;
	GFileEnumerator* _tmp1_;
	GFileEnumerator* enumerator;
	GFileEnumerator* _tmp2_;
	GList* _tmp3_;
	GList* infos;
	GList* _tmp4_;
	GList* info_collection;
	GList* info_it;
	GFileInfo* _tmp5_;
	GFileInfo* info;
	GFileInfo* _tmp6_;
	GList* _tmp7_;
	guint _tmp8_;
	GError* e;
	GFile* _tmp9_;
	GFile* _tmp10_;
	GError* _tmp11_;
	const gchar* _tmp12_;
	GError * _inner_error_;
};


static gpointer deja_dup_recursive_op_parent_class = NULL;

GType deja_dup_recursive_op_get_type (void) G_GNUC_CONST;
#define DEJA_DUP_RECURSIVE_OP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), DEJA_DUP_TYPE_RECURSIVE_OP, DejaDupRecursiveOpPrivate))
enum  {
	DEJA_DUP_RECURSIVE_OP_DUMMY_PROPERTY,
	DEJA_DUP_RECURSIVE_OP_SRC,
	DEJA_DUP_RECURSIVE_OP_DST
};
#define DEJA_DUP_RECURSIVE_OP_NUM_ENUMERATED 16
void deja_dup_recursive_op_handle_file (DejaDupRecursiveOp* self);
static void deja_dup_recursive_op_real_handle_file (DejaDupRecursiveOp* self);
void deja_dup_recursive_op_handle_dir (DejaDupRecursiveOp* self);
static void deja_dup_recursive_op_real_handle_dir (DejaDupRecursiveOp* self);
void deja_dup_recursive_op_finish_dir (DejaDupRecursiveOp* self);
static void deja_dup_recursive_op_real_finish_dir (DejaDupRecursiveOp* self);
DejaDupRecursiveOp* deja_dup_recursive_op_clone_for_info (DejaDupRecursiveOp* self, GFileInfo* info);
static DejaDupRecursiveOp* deja_dup_recursive_op_real_clone_for_info (DejaDupRecursiveOp* self, GFileInfo* info);
static gboolean deja_dup_recursive_op_idle_action (DejaDupRecursiveOp* self);
void deja_dup_recursive_op_start_async (DejaDupRecursiveOp* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void deja_dup_recursive_op_start_finish (DejaDupRecursiveOp* self, GAsyncResult* _res_);
void deja_dup_recursive_op_start (DejaDupRecursiveOp* self);
static Block10Data* block10_data_ref (Block10Data* _data10_);
static void block10_data_unref (void * _userdata_);
static gboolean _deja_dup_recursive_op_idle_action_gsource_func (gpointer self);
static void __lambda29_ (Block10Data* _data10_, DejaDupRecursiveOp* m);
static void ___lambda29__deja_dup_recursive_op_done (DejaDupRecursiveOp* _sender, gpointer self);
static void deja_dup_recursive_op_start_async_data_free (gpointer _data);
static gboolean deja_dup_recursive_op_start_async_co (DejaDupRecursiveOpStartAsyncData* _data_);
GFile* deja_dup_recursive_op_get_src (DejaDupRecursiveOp* self);
GFile* deja_dup_recursive_op_get_dst (DejaDupRecursiveOp* self);
static void deja_dup_recursive_op_do_dir (DejaDupRecursiveOp* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void deja_dup_recursive_op_do_dir_finish (DejaDupRecursiveOp* self, GAsyncResult* _res_);
static void deja_dup_recursive_op_start_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void deja_dup_recursive_op_check_ref (DejaDupRecursiveOp* self);
static void deja_dup_recursive_op_recurse_on_info (DejaDupRecursiveOp* self, GFileInfo* info);
static void deja_dup_recursive_op_add_ref (DejaDupRecursiveOp* self);
static void __lambda27_ (DejaDupRecursiveOp* self, DejaDupRecursiveOp* m);
static void deja_dup_recursive_op_remove_ref (DejaDupRecursiveOp* self);
static void ___lambda27__deja_dup_recursive_op_done (DejaDupRecursiveOp* _sender, gpointer self);
static void __lambda28_ (DejaDupRecursiveOp* self, DejaDupRecursiveOp* m, GFile* s, GFile* d, const gchar* e);
static void ___lambda28__deja_dup_recursive_op_raise_error (DejaDupRecursiveOp* _sender, GFile* src, GFile* dst, const gchar* errstr, gpointer self);
static void deja_dup_recursive_op_do_dir_data_free (gpointer _data);
static gboolean deja_dup_recursive_op_do_dir_co (DejaDupRecursiveOpDoDirData* _data_);
static void deja_dup_recursive_op_do_dir_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
DejaDupRecursiveOp* deja_dup_recursive_op_construct (GType object_type);
static void deja_dup_recursive_op_set_src (DejaDupRecursiveOp* self, GFile* value);
static void deja_dup_recursive_op_set_dst (DejaDupRecursiveOp* self, GFile* value);
static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void deja_dup_recursive_op_finalize (GObject* obj);
static void _vala_deja_dup_recursive_op_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_deja_dup_recursive_op_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static void deja_dup_recursive_op_real_handle_file (DejaDupRecursiveOp* self) {
}


void deja_dup_recursive_op_handle_file (DejaDupRecursiveOp* self) {
	g_return_if_fail (self != NULL);
	DEJA_DUP_RECURSIVE_OP_GET_CLASS (self)->handle_file (self);
}


static void deja_dup_recursive_op_real_handle_dir (DejaDupRecursiveOp* self) {
}


void deja_dup_recursive_op_handle_dir (DejaDupRecursiveOp* self) {
	g_return_if_fail (self != NULL);
	DEJA_DUP_RECURSIVE_OP_GET_CLASS (self)->handle_dir (self);
}


static void deja_dup_recursive_op_real_finish_dir (DejaDupRecursiveOp* self) {
}


void deja_dup_recursive_op_finish_dir (DejaDupRecursiveOp* self) {
	g_return_if_fail (self != NULL);
	DEJA_DUP_RECURSIVE_OP_GET_CLASS (self)->finish_dir (self);
}


static DejaDupRecursiveOp* deja_dup_recursive_op_real_clone_for_info (DejaDupRecursiveOp* self, GFileInfo* info) {
	g_critical ("Type `%s' does not implement abstract method `deja_dup_recursive_op_clone_for_info'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


DejaDupRecursiveOp* deja_dup_recursive_op_clone_for_info (DejaDupRecursiveOp* self, GFileInfo* info) {
	g_return_val_if_fail (self != NULL, NULL);
	return DEJA_DUP_RECURSIVE_OP_GET_CLASS (self)->clone_for_info (self, info);
}


static gboolean deja_dup_recursive_op_idle_action (DejaDupRecursiveOp* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	deja_dup_recursive_op_start_async (self, NULL, NULL);
	result = FALSE;
	return result;
}


static Block10Data* block10_data_ref (Block10Data* _data10_) {
	g_atomic_int_inc (&_data10_->_ref_count_);
	return _data10_;
}


static void block10_data_unref (void * _userdata_) {
	Block10Data* _data10_;
	_data10_ = (Block10Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data10_->_ref_count_)) {
		DejaDupRecursiveOp * self;
		self = _data10_->self;
		_g_main_loop_unref0 (_data10_->loop);
		_g_object_unref0 (self);
		g_slice_free (Block10Data, _data10_);
	}
}


static gboolean _deja_dup_recursive_op_idle_action_gsource_func (gpointer self) {
	gboolean result;
	result = deja_dup_recursive_op_idle_action (self);
	return result;
}


static void __lambda29_ (Block10Data* _data10_, DejaDupRecursiveOp* m) {
	DejaDupRecursiveOp * self;
	self = _data10_->self;
	g_return_if_fail (m != NULL);
	g_main_loop_quit (_data10_->loop);
}


static void ___lambda29__deja_dup_recursive_op_done (DejaDupRecursiveOp* _sender, gpointer self) {
	__lambda29_ (self, _sender);
}


void deja_dup_recursive_op_start (DejaDupRecursiveOp* self) {
	Block10Data* _data10_;
	GMainLoop* _tmp0_;
	g_return_if_fail (self != NULL);
	_data10_ = g_slice_new0 (Block10Data);
	_data10_->_ref_count_ = 1;
	_data10_->self = g_object_ref (self);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _deja_dup_recursive_op_idle_action_gsource_func, g_object_ref (self), g_object_unref);
	_tmp0_ = g_main_loop_new (NULL, FALSE);
	_data10_->loop = _tmp0_;
	g_signal_connect_data (self, "done", (GCallback) ___lambda29__deja_dup_recursive_op_done, block10_data_ref (_data10_), (GClosureNotify) block10_data_unref, 0);
	g_main_loop_run (_data10_->loop);
	block10_data_unref (_data10_);
	_data10_ = NULL;
}


static void deja_dup_recursive_op_start_async_data_free (gpointer _data) {
	DejaDupRecursiveOpStartAsyncData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupRecursiveOpStartAsyncData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void deja_dup_recursive_op_start_async (DejaDupRecursiveOp* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupRecursiveOpStartAsyncData* _data_;
	DejaDupRecursiveOp* _tmp0_;
	_data_ = g_slice_new0 (DejaDupRecursiveOpStartAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_recursive_op_start_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_recursive_op_start_async_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_recursive_op_start_async_co (_data_);
}


void deja_dup_recursive_op_start_finish (DejaDupRecursiveOp* self, GAsyncResult* _res_) {
	DejaDupRecursiveOpStartAsyncData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void deja_dup_recursive_op_start_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	DejaDupRecursiveOpStartAsyncData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	deja_dup_recursive_op_start_async_co (_data_);
}


static gboolean deja_dup_recursive_op_start_async_co (DejaDupRecursiveOpStartAsyncData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->priv->_src;
	if (_data_->_tmp0_ != NULL) {
		_data_->_tmp1_ = _data_->self->priv->_src;
		_data_->_tmp2_ = 0;
		_data_->_tmp2_ = g_file_query_file_type (_data_->_tmp1_, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL);
		_data_->self->src_type = _data_->_tmp2_;
	}
	_data_->_tmp3_ = _data_->self->priv->_dst;
	if (_data_->_tmp3_ != NULL) {
		_data_->_tmp4_ = _data_->self->priv->_dst;
		_data_->_tmp5_ = 0;
		_data_->_tmp5_ = g_file_query_file_type (_data_->_tmp4_, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, NULL);
		_data_->self->dst_type = _data_->_tmp5_;
	}
	_data_->_tmp6_ = _data_->self->src_type;
	switch (_data_->_tmp6_) {
		case G_FILE_TYPE_DIRECTORY:
		{
			_data_->_state_ = 1;
			deja_dup_recursive_op_do_dir (_data_->self, deja_dup_recursive_op_start_async_ready, _data_);
			return FALSE;
			_state_1:
			deja_dup_recursive_op_do_dir_finish (_data_->self, _data_->_res_);
			break;
		}
		default:
		{
			deja_dup_recursive_op_handle_file (_data_->self);
			break;
		}
	}
	deja_dup_recursive_op_check_ref (_data_->self);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void __lambda27_ (DejaDupRecursiveOp* self, DejaDupRecursiveOp* m) {
	DejaDupRecursiveOp* _tmp0_;
	g_return_if_fail (m != NULL);
	deja_dup_recursive_op_remove_ref (self);
	_tmp0_ = m;
	g_object_unref ((GObject*) _tmp0_);
}


static void ___lambda27__deja_dup_recursive_op_done (DejaDupRecursiveOp* _sender, gpointer self) {
	__lambda27_ (self, _sender);
}


static void __lambda28_ (DejaDupRecursiveOp* self, DejaDupRecursiveOp* m, GFile* s, GFile* d, const gchar* e) {
	GFile* _tmp0_;
	GFile* _tmp1_;
	const gchar* _tmp2_;
	g_return_if_fail (m != NULL);
	g_return_if_fail (s != NULL);
	g_return_if_fail (d != NULL);
	g_return_if_fail (e != NULL);
	_tmp0_ = s;
	_tmp1_ = d;
	_tmp2_ = e;
	g_signal_emit_by_name (self, "raise-error", _tmp0_, _tmp1_, _tmp2_);
}


static void ___lambda28__deja_dup_recursive_op_raise_error (DejaDupRecursiveOp* _sender, GFile* src, GFile* dst, const gchar* errstr, gpointer self) {
	__lambda28_ (self, _sender, src, dst, errstr);
}


static void deja_dup_recursive_op_recurse_on_info (DejaDupRecursiveOp* self, GFileInfo* info) {
	GFileInfo* _tmp0_;
	DejaDupRecursiveOp* _tmp1_ = NULL;
	DejaDupRecursiveOp* op;
	g_return_if_fail (self != NULL);
	g_return_if_fail (info != NULL);
	deja_dup_recursive_op_add_ref (self);
	_tmp0_ = info;
	_tmp1_ = deja_dup_recursive_op_clone_for_info (self, _tmp0_);
	op = _tmp1_;
	g_object_ref ((GObject*) op);
	g_signal_connect_object (op, "done", (GCallback) ___lambda27__deja_dup_recursive_op_done, self, 0);
	g_signal_connect_object (op, "raise-error", (GCallback) ___lambda28__deja_dup_recursive_op_raise_error, self, 0);
	deja_dup_recursive_op_start_async (op, NULL, NULL);
	_g_object_unref0 (op);
}


static void deja_dup_recursive_op_do_dir_data_free (gpointer _data) {
	DejaDupRecursiveOpDoDirData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupRecursiveOpDoDirData, _data_);
}


static void deja_dup_recursive_op_do_dir (DejaDupRecursiveOp* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupRecursiveOpDoDirData* _data_;
	DejaDupRecursiveOp* _tmp0_;
	_data_ = g_slice_new0 (DejaDupRecursiveOpDoDirData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_recursive_op_do_dir);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_recursive_op_do_dir_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_recursive_op_do_dir_co (_data_);
}


static void deja_dup_recursive_op_do_dir_finish (DejaDupRecursiveOp* self, GAsyncResult* _res_) {
	DejaDupRecursiveOpDoDirData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void deja_dup_recursive_op_do_dir_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	DejaDupRecursiveOpDoDirData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	deja_dup_recursive_op_do_dir_co (_data_);
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static gboolean deja_dup_recursive_op_do_dir_co (DejaDupRecursiveOpDoDirData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	deja_dup_recursive_op_handle_dir (_data_->self);
	deja_dup_recursive_op_add_ref (_data_->self);
	{
		_data_->_tmp0_ = _data_->self->priv->_src;
		_data_->_state_ = 1;
		g_file_enumerate_children_async (_data_->_tmp0_, G_FILE_ATTRIBUTE_STANDARD_NAME, G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS, G_PRIORITY_DEFAULT, NULL, deja_dup_recursive_op_do_dir_ready, _data_);
		return FALSE;
		_state_1:
		_data_->_tmp1_ = NULL;
		_data_->_tmp1_ = g_file_enumerate_children_finish (_data_->_tmp0_, _data_->_res_, &_data_->_inner_error_);
		_data_->enumerator = _data_->_tmp1_;
		if (_data_->_inner_error_ != NULL) {
			goto __catch39_g_error;
		}
		while (TRUE) {
			_data_->_tmp2_ = _data_->enumerator;
			_data_->_state_ = 2;
			g_file_enumerator_next_files_async (_data_->_tmp2_, DEJA_DUP_RECURSIVE_OP_NUM_ENUMERATED, G_PRIORITY_DEFAULT, NULL, deja_dup_recursive_op_do_dir_ready, _data_);
			return FALSE;
			_state_2:
			_data_->_tmp3_ = NULL;
			_data_->_tmp3_ = g_file_enumerator_next_files_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
			_data_->infos = _data_->_tmp3_;
			if (_data_->_inner_error_ != NULL) {
				_g_object_unref0 (_data_->enumerator);
				goto __catch39_g_error;
			}
			_data_->_tmp4_ = _data_->infos;
			{
				_data_->info_collection = _data_->_tmp4_;
				for (_data_->info_it = _data_->info_collection; _data_->info_it != NULL; _data_->info_it = _data_->info_it->next) {
					_data_->_tmp5_ = _g_object_ref0 ((GFileInfo*) _data_->info_it->data);
					_data_->info = _data_->_tmp5_;
					{
						_data_->_tmp6_ = _data_->info;
						deja_dup_recursive_op_recurse_on_info (_data_->self, _data_->_tmp6_);
						_g_object_unref0 (_data_->info);
					}
				}
			}
			_data_->_tmp7_ = _data_->infos;
			_data_->_tmp8_ = 0U;
			_data_->_tmp8_ = g_list_length (_data_->_tmp7_);
			if (_data_->_tmp8_ != ((guint) DEJA_DUP_RECURSIVE_OP_NUM_ENUMERATED)) {
				deja_dup_recursive_op_remove_ref (_data_->self);
				__g_list_free__g_object_unref0_0 (_data_->infos);
				break;
			}
			__g_list_free__g_object_unref0_0 (_data_->infos);
		}
		_g_object_unref0 (_data_->enumerator);
	}
	goto __finally39;
	__catch39_g_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp9_ = _data_->self->priv->_src;
		_data_->_tmp10_ = _data_->self->priv->_dst;
		_data_->_tmp11_ = _data_->e;
		_data_->_tmp12_ = _data_->_tmp11_->message;
		g_signal_emit_by_name (_data_->self, "raise-error", _data_->_tmp9_, _data_->_tmp10_, _data_->_tmp12_);
		deja_dup_recursive_op_remove_ref (_data_->self);
		_g_error_free0 (_data_->e);
	}
	__finally39:
	if (_data_->_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
		g_clear_error (&_data_->_inner_error_);
		return FALSE;
	}
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void deja_dup_recursive_op_add_ref (DejaDupRecursiveOp* self) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->refs;
	self->priv->refs = _tmp0_ + 1;
}


static void deja_dup_recursive_op_remove_ref (DejaDupRecursiveOp* self) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->refs;
	self->priv->refs = _tmp0_ - 1;
	deja_dup_recursive_op_check_ref (self);
}


static void deja_dup_recursive_op_check_ref (DejaDupRecursiveOp* self) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->refs;
	if (_tmp0_ == 0) {
		GFileType _tmp1_;
		_tmp1_ = self->src_type;
		if (_tmp1_ == G_FILE_TYPE_DIRECTORY) {
			deja_dup_recursive_op_finish_dir (self);
		}
		g_signal_emit_by_name (self, "done");
	}
}


DejaDupRecursiveOp* deja_dup_recursive_op_construct (GType object_type) {
	DejaDupRecursiveOp * self = NULL;
	self = (DejaDupRecursiveOp*) g_object_new (object_type, NULL);
	return self;
}


GFile* deja_dup_recursive_op_get_src (DejaDupRecursiveOp* self) {
	GFile* result;
	GFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_src;
	result = _tmp0_;
	return result;
}


static void deja_dup_recursive_op_set_src (DejaDupRecursiveOp* self, GFile* value) {
	GFile* _tmp0_;
	GFile* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_src);
	self->priv->_src = _tmp1_;
	g_object_notify ((GObject *) self, "src");
}


GFile* deja_dup_recursive_op_get_dst (DejaDupRecursiveOp* self) {
	GFile* result;
	GFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_dst;
	result = _tmp0_;
	return result;
}


static void deja_dup_recursive_op_set_dst (DejaDupRecursiveOp* self, GFile* value) {
	GFile* _tmp0_;
	GFile* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_dst);
	self->priv->_dst = _tmp1_;
	g_object_notify ((GObject *) self, "dst");
}


static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (gpointer data1, gpointer arg_1, gpointer arg_2, const char* arg_3, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_OBJECT_STRING callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_object (param_values + 2), g_value_get_string (param_values + 3), data2);
}


static void deja_dup_recursive_op_class_init (DejaDupRecursiveOpClass * klass) {
	deja_dup_recursive_op_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DejaDupRecursiveOpPrivate));
	DEJA_DUP_RECURSIVE_OP_CLASS (klass)->handle_file = deja_dup_recursive_op_real_handle_file;
	DEJA_DUP_RECURSIVE_OP_CLASS (klass)->handle_dir = deja_dup_recursive_op_real_handle_dir;
	DEJA_DUP_RECURSIVE_OP_CLASS (klass)->finish_dir = deja_dup_recursive_op_real_finish_dir;
	DEJA_DUP_RECURSIVE_OP_CLASS (klass)->clone_for_info = deja_dup_recursive_op_real_clone_for_info;
	G_OBJECT_CLASS (klass)->get_property = _vala_deja_dup_recursive_op_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_deja_dup_recursive_op_set_property;
	G_OBJECT_CLASS (klass)->finalize = deja_dup_recursive_op_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEJA_DUP_RECURSIVE_OP_SRC, g_param_spec_object ("src", "src", "src", G_TYPE_FILE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEJA_DUP_RECURSIVE_OP_DST, g_param_spec_object ("dst", "dst", "dst", G_TYPE_FILE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("done", DEJA_DUP_TYPE_RECURSIVE_OP, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("raise_error", DEJA_DUP_TYPE_RECURSIVE_OP, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_OBJECT_STRING, G_TYPE_NONE, 3, G_TYPE_FILE, G_TYPE_FILE, G_TYPE_STRING);
}


static void deja_dup_recursive_op_instance_init (DejaDupRecursiveOp * self) {
	self->priv = DEJA_DUP_RECURSIVE_OP_GET_PRIVATE (self);
}


static void deja_dup_recursive_op_finalize (GObject* obj) {
	DejaDupRecursiveOp * self;
	self = DEJA_DUP_RECURSIVE_OP (obj);
	_g_object_unref0 (self->priv->_src);
	_g_object_unref0 (self->priv->_dst);
	G_OBJECT_CLASS (deja_dup_recursive_op_parent_class)->finalize (obj);
}


GType deja_dup_recursive_op_get_type (void) {
	static volatile gsize deja_dup_recursive_op_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_recursive_op_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupRecursiveOpClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_recursive_op_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupRecursiveOp), 0, (GInstanceInitFunc) deja_dup_recursive_op_instance_init, NULL };
		GType deja_dup_recursive_op_type_id;
		deja_dup_recursive_op_type_id = g_type_register_static (G_TYPE_OBJECT, "DejaDupRecursiveOp", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&deja_dup_recursive_op_type_id__volatile, deja_dup_recursive_op_type_id);
	}
	return deja_dup_recursive_op_type_id__volatile;
}


static void _vala_deja_dup_recursive_op_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	DejaDupRecursiveOp * self;
	self = DEJA_DUP_RECURSIVE_OP (object);
	switch (property_id) {
		case DEJA_DUP_RECURSIVE_OP_SRC:
		g_value_set_object (value, deja_dup_recursive_op_get_src (self));
		break;
		case DEJA_DUP_RECURSIVE_OP_DST:
		g_value_set_object (value, deja_dup_recursive_op_get_dst (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_deja_dup_recursive_op_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	DejaDupRecursiveOp * self;
	self = DEJA_DUP_RECURSIVE_OP (object);
	switch (property_id) {
		case DEJA_DUP_RECURSIVE_OP_SRC:
		deja_dup_recursive_op_set_src (self, g_value_get_object (value));
		break;
		case DEJA_DUP_RECURSIVE_OP_DST:
		deja_dup_recursive_op_set_dst (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



