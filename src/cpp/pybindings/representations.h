#ifndef CPP_BINDINGS_REPRESENTATIONS_H_
#define CPP_BINDINGS_REPRESENTATIONS_H_

#include <string>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"

std::string variant_repr(const material_color_utilities::Variant &v);
std::string hct_repr(const material_color_utilities::Hct &h);
std::string tonal_palette_repr(const material_color_utilities::TonalPalette &t);
std::string dynamic_scheme_repr(const material_color_utilities::DynamicScheme &d);
std::string theme_repr(const material_color_utilities::Theme &t);
std::string dynamic_scheme_group_repr(const material_color_utilities::DynamicSchemeGroup &d);
std::string custom_color_repr(const material_color_utilities::CustomColor &c);
std::string custom_color_group_repr(const material_color_utilities::CustomColorGroup &c);
std::string custom_colors_vec_repr(const std::vector<material_color_utilities::CustomColorGroup> &c);

#endif // CPP_BINDINGS_REPRESENTATIONS_H_