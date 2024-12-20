#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include "cpp/pybindings/representations.h"
#include "cpp/pybindings/bindings.h"
#include <string>
namespace py = pybind11;

void bind_theme(py::module &m)
{
  py::class_<material_color_utilities::Theme>(m, "Theme")
      .def(py::init<>()) // Default constructor
      .def_readwrite("source", &material_color_utilities::Theme::source)
      .def_readwrite("schemes", &material_color_utilities::Theme::schemes)
      .def_readwrite("contrast_level", &material_color_utilities::Theme::contrastLevel)
      .def_readwrite("variant", &material_color_utilities::Theme::variant)
      .def_readwrite("custom_colors", &material_color_utilities::Theme::customColors)
      .def("__repr__",
           [](const material_color_utilities::Theme &t)
           {
             return theme_repr(t);
           });
}

void bind_hct(py::module &m)
{
  py::class_<material_color_utilities::Hct>(m, "Hct")
      .def(py::init<>()) // Default constructor
      .def(py::init<const material_color_utilities::Argb &>())
      .def("get_argb", &material_color_utilities::Hct::ToInt)
      .def("get_hue", &material_color_utilities::Hct::get_hue)
      .def("get_chroma", &material_color_utilities::Hct::get_chroma)
      .def("get_tone", &material_color_utilities::Hct::get_tone)  
      .def("__repr__",
           [](const material_color_utilities::Hct &h)
           {
             return hct_repr(h);
           });
}

void bind_dynamic_scheme_group(py::module &m)
{
  py::class_<material_color_utilities::DynamicSchemeGroup>(m, "DynamicSchemeGroup")
      .def(py::init<>()) // Default constructor
      .def_readwrite("light", &material_color_utilities::DynamicSchemeGroup::light)
      .def_readwrite("dark", &material_color_utilities::DynamicSchemeGroup::dark)
      .def("__repr__",
           [](const material_color_utilities::DynamicSchemeGroup &d)
           {
             return dynamic_scheme_group_repr(d);
           });
}

void bind_custom_color_group(py::module &m)
{
  py::class_<material_color_utilities::CustomColorGroup>(m, "CustomColorGroup")
      .def(py::init<>()) // Default constructor
      .def_readwrite("color", &material_color_utilities::CustomColorGroup::color)
      .def_readwrite("value", &material_color_utilities::CustomColorGroup::value)
      .def_readwrite("light", &material_color_utilities::CustomColorGroup::light)
      .def_readwrite("dark", &material_color_utilities::CustomColorGroup::dark)
      .def("__repr__",
           [](const material_color_utilities::CustomColorGroup &c)
           {
             return custom_color_group_repr(c);
           });
}

void bind_custom_color(py::module &m)
{
  py::class_<material_color_utilities::CustomColor>(m, "CustomColor")
      .def(py::init<>()) // Default constructor
      .def(py::init<const material_color_utilities::Argb &, const std::string &, const bool &>())
      .def_readwrite("value", &material_color_utilities::CustomColor::value)
      .def_readwrite("name", &material_color_utilities::CustomColor::name)
      .def_readwrite("blend", &material_color_utilities::CustomColor::blend)
      .def("__repr__",
           [](const material_color_utilities::CustomColor &c)
           {
             return custom_color_repr(c);
           });
}

void bind_variant(py::module &m)
{
  py::enum_<material_color_utilities::Variant>(m, "Variant")
      .value("kMonochrome", material_color_utilities::Variant::kMonochrome)
      .value("kNeutral", material_color_utilities::Variant::kNeutral)
      .value("kTonalSpot", material_color_utilities::Variant::kTonalSpot)
      .value("kVibrant", material_color_utilities::Variant::kVibrant)
      .value("kExpressive", material_color_utilities::Variant::kExpressive)
      .value("kFidelity", material_color_utilities::Variant::kFidelity)
      .value("kContent", material_color_utilities::Variant::kContent)
      .value("kRainbow", material_color_utilities::Variant::kRainbow)
      .value("kFruitSalad", material_color_utilities::Variant::kFruitSalad)
      .def("__repr__",
           [](const material_color_utilities::Variant &v)
           {
             return variant_repr(v);
           });
}

void bind_tonal_palette(py::module &m)
{
  py::class_<material_color_utilities::TonalPalette>(m, "TonalPalette")
      .def(py::init<>()) // Default constructor
      .def(py::init<material_color_utilities::Argb>())
      .def(py::init<material_color_utilities::Hct>())
      .def(py::init<double, double>())
      .def(py::init<double, double, material_color_utilities::Hct>())
      .def("get", &material_color_utilities::TonalPalette::get)
      .def("get_hue", &material_color_utilities::TonalPalette::get_hue)
      .def("get_chroma", &material_color_utilities::TonalPalette::get_chroma)
      .def("get_key_color", &material_color_utilities::TonalPalette::get_key_color)
      .def("__repr__",
           [](const material_color_utilities::TonalPalette &t)
           {
             return tonal_palette_repr(t);
           });
}

void bind_dynamic_scheme(py::module &m)
{
  py::class_<material_color_utilities::DynamicScheme>(m, "DynamicScheme")
      .def(py::init<>()) // Default constructor
      .def_readwrite("source_color_hct", &material_color_utilities::DynamicScheme::source_color_hct)
      .def_readwrite("variant", &material_color_utilities::DynamicScheme::variant)
      .def_readwrite("is_dark", &material_color_utilities::DynamicScheme::is_dark)
      .def_readwrite("contrast_level", &material_color_utilities::DynamicScheme::contrast_level)
      .def_readwrite("primary", &material_color_utilities::DynamicScheme::primary_palette)
      .def_readwrite("secondary", &material_color_utilities::DynamicScheme::secondary_palette)
      .def_readwrite("tertiary", &material_color_utilities::DynamicScheme::tertiary_palette)
      .def_readwrite("neutral", &material_color_utilities::DynamicScheme::neutral_palette)
      .def_readwrite("neutral_variant", &material_color_utilities::DynamicScheme::neutral_variant_palette)
      .def_readwrite("error", &material_color_utilities::DynamicScheme::error_palette)
      .def("get_surface_container_low", &material_color_utilities::DynamicScheme::GetSurfaceContainerLow)
      .def("get_surface_container", &material_color_utilities::DynamicScheme::GetSurfaceContainer)
      .def("get_surface_container_high", &material_color_utilities::DynamicScheme::GetSurfaceContainerHigh)
      .def("get_surface_container_highest", &material_color_utilities::DynamicScheme::GetSurfaceContainerHighest)
      .def("get_on_surface", &material_color_utilities::DynamicScheme::GetOnSurface)
      .def("get_surface_variant", &material_color_utilities::DynamicScheme::GetSurfaceVariant)
      .def("get_on_surface_variant", &material_color_utilities::DynamicScheme::GetOnSurfaceVariant)
      .def("get_inverse_surface", &material_color_utilities::DynamicScheme::GetInverseSurface)
      .def("get_inverse_on_surface", &material_color_utilities::DynamicScheme::GetInverseOnSurface)
      .def("get_outline", &material_color_utilities::DynamicScheme::GetOutline)
      .def("get_outline_variant", &material_color_utilities::DynamicScheme::GetOutlineVariant)
      .def("get_shadow", &material_color_utilities::DynamicScheme::GetShadow)
      .def("get_scrim", &material_color_utilities::DynamicScheme::GetScrim)
      .def("get_surface_tint", &material_color_utilities::DynamicScheme::GetSurfaceTint)
      .def("get_primary", &material_color_utilities::DynamicScheme::GetPrimary)
      .def("get_on_primary", &material_color_utilities::DynamicScheme::GetOnPrimary)
      .def("get_primary_container", &material_color_utilities::DynamicScheme::GetPrimaryContainer)
      .def("get_on_primary_container", &material_color_utilities::DynamicScheme::GetOnPrimaryContainer)
      .def("get_inverse_primary", &material_color_utilities::DynamicScheme::GetInversePrimary)
      .def("get_secondary", &material_color_utilities::DynamicScheme::GetSecondary)
      .def("get_on_secondary", &material_color_utilities::DynamicScheme::GetOnSecondary)
      .def("get_secondary_container", &material_color_utilities::DynamicScheme::GetSecondaryContainer)
      .def("get_on_secondary_container", &material_color_utilities::DynamicScheme::GetOnSecondaryContainer)
      .def("get_tertiary", &material_color_utilities::DynamicScheme::GetTertiary)
      .def("get_on_tertiary", &material_color_utilities::DynamicScheme::GetOnTertiary)
      .def("get_tertiary_container", &material_color_utilities::DynamicScheme::GetTertiaryContainer)
      .def("get_on_tertiary_container", &material_color_utilities::DynamicScheme::GetOnTertiaryContainer)
      .def("get_error", &material_color_utilities::DynamicScheme::GetError)
      .def("get_on_error", &material_color_utilities::DynamicScheme::GetOnError)
      .def("get_error_container", &material_color_utilities::DynamicScheme::GetErrorContainer)
      .def("get_on_error_container", &material_color_utilities::DynamicScheme::GetOnErrorContainer)
      .def("get_primary_fixed", &material_color_utilities::DynamicScheme::GetPrimaryFixed)
      .def("get_primary_fixed_dim", &material_color_utilities::DynamicScheme::GetPrimaryFixedDim)
      .def("get_on_primary_fixed", &material_color_utilities::DynamicScheme::GetOnPrimaryFixed)
      .def("get_on_primary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnPrimaryFixedVariant)
      .def("get_secondary_fixed", &material_color_utilities::DynamicScheme::GetSecondaryFixed)
      .def("get_secondary_fixed_dim", &material_color_utilities::DynamicScheme::GetSecondaryFixedDim)
      .def("get_on_secondary_fixed", &material_color_utilities::DynamicScheme::GetOnSecondaryFixed)
      .def("get_on_secondary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnSecondaryFixedVariant)
      .def("get_tertiary_fixed", &material_color_utilities::DynamicScheme::GetTertiaryFixed)
      .def("get_tertiary_fixed_dim", &material_color_utilities::DynamicScheme::GetTertiaryFixedDim)
      .def("get_on_tertiary_fixed", &material_color_utilities::DynamicScheme::GetOnTertiaryFixed)
      .def("get_on_tertiary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnTertiaryFixedVariant)
      .def("__repr__",
           [](const material_color_utilities::DynamicScheme &d)
           {
             return dynamic_scheme_repr(d);
           });

  m.def("get_rotated_hue", &material_color_utilities::DynamicScheme::GetRotatedHue, py::arg("source_color"), py::arg("hues"), py::arg("rotations"));
}