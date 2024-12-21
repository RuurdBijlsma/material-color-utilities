#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/pybindings/representations.h"
#include <string>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"

namespace py = pybind11;
using namespace material_color_utilities;

std::string theme_repr(const material_color_utilities::Theme &t)
{
  return "Theme(source=" + argb_repr(t.source) +
         ", schemes=" + dynamic_scheme_group_repr(t.schemes) +
         ", contrast_level=" + std::to_string(t.contrastLevel) +
         ", variant=" + VariantToString(t.variant) +
         ", custom_colors=" + custom_colors_vec_repr(t.customColors) + ")";
}

std::string argb_repr(const material_color_utilities::Argb &a)
{
  return material_color_utilities::RgbHexFromArgb(a) + "\"";
}

std::string bool_repr(const bool &b)
{
  return b ? "True" : "False";
}

std::string variant_repr(const material_color_utilities::Variant &v)
{
  return "Variant." + VariantToString(v);
}

std::string hct_repr(const material_color_utilities::Hct &h)
{
  return "Hct(hue=" + std::to_string(h.get_hue()) +
         ", chroma=" + std::to_string(h.get_chroma()) +
         ", tone=" + std::to_string(h.get_tone()) + ")";
}

std::string tonal_palette_repr(const material_color_utilities::TonalPalette &t)
{
  return "TonalPalette(hue=" + std::to_string(t.get_hue()) +
         ", chroma=" + std::to_string(t.get_chroma()) +
         ", key_color=" + hct_repr(t.get_key_color()) + ")";
}

std::string dynamic_scheme_repr(const material_color_utilities::DynamicScheme &d)
{
  return "DynamicScheme(source_color_hct=" + hct_repr(d.source_color_hct) +
         ", variant=" + variant_repr(d.variant) +
         ", is_dark=" + bool_repr(d.is_dark) +
         ", contrast_level=" + std::to_string(d.contrast_level) +
         ", primary=" + tonal_palette_repr(d.primary_palette) +
         ", secondary=" + tonal_palette_repr(d.secondary_palette) +
         ", tertiary=" + tonal_palette_repr(d.tertiary_palette) +
         ", neutral=" + tonal_palette_repr(d.neutral_palette) +
         ", neutral_variant=" + tonal_palette_repr(d.neutral_variant_palette) +
         ", error=" + tonal_palette_repr(d.error_palette) + ")";
}

std::string dynamic_scheme_group_repr(const material_color_utilities::DynamicSchemeGroup &d)
{
  return "DynamicSchemeGroup(light=" + dynamic_scheme_repr(d.light) +
         ", dark=" + dynamic_scheme_repr(d.dark) + ")";
}

std::string color_group_repr(const material_color_utilities::ColorGroup &c)
{
  return "ColorGroup(color=" + argb_repr(c.color) +
         ", on_color=" + argb_repr(c.onColor) +
         ", color_container=" + argb_repr(c.colorContainer) +
         ", on_color_container=" + argb_repr(c.onColorContainer) + ")";
}

std::string custom_color_repr(const material_color_utilities::CustomColor &c)
{
  return "CustomColor(value=" + argb_repr(c.value) +
         ", name=" + c.name +
         ", blend=" + bool_repr(c.blend) + ")";
}

std::string custom_color_group_repr(const material_color_utilities::CustomColorGroup &c)
{
  return "CustomColorGroup(color=" + custom_color_repr(c.color) +
         ", value=" + argb_repr(c.value) +
         ", light=" + color_group_repr(c.light) +
         ", dark=" + color_group_repr(c.dark) + ")";
}

std::string custom_colors_vec_repr(const std::vector<material_color_utilities::CustomColorGroup> &c)
{
  std::string result = "[";
  for (const auto &color : c)
  {
    result += custom_color_group_repr(color) + ", ";
  }
  result += "]";
  return result;
}
