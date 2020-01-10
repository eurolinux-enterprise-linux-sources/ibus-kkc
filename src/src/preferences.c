/* preferences.c generated by valac 0.20.1, the Vala compiler
 * generated from preferences.vala, do not modify */

/* 
 * Copyright (C) 2011-2013 Daiki Ueno <ueno@gnu.org>
 * Copyright (C) 2011-2013 Red Hat, Inc.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <ibus.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include <libkkc/libkkc.h>


#define TYPE_PREFERENCES (preferences_get_type ())
#define PREFERENCES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PREFERENCES, Preferences))
#define PREFERENCES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PREFERENCES, PreferencesClass))
#define IS_PREFERENCES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PREFERENCES))
#define IS_PREFERENCES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PREFERENCES))
#define PREFERENCES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PREFERENCES, PreferencesClass))

typedef struct _Preferences Preferences;
typedef struct _PreferencesClass PreferencesClass;
typedef struct _PreferencesPrivate PreferencesPrivate;

#define TYPE_DICTIONARY_REGISTRY (dictionary_registry_get_type ())
#define DICTIONARY_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DICTIONARY_REGISTRY, DictionaryRegistry))
#define DICTIONARY_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DICTIONARY_REGISTRY, DictionaryRegistryClass))
#define IS_DICTIONARY_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DICTIONARY_REGISTRY))
#define IS_DICTIONARY_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DICTIONARY_REGISTRY))
#define DICTIONARY_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DICTIONARY_REGISTRY, DictionaryRegistryClass))

typedef struct _DictionaryRegistry DictionaryRegistry;
typedef struct _DictionaryRegistryClass DictionaryRegistryClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_variant_iter_free0(var) ((var == NULL) ? NULL : (var = (g_variant_iter_free (var), NULL)))

#define TYPE_DICTIONARY_METADATA (dictionary_metadata_get_type ())
#define DICTIONARY_METADATA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DICTIONARY_METADATA, DictionaryMetadata))
#define DICTIONARY_METADATA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DICTIONARY_METADATA, DictionaryMetadataClass))
#define IS_DICTIONARY_METADATA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DICTIONARY_METADATA))
#define IS_DICTIONARY_METADATA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DICTIONARY_METADATA))
#define DICTIONARY_METADATA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DICTIONARY_METADATA, DictionaryMetadataClass))

typedef struct _DictionaryMetadata DictionaryMetadata;
typedef struct _DictionaryMetadataClass DictionaryMetadataClass;

struct _Preferences {
	GObject parent_instance;
	PreferencesPrivate * priv;
};

struct _PreferencesClass {
	GObjectClass parent_class;
};

struct _PreferencesPrivate {
	IBusConfig* config;
	DictionaryRegistry* registry;
	GeeMap* _default;
	GeeMap* current;
};


static gpointer preferences_parent_class = NULL;

GType preferences_get_type (void) G_GNUC_CONST;
GType dictionary_registry_get_type (void) G_GNUC_CONST;
#define PREFERENCES_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PREFERENCES, PreferencesPrivate))
enum  {
	PREFERENCES_DUMMY_PROPERTY
};
void preferences_load (Preferences* self);
GType dictionary_metadata_get_type (void) G_GNUC_CONST;
DictionaryMetadata** preferences_list_available_dictionaries (Preferences* self, int* result_length1);
DictionaryMetadata** dictionary_registry_list_available (DictionaryRegistry* self, int* result_length1);
DictionaryMetadata* preferences_get_dictionary_metadata (Preferences* self, const gchar* id);
DictionaryMetadata* dictionary_registry_get_metadata (DictionaryRegistry* self, const gchar* id);
GVariant* preferences_get (Preferences* self, const gchar* name);
void preferences_set (Preferences* self, const gchar* name, GVariant* value);
Preferences* preferences_new (IBusConfig* config);
Preferences* preferences_construct (GType object_type, IBusConfig* config);
DictionaryRegistry* dictionary_registry_new (void);
DictionaryRegistry* dictionary_registry_construct (GType object_type);
gboolean dictionary_metadata_get_default_enabled (DictionaryMetadata* self);
const gchar* dictionary_metadata_get_id (DictionaryMetadata* self);
static void preferences_value_changed_cb (Preferences* self, IBusConfig* config, const gchar* section, const gchar* name, GVariant* value);
static void _preferences_value_changed_cb_ibus_config_value_changed (IBusConfig* _sender, const gchar* p0, const gchar* p1, GVariant* p2, gpointer self);
static void g_cclosure_user_marshal_VOID__STRING_VARIANT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void preferences_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _g_variant_ref0 (gpointer self) {
	return self ? g_variant_ref (self) : NULL;
}


void preferences_load (Preferences* self) {
	IBusConfig* _tmp0_;
	GVariant* _tmp1_ = NULL;
	GVariant* _tmp2_;
	GVariant* values;
	GVariant* _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->config;
	_tmp1_ = ibus_config_get_values (_tmp0_, "engine/kkc");
	_tmp2_ = _g_variant_ref0 (_tmp1_);
	values = _tmp2_;
	_tmp3_ = values;
	if (_tmp3_ != NULL) {
		GVariant* _tmp4_;
		GVariantIter* _tmp5_ = NULL;
		GVariantIter* iter;
		GVariant* entry;
		_tmp4_ = values;
		_tmp5_ = g_variant_iter_new (_tmp4_);
		iter = _tmp5_;
		entry = NULL;
		while (TRUE) {
			GVariantIter* _tmp6_;
			GVariant* _tmp7_ = NULL;
			GVariant* _tmp8_;
			gchar* name = NULL;
			GVariant* value = NULL;
			GVariant* _tmp9_;
			GeeMap* _tmp10_;
			const gchar* _tmp11_;
			GVariant* _tmp12_;
			_tmp6_ = iter;
			_tmp7_ = g_variant_iter_next_value (_tmp6_);
			_g_variant_unref0 (entry);
			entry = _tmp7_;
			_tmp8_ = entry;
			if (!(_tmp8_ != NULL)) {
				break;
			}
			_tmp9_ = entry;
			g_variant_get (_tmp9_, "{sv}", &name, &value, NULL);
			_tmp10_ = self->priv->current;
			_tmp11_ = name;
			_tmp12_ = value;
			gee_map_set (_tmp10_, _tmp11_, _tmp12_);
			_g_variant_unref0 (value);
			_g_free0 (name);
		}
		_g_variant_unref0 (entry);
		_g_variant_iter_free0 (iter);
	}
	_g_variant_unref0 (values);
}


DictionaryMetadata** preferences_list_available_dictionaries (Preferences* self, int* result_length1) {
	DictionaryMetadata** result = NULL;
	DictionaryRegistry* _tmp0_;
	gint _tmp1_ = 0;
	DictionaryMetadata** _tmp2_ = NULL;
	DictionaryMetadata** _tmp3_;
	gint _tmp3__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->registry;
	_tmp2_ = dictionary_registry_list_available (_tmp0_, &_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp3__length1 = _tmp1_;
	if (result_length1) {
		*result_length1 = _tmp3__length1;
	}
	result = _tmp3_;
	return result;
}


DictionaryMetadata* preferences_get_dictionary_metadata (Preferences* self, const gchar* id) {
	DictionaryMetadata* result = NULL;
	DictionaryRegistry* _tmp0_;
	const gchar* _tmp1_;
	DictionaryMetadata* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	_tmp0_ = self->priv->registry;
	_tmp1_ = id;
	_tmp2_ = dictionary_registry_get_metadata (_tmp0_, _tmp1_);
	result = _tmp2_;
	return result;
}


GVariant* preferences_get (Preferences* self, const gchar* name) {
	GVariant* result = NULL;
	GeeMap* _tmp0_;
	const gchar* _tmp1_;
	gpointer _tmp2_ = NULL;
	GVariant* value;
	GVariant* _tmp3_;
	GeeMap* _tmp4_;
	const gchar* _tmp5_;
	gpointer _tmp6_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->current;
	_tmp1_ = name;
	_tmp2_ = gee_map_get (_tmp0_, _tmp1_);
	value = (GVariant*) _tmp2_;
	_tmp3_ = value;
	if (_tmp3_ != NULL) {
		result = value;
		return result;
	}
	_tmp4_ = self->priv->_default;
	_tmp5_ = name;
	_tmp6_ = gee_map_get (_tmp4_, _tmp5_);
	result = (GVariant*) _tmp6_;
	_g_variant_unref0 (value);
	return result;
}


void preferences_set (Preferences* self, const gchar* name, GVariant* value) {
	GeeMap* _tmp0_;
	const gchar* _tmp1_;
	gpointer _tmp2_ = NULL;
	GVariant* _value;
	gboolean _tmp3_ = FALSE;
	GVariant* _tmp4_;
	gboolean _tmp8_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (value != NULL);
	_tmp0_ = self->priv->current;
	_tmp1_ = name;
	_tmp2_ = gee_map_get (_tmp0_, _tmp1_);
	_value = (GVariant*) _tmp2_;
	_tmp4_ = _value;
	if (_tmp4_ == NULL) {
		_tmp3_ = TRUE;
	} else {
		GVariant* _tmp5_;
		GVariant* _tmp6_;
		gboolean _tmp7_ = FALSE;
		_tmp5_ = _value;
		_tmp6_ = value;
		_tmp7_ = g_variant_equal (_tmp5_, _tmp6_);
		_tmp3_ = !_tmp7_;
	}
	_tmp8_ = _tmp3_;
	if (_tmp8_) {
		GeeMap* _tmp9_;
		const gchar* _tmp10_;
		gpointer _tmp11_ = NULL;
		gboolean _tmp12_ = FALSE;
		GVariant* _tmp13_;
		gboolean _tmp17_;
		_tmp9_ = self->priv->_default;
		_tmp10_ = name;
		_tmp11_ = gee_map_get (_tmp9_, _tmp10_);
		_g_variant_unref0 (_value);
		_value = (GVariant*) _tmp11_;
		_tmp13_ = _value;
		if (_tmp13_ == NULL) {
			_tmp12_ = TRUE;
		} else {
			GVariant* _tmp14_;
			GVariant* _tmp15_;
			gboolean _tmp16_ = FALSE;
			_tmp14_ = _value;
			_tmp15_ = value;
			_tmp16_ = g_variant_equal (_tmp14_, _tmp15_);
			_tmp12_ = !_tmp16_;
		}
		_tmp17_ = _tmp12_;
		if (_tmp17_) {
			GeeMap* _tmp18_;
			const gchar* _tmp19_;
			GVariant* _tmp20_;
			IBusConfig* _tmp21_;
			const gchar* _tmp22_;
			GVariant* _tmp23_;
			_tmp18_ = self->priv->current;
			_tmp19_ = name;
			_tmp20_ = value;
			gee_map_set (_tmp18_, _tmp19_, _tmp20_);
			_tmp21_ = self->priv->config;
			_tmp22_ = name;
			_tmp23_ = value;
			ibus_config_set_value (_tmp21_, "engine/kkc", _tmp22_, _tmp23_);
		} else {
			GeeMap* _tmp24_;
			const gchar* _tmp25_;
			IBusConfig* _tmp26_;
			const gchar* _tmp27_;
			_tmp24_ = self->priv->current;
			_tmp25_ = name;
			gee_map_unset (_tmp24_, _tmp25_, NULL);
			_tmp26_ = self->priv->config;
			_tmp27_ = name;
			ibus_config_unset (_tmp26_, "engine/kkc", _tmp27_);
		}
	}
	_g_variant_unref0 (_value);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _preferences_value_changed_cb_ibus_config_value_changed (IBusConfig* _sender, const gchar* p0, const gchar* p1, GVariant* p2, gpointer self) {
	preferences_value_changed_cb (self, _sender, p0, p1, p2);
}


Preferences* preferences_construct (GType object_type, IBusConfig* config) {
	Preferences * self = NULL;
	DictionaryRegistry* _tmp0_;
	GeeMap* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	GVariant* _tmp5_;
	GVariant* _tmp6_;
	GeeArrayList* _tmp7_;
	GeeArrayList* dictionaries;
	gint _tmp8_ = 0;
	DictionaryMetadata** _tmp9_ = NULL;
	GeeMap* _tmp18_;
	GeeArrayList* _tmp19_;
	gint _tmp20_ = 0;
	gpointer* _tmp21_ = NULL;
	gchar** _tmp22_;
	gint _tmp22__length1;
	GVariant* _tmp23_;
	GVariant* _tmp24_;
	GeeMap* _tmp25_;
	GVariant* _tmp26_;
	GVariant* _tmp27_;
	GeeMap* _tmp28_;
	GVariant* _tmp29_;
	GVariant* _tmp30_;
	GeeMap* _tmp31_;
	GVariant* _tmp32_;
	GVariant* _tmp33_;
	GeeMap* _tmp34_;
	GVariant* _tmp35_;
	GVariant* _tmp36_;
	GeeMap* _tmp37_;
	GVariant* _tmp38_;
	GVariant* _tmp39_;
	GeeMap* _tmp40_;
	GVariant* _tmp41_;
	GVariant* _tmp42_;
	GeeMap* _tmp43_;
	GVariant* _tmp44_;
	GVariant* _tmp45_;
	GeeMap* _tmp46_;
	GVariant* _tmp47_;
	GVariant* _tmp48_;
	GeeMap* _tmp49_;
	GVariant* _tmp50_;
	GVariant* _tmp51_;
	GeeMap* _tmp52_;
	GVariant* _tmp53_;
	GVariant* _tmp54_;
	IBusConfig* _tmp55_;
	IBusConfig* _tmp56_;
	IBusConfig* _tmp57_;
	g_return_val_if_fail (config != NULL, NULL);
	self = (Preferences*) g_object_new (object_type, NULL);
	_tmp0_ = dictionary_registry_new ();
	_g_object_unref0 (self->priv->registry);
	self->priv->registry = _tmp0_;
	_tmp1_ = self->priv->_default;
	_tmp2_ = g_get_user_config_dir ();
	_tmp3_ = g_build_filename (_tmp2_, PACKAGE_NAME, "dictionary", NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_variant_new_string (_tmp4_);
	g_variant_ref_sink (_tmp5_);
	_tmp6_ = _tmp5_;
	gee_map_set (_tmp1_, "user_dictionary", _tmp6_);
	_g_variant_unref0 (_tmp6_);
	_g_free0 (_tmp4_);
	_tmp7_ = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
	dictionaries = _tmp7_;
	_tmp9_ = preferences_list_available_dictionaries (self, &_tmp8_);
	{
		DictionaryMetadata** metadata_collection = NULL;
		gint metadata_collection_length1 = 0;
		gint _metadata_collection_size_ = 0;
		gint metadata_it = 0;
		metadata_collection = _tmp9_;
		metadata_collection_length1 = _tmp8_;
		for (metadata_it = 0; metadata_it < _tmp8_; metadata_it = metadata_it + 1) {
			DictionaryMetadata* _tmp10_;
			DictionaryMetadata* metadata = NULL;
			_tmp10_ = _g_object_ref0 (metadata_collection[metadata_it]);
			metadata = _tmp10_;
			{
				DictionaryMetadata* _tmp11_;
				gboolean _tmp12_;
				gboolean _tmp13_;
				_tmp11_ = metadata;
				_tmp12_ = dictionary_metadata_get_default_enabled (_tmp11_);
				_tmp13_ = _tmp12_;
				if (_tmp13_) {
					GeeArrayList* _tmp14_;
					DictionaryMetadata* _tmp15_;
					const gchar* _tmp16_;
					const gchar* _tmp17_;
					_tmp14_ = dictionaries;
					_tmp15_ = metadata;
					_tmp16_ = dictionary_metadata_get_id (_tmp15_);
					_tmp17_ = _tmp16_;
					gee_abstract_collection_add ((GeeAbstractCollection*) _tmp14_, _tmp17_);
				}
				_g_object_unref0 (metadata);
			}
		}
		metadata_collection = (_vala_array_free (metadata_collection, metadata_collection_length1, (GDestroyNotify) g_object_unref), NULL);
	}
	_tmp18_ = self->priv->_default;
	_tmp19_ = dictionaries;
	_tmp21_ = gee_abstract_collection_to_array ((GeeAbstractCollection*) _tmp19_, &_tmp20_);
	_tmp22_ = _tmp21_;
	_tmp22__length1 = _tmp20_;
	_tmp23_ = g_variant_new_strv (_tmp22_, _tmp20_);
	g_variant_ref_sink (_tmp23_);
	_tmp24_ = _tmp23_;
	gee_map_set (_tmp18_, "system_dictionaries", _tmp24_);
	_g_variant_unref0 (_tmp24_);
	_tmp22_ = (_vala_array_free (_tmp22_, _tmp22__length1, (GDestroyNotify) g_free), NULL);
	_tmp25_ = self->priv->_default;
	_tmp26_ = g_variant_new_int32 ((gint32) KKC_PUNCTUATION_STYLE_JA_JA);
	g_variant_ref_sink (_tmp26_);
	_tmp27_ = _tmp26_;
	gee_map_set (_tmp25_, "punctuation_style", _tmp27_);
	_g_variant_unref0 (_tmp27_);
	_tmp28_ = self->priv->_default;
	_tmp29_ = g_variant_new_boolean (TRUE);
	g_variant_ref_sink (_tmp29_);
	_tmp30_ = _tmp29_;
	gee_map_set (_tmp28_, "auto_correct", _tmp30_);
	_g_variant_unref0 (_tmp30_);
	_tmp31_ = self->priv->_default;
	_tmp32_ = g_variant_new_int32 ((gint32) 10);
	g_variant_ref_sink (_tmp32_);
	_tmp33_ = _tmp32_;
	gee_map_set (_tmp31_, "page_size", _tmp33_);
	_g_variant_unref0 (_tmp33_);
	_tmp34_ = self->priv->_default;
	_tmp35_ = g_variant_new_int32 ((gint32) 0);
	g_variant_ref_sink (_tmp35_);
	_tmp36_ = _tmp35_;
	gee_map_set (_tmp34_, "pagination_start", _tmp36_);
	_g_variant_unref0 (_tmp36_);
	_tmp37_ = self->priv->_default;
	_tmp38_ = g_variant_new_boolean (FALSE);
	g_variant_ref_sink (_tmp38_);
	_tmp39_ = _tmp38_;
	gee_map_set (_tmp37_, "show_annotation", _tmp39_);
	_g_variant_unref0 (_tmp39_);
	_tmp40_ = self->priv->_default;
	_tmp41_ = g_variant_new_int32 ((gint32) KKC_INPUT_MODE_HIRAGANA);
	g_variant_ref_sink (_tmp41_);
	_tmp42_ = _tmp41_;
	gee_map_set (_tmp40_, "initial_input_mode", _tmp42_);
	_g_variant_unref0 (_tmp42_);
	_tmp43_ = self->priv->_default;
	_tmp44_ = g_variant_new_boolean (FALSE);
	g_variant_ref_sink (_tmp44_);
	_tmp45_ = _tmp44_;
	gee_map_set (_tmp43_, "egg_like_newline", _tmp45_);
	_g_variant_unref0 (_tmp45_);
	_tmp46_ = self->priv->_default;
	_tmp47_ = g_variant_new_string ("default");
	g_variant_ref_sink (_tmp47_);
	_tmp48_ = _tmp47_;
	gee_map_set (_tmp46_, "typing_rule", _tmp48_);
	_g_variant_unref0 (_tmp48_);
	_tmp49_ = self->priv->_default;
	_tmp50_ = g_variant_new_boolean (FALSE);
	g_variant_ref_sink (_tmp50_);
	_tmp51_ = _tmp50_;
	gee_map_set (_tmp49_, "use_custom_keymap", _tmp51_);
	_g_variant_unref0 (_tmp51_);
	_tmp52_ = self->priv->_default;
	_tmp53_ = g_variant_new_string ("jp");
	g_variant_ref_sink (_tmp53_);
	_tmp54_ = _tmp53_;
	gee_map_set (_tmp52_, "keymap", _tmp54_);
	_g_variant_unref0 (_tmp54_);
	_tmp55_ = config;
	_tmp56_ = _g_object_ref0 (_tmp55_);
	_g_object_unref0 (self->priv->config);
	self->priv->config = _tmp56_;
	preferences_load (self);
	_tmp57_ = config;
	g_signal_connect_object (_tmp57_, "value-changed", (GCallback) _preferences_value_changed_cb_ibus_config_value_changed, self, 0);
	_g_object_unref0 (dictionaries);
	return self;
}


Preferences* preferences_new (IBusConfig* config) {
	return preferences_construct (TYPE_PREFERENCES, config);
}


static void preferences_value_changed_cb (Preferences* self, IBusConfig* config, const gchar* section, const gchar* name, GVariant* value) {
	const gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (config != NULL);
	g_return_if_fail (section != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (value != NULL);
	_tmp0_ = section;
	if (g_strcmp0 (_tmp0_, "engine/kkc") == 0) {
		gboolean _tmp1_ = FALSE;
		GVariant* _tmp2_;
		gboolean _tmp9_;
		const gchar* _tmp15_;
		GVariant* _tmp16_;
		_tmp2_ = value;
		if (_tmp2_ == NULL) {
			_tmp1_ = TRUE;
		} else {
			GVariant* _tmp3_;
			GVariant** _tmp4_ = NULL;
			GVariant** _tmp5_;
			gint _tmp5__length1;
			GVariant* _tmp6_;
			GVariant* _tmp7_;
			gboolean _tmp8_ = FALSE;
			_tmp3_ = value;
			_tmp4_ = g_new0 (GVariant*, 0 + 1);
			_tmp5_ = _tmp4_;
			_tmp5__length1 = 0;
			_tmp6_ = g_variant_new_tuple (_tmp5_, 0);
			g_variant_ref_sink (_tmp6_);
			_tmp7_ = _tmp6_;
			_tmp8_ = g_variant_equal (_tmp3_, _tmp7_);
			_tmp1_ = _tmp8_;
			_g_variant_unref0 (_tmp7_);
			_tmp5_ = (_vala_array_free (_tmp5_, _tmp5__length1, (GDestroyNotify) g_variant_unref), NULL);
		}
		_tmp9_ = _tmp1_;
		if (_tmp9_) {
			GeeMap* _tmp10_;
			const gchar* _tmp11_;
			_tmp10_ = self->priv->current;
			_tmp11_ = name;
			gee_map_unset (_tmp10_, _tmp11_, NULL);
		} else {
			GeeMap* _tmp12_;
			const gchar* _tmp13_;
			GVariant* _tmp14_;
			_tmp12_ = self->priv->current;
			_tmp13_ = name;
			_tmp14_ = value;
			gee_map_set (_tmp12_, _tmp13_, _tmp14_);
		}
		_tmp15_ = name;
		_tmp16_ = value;
		g_signal_emit_by_name (self, "value-changed", _tmp15_, _tmp16_);
	}
}


static void g_cclosure_user_marshal_VOID__STRING_VARIANT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_VARIANT) (gpointer data1, const char* arg_1, gpointer arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_VARIANT callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_VARIANT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_variant (param_values + 2), data2);
}


static void preferences_class_init (PreferencesClass * klass) {
	preferences_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PreferencesPrivate));
	G_OBJECT_CLASS (klass)->finalize = preferences_finalize;
	g_signal_new ("value_changed", TYPE_PREFERENCES, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_VARIANT, G_TYPE_NONE, 2, G_TYPE_STRING, G_TYPE_VARIANT);
}


static void preferences_instance_init (Preferences * self) {
	GeeHashMap* _tmp0_;
	GeeHashMap* _tmp1_;
	self->priv = PREFERENCES_GET_PRIVATE (self);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_VARIANT, (GBoxedCopyFunc) g_variant_ref, g_variant_unref, NULL, NULL, NULL);
	self->priv->_default = (GeeMap*) _tmp0_;
	_tmp1_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_VARIANT, (GBoxedCopyFunc) g_variant_ref, g_variant_unref, NULL, NULL, NULL);
	self->priv->current = (GeeMap*) _tmp1_;
}


static void preferences_finalize (GObject* obj) {
	Preferences * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_PREFERENCES, Preferences);
	_g_object_unref0 (self->priv->config);
	_g_object_unref0 (self->priv->registry);
	_g_object_unref0 (self->priv->_default);
	_g_object_unref0 (self->priv->current);
	G_OBJECT_CLASS (preferences_parent_class)->finalize (obj);
}


GType preferences_get_type (void) {
	static volatile gsize preferences_type_id__volatile = 0;
	if (g_once_init_enter (&preferences_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PreferencesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) preferences_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Preferences), 0, (GInstanceInitFunc) preferences_instance_init, NULL };
		GType preferences_type_id;
		preferences_type_id = g_type_register_static (G_TYPE_OBJECT, "Preferences", &g_define_type_info, 0);
		g_once_init_leave (&preferences_type_id__volatile, preferences_type_id);
	}
	return preferences_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



