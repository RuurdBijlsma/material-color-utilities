#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/utils/util_types.h"
#include "cpp/pybindings/representations.h"
#include "cpp/pybindings/bindings.h"
#include <string>
namespace py = pybind11;

void bind_theme(py::module &m)
{
  py::class_<material_color_utilities::Theme>(m, "Theme")
      .def(py::init<>()) // Default constructor
      .def_static("from_source_color",
                  &material_color_utilities::Theme::FromSourceColor,
                  py::arg("source"),
                  py::arg("contrast_level"),
                  py::arg("variant"),
                  py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>())
      .def_static("from_array",
                  &material_color_utilities::Theme::FromImage,
                  py::arg("image"),
                  py::arg("contrast_level"),
                  py::arg("variant"),
                  py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>())
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
      .def(py::init<const material_color_utilities::Argb &>(), py::arg("argb"))
      .def_property_readonly("argb", &material_color_utilities::Hct::ToInt)
      .def_property_readonly("hex", &material_color_utilities::Hct::ToHex)
      .def_property("hue", &material_color_utilities::Hct::get_hue, &material_color_utilities::Hct::set_hue)
      .def_property("chroma", &material_color_utilities::Hct::get_chroma, &material_color_utilities::Hct::set_chroma)
      .def_property("tone", &material_color_utilities::Hct::get_tone, &material_color_utilities::Hct::set_tone)
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
      .def(py::init<const material_color_utilities::Argb &, const std::string &, const bool &>(), py::arg("value"), py::arg("name"), py::arg("blend"))
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
      .value("MONOCHROME", material_color_utilities::Variant::kMonochrome)
      .value("NEUTRAL", material_color_utilities::Variant::kNeutral)
      .value("TONALSPOT", material_color_utilities::Variant::kTonalSpot)
      .value("VIBRANT", material_color_utilities::Variant::kVibrant)
      .value("EXPRESSIVE", material_color_utilities::Variant::kExpressive)
      .value("FIDELITY", material_color_utilities::Variant::kFidelity)
      .value("CONTENT", material_color_utilities::Variant::kContent)
      .value("RAINBOW", material_color_utilities::Variant::kRainbow)
      .value("FRUITSALAD", material_color_utilities::Variant::kFruitSalad)
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
      .def(py::init<material_color_utilities::Argb>(), py::arg("argb"))
      .def(py::init<material_color_utilities::Hct>(), py::arg("hct"))
      .def(py::init<double, double>(), py::arg("hue"), py::arg("chroma"))
      .def(py::init<double, double, material_color_utilities::Hct>(), py::arg("hue"), py::arg("chroma"), py::arg("key_color"))
      .def("get", &material_color_utilities::TonalPalette::get)
      .def_property_readonly("hue", &material_color_utilities::TonalPalette::get_hue)
      .def_property_readonly("chroma", &material_color_utilities::TonalPalette::get_chroma)
      .def_property_readonly("key_color", &material_color_utilities::TonalPalette::get_key_color)
      .def("__repr__",
           [](const material_color_utilities::TonalPalette &t)
           {
             return tonal_palette_repr(t);
           });
}

void bind_color_group(py::module &m)
{
  py::class_<material_color_utilities::ColorGroup>(m, "ColorGroup")
      .def(py::init<>()) // Default constructor
      .def_readwrite("color", &material_color_utilities::ColorGroup::color)
      .def_readwrite("on_color", &material_color_utilities::ColorGroup::onColor)
      .def_readwrite("color_container", &material_color_utilities::ColorGroup::colorContainer)
      .def_readwrite("on_color_container", &material_color_utilities::ColorGroup::onColorContainer)
      .def("__repr__",
           [](const material_color_utilities::ColorGroup &c)
           {
             return color_group_repr(c);
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
      .def_readwrite("primary_palette", &material_color_utilities::DynamicScheme::primary_palette)
      .def_readwrite("secondary_palette", &material_color_utilities::DynamicScheme::secondary_palette)
      .def_readwrite("tertiary_palette", &material_color_utilities::DynamicScheme::tertiary_palette)
      .def_readwrite("neutral_palette", &material_color_utilities::DynamicScheme::neutral_palette)
      .def_readwrite("neutral_variant_palette", &material_color_utilities::DynamicScheme::neutral_variant_palette)
      .def_readwrite("error_palette", &material_color_utilities::DynamicScheme::error_palette)
      .def_property_readonly("surface_container_low", &material_color_utilities::DynamicScheme::GetSurfaceContainerLow)
      .def_property_readonly("surface_container", &material_color_utilities::DynamicScheme::GetSurfaceContainer)
      .def_property_readonly("surface_container_high", &material_color_utilities::DynamicScheme::GetSurfaceContainerHigh)
      .def_property_readonly("surface_container_highest", &material_color_utilities::DynamicScheme::GetSurfaceContainerHighest)
      .def_property_readonly("on_surface", &material_color_utilities::DynamicScheme::GetOnSurface)
      .def_property_readonly("surface_variant", &material_color_utilities::DynamicScheme::GetSurfaceVariant)
      .def_property_readonly("on_surface_variant", &material_color_utilities::DynamicScheme::GetOnSurfaceVariant)
      .def_property_readonly("inverse_surface", &material_color_utilities::DynamicScheme::GetInverseSurface)
      .def_property_readonly("inverse_on_surface", &material_color_utilities::DynamicScheme::GetInverseOnSurface)
      .def_property_readonly("outline", &material_color_utilities::DynamicScheme::GetOutline)
      .def_property_readonly("outline_variant", &material_color_utilities::DynamicScheme::GetOutlineVariant)
      .def_property_readonly("shadow", &material_color_utilities::DynamicScheme::GetShadow)
      .def_property_readonly("scrim", &material_color_utilities::DynamicScheme::GetScrim)
      .def_property_readonly("surface_tint", &material_color_utilities::DynamicScheme::GetSurfaceTint)
      .def_property_readonly("primary", &material_color_utilities::DynamicScheme::GetPrimary)
      .def_property_readonly("on_primary", &material_color_utilities::DynamicScheme::GetOnPrimary)
      .def_property_readonly("primary_container", &material_color_utilities::DynamicScheme::GetPrimaryContainer)
      .def_property_readonly("on_primary_container", &material_color_utilities::DynamicScheme::GetOnPrimaryContainer)
      .def_property_readonly("inverse_primary", &material_color_utilities::DynamicScheme::GetInversePrimary)
      .def_property_readonly("secondary", &material_color_utilities::DynamicScheme::GetSecondary)
      .def_property_readonly("on_secondary", &material_color_utilities::DynamicScheme::GetOnSecondary)
      .def_property_readonly("secondary_container", &material_color_utilities::DynamicScheme::GetSecondaryContainer)
      .def_property_readonly("on_secondary_container", &material_color_utilities::DynamicScheme::GetOnSecondaryContainer)
      .def_property_readonly("tertiary", &material_color_utilities::DynamicScheme::GetTertiary)
      .def_property_readonly("on_tertiary", &material_color_utilities::DynamicScheme::GetOnTertiary)
      .def_property_readonly("tertiary_container", &material_color_utilities::DynamicScheme::GetTertiaryContainer)
      .def_property_readonly("on_tertiary_container", &material_color_utilities::DynamicScheme::GetOnTertiaryContainer)
      .def_property_readonly("error", &material_color_utilities::DynamicScheme::GetError)
      .def_property_readonly("on_error", &material_color_utilities::DynamicScheme::GetOnError)
      .def_property_readonly("error_container", &material_color_utilities::DynamicScheme::GetErrorContainer)
      .def_property_readonly("on_error_container", &material_color_utilities::DynamicScheme::GetOnErrorContainer)
      .def_property_readonly("primary_fixed", &material_color_utilities::DynamicScheme::GetPrimaryFixed)
      .def_property_readonly("primary_fixed_dim", &material_color_utilities::DynamicScheme::GetPrimaryFixedDim)
      .def_property_readonly("on_primary_fixed", &material_color_utilities::DynamicScheme::GetOnPrimaryFixed)
      .def_property_readonly("on_primary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnPrimaryFixedVariant)
      .def_property_readonly("secondary_fixed", &material_color_utilities::DynamicScheme::GetSecondaryFixed)
      .def_property_readonly("secondary_fixed_dim", &material_color_utilities::DynamicScheme::GetSecondaryFixedDim)
      .def_property_readonly("on_secondary_fixed", &material_color_utilities::DynamicScheme::GetOnSecondaryFixed)
      .def_property_readonly("on_secondary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnSecondaryFixedVariant)
      .def_property_readonly("tertiary_fixed", &material_color_utilities::DynamicScheme::GetTertiaryFixed)
      .def_property_readonly("tertiary_fixed_dim", &material_color_utilities::DynamicScheme::GetTertiaryFixedDim)
      .def_property_readonly("on_tertiary_fixed", &material_color_utilities::DynamicScheme::GetOnTertiaryFixed)
      .def_property_readonly("on_tertiary_fixed_variant", &material_color_utilities::DynamicScheme::GetOnTertiaryFixedVariant)
      .def("__repr__",
           [](const material_color_utilities::DynamicScheme &d)
           {
             return dynamic_scheme_repr(d);
           });

  m.def("get_rotated_hue", &material_color_utilities::DynamicScheme::GetRotatedHue, py::arg("source_color"), py::arg("hues"), py::arg("rotations"));
}
