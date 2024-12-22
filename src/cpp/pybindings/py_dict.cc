#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/attr.h>
#include <cpp/utils/util_types.h>
#include <cpp/pybindings/py_dict.h>
#include <cpp/dynamiccolor/variant.h>
#include <string>
namespace py = pybind11;
using namespace pybind11::literals;

py::dict ThemeDict(const material_color_utilities::Theme &t)
{
    std::vector<py::dict> custom_colors_dicts;
    custom_colors_dicts.reserve(t.customColors.size());

    std::transform(t.customColors.begin(), t.customColors.end(),
                   std::back_inserter(custom_colors_dicts),
                   [](const auto &custom_color)
                   { return CustomColorGroupDict(custom_color); });

    return py::dict(
        "source"_a = t.GetHexSource(),
        "contrast_level"_a = t.contrastLevel,
        "variant"_a = VariantToString(t.variant),
        "schemes"_a = DynamicSchemeGroupDict(t.schemes),
        "custom_colors"_a = custom_colors_dicts);
}

py::dict CustomColorGroupDict(const material_color_utilities::CustomColorGroup &c)
{
    return py::dict(
        "color"_a = CustomColorDict(c.color),
        "value"_a = c.GetHexValue(),
        "light"_a = ColorGroupDict(c.light),
        "dark"_a = ColorGroupDict(c.dark));
}

py::dict CustomColorDict(const material_color_utilities::CustomColor &c)
{
    return py::dict(
        "value"_a = c.GetHexValue(),
        "name"_a = c.name,
        "blend"_a = c.blend);
}

py::dict ColorGroupDict(const material_color_utilities::ColorGroup &c)
{
    return py::dict(
        "color"_a = c.GetHexColor(),
        "on_color"_a = c.GetHexOnColor(),
        "color_container"_a = c.GetHexColorContainer(),
        "on_color_container"_a = c.GetHexOnColorContainer());
}

py::dict DynamicSchemeGroupDict(const material_color_utilities::DynamicSchemeGroup &d)
{
    return py::dict(
        "light"_a = DynamicSchemeDict(d.light),
        "dark"_a = DynamicSchemeDict(d.dark));
}

py::dict DynamicSchemeDict(const material_color_utilities::DynamicScheme &d)
{
    return py::dict(
        "source_color_hct"_a = HctDict(d.source_color_hct),
        "variant"_a = VariantToString(d.variant),
        "is_dark"_a = d.is_dark,
        "contrast_level"_a = d.contrast_level,
        "primary_palette"_a = TonalPaletteDict(d.primary_palette),
        "secondary_palette"_a = TonalPaletteDict(d.secondary_palette),
        "tertiary_palette"_a = TonalPaletteDict(d.tertiary_palette),
        "neutral_palette"_a = TonalPaletteDict(d.neutral_palette),
        "neutral_variant_palette"_a = TonalPaletteDict(d.neutral_variant_palette),
        "error_palette"_a = TonalPaletteDict(d.error_palette),
        "surface_container_low"_a = d.HexSurfaceContainerLow(),
        "surface_container"_a = d.HexSurfaceContainer(),
        "surface_container_high"_a = d.HexSurfaceContainerHigh(),
        "surface_container_highest"_a = d.HexSurfaceContainerHighest(),
        "on_surface"_a = d.HexOnSurface(),
        "surface_variant"_a = d.HexSurfaceVariant(),
        "on_surface_variant"_a = d.HexOnSurfaceVariant(),
        "inverse_surface"_a = d.HexInverseSurface(),
        "inverse_on_surface"_a = d.HexInverseOnSurface(),
        "outline"_a = d.HexOutline(),
        "outline_variant"_a = d.HexOutlineVariant(),
        "shadow"_a = d.HexShadow(),
        "scrim"_a = d.HexScrim(),
        "surface_tint"_a = d.HexSurfaceTint(),
        "primary"_a = d.HexPrimary(),
        "on_primary"_a = d.HexOnPrimary(),
        "primary_container"_a = d.HexPrimaryContainer(),
        "on_primary_container"_a = d.HexOnPrimaryContainer(),
        "inverse_primary"_a = d.HexInversePrimary(),
        "secondary"_a = d.HexSecondary(),
        "on_secondary"_a = d.HexOnSecondary(),
        "secondary_container"_a = d.HexSecondaryContainer(),
        "on_secondary_container"_a = d.HexOnSecondaryContainer(),
        "tertiary"_a = d.HexTertiary(),
        "on_tertiary"_a = d.HexOnTertiary(),
        "tertiary_container"_a = d.HexTertiaryContainer(),
        "on_tertiary_container"_a = d.HexOnTertiaryContainer(),
        "error"_a = d.HexError(),
        "on_error"_a = d.HexOnError(),
        "error_container"_a = d.HexErrorContainer(),
        "on_error_container"_a = d.HexOnErrorContainer(),
        "primary_fixed"_a = d.HexPrimaryFixed(),
        "primary_fixed_dim"_a = d.HexPrimaryFixedDim(),
        "on_primary_fixed"_a = d.HexOnPrimaryFixed(),
        "on_primary_fixed_variant"_a = d.HexOnPrimaryFixedVariant(),
        "secondary_fixed"_a = d.HexSecondaryFixed(),
        "secondary_fixed_dim"_a = d.HexSecondaryFixedDim(),
        "on_secondary_fixed"_a = d.HexOnSecondaryFixed(),
        "on_secondary_fixed_variant"_a = d.HexOnSecondaryFixedVariant(),
        "tertiary_fixed"_a = d.HexTertiaryFixed(),
        "tertiary_fixed_dim"_a = d.HexTertiaryFixedDim(),
        "on_tertiary_fixed"_a = d.HexOnTertiaryFixed(),
        "on_tertiary_fixed_variant"_a = d.HexOnTertiaryFixedVariant());
}

py::dict TonalPaletteDict(const material_color_utilities::TonalPalette &t)
{
    return py::dict(
        "hue"_a = t.get_hue(),
        "chroma"_a = t.get_chroma(),
        "tones"_a = py::dict(
            "10"_a = t.GetHex(10),
            "20"_a = t.GetHex(20),
            "30"_a = t.GetHex(30),
            "40"_a = t.GetHex(40),
            "50"_a = t.GetHex(50),
            "60"_a = t.GetHex(60),
            "70"_a = t.GetHex(70),
            "80"_a = t.GetHex(80),
            "90"_a = t.GetHex(90)));
        "key_color"_a = HctDict(t.get_key_color());
}

py::dict HctDict(const material_color_utilities::Hct &h)
{
    return py::dict(
        "hue"_a = h.get_hue(),
        "chroma"_a = h.get_chroma(),
        "tone"_a = h.get_tone());
}
