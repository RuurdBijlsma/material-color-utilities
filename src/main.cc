#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include "cpp/utils/image_utils.h"
#include "cpp/pybindings/bindings.h"
#include <cpp/utils/color_utils.h>
#include <string>
namespace py = pybind11;

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

// TODO alle classes die gebind worden moeten default constructor hebben lijkt t
// Ik moet ook alle types in Theme nog binden (scheme,tonalpallette, etc. etc., repr zou ook wel nice zijn toch).
// snakecase instances in cpp weghalen, in bindings alleen snakecase hebben
// alle argb -> binded versions to hex conversion
// many fields are still black for some reason, look into this
// ik denk dat veel default constructors wel weg kunnen ofzo? idk proberen
// image color extraction

PYBIND11_MODULE(_core, m)
{
  bind_theme(m);
  bind_hct(m);
  bind_dynamic_scheme_group(m);
  bind_dynamic_scheme(m);
  bind_tonal_palette(m);
  bind_custom_color(m);
  bind_custom_color_group(m);
  bind_color_group(m);
  bind_variant(m);

  m.def("argb_from_hex",
        &material_color_utilities::ArgbFromHex,
        "Converts a hex color code string to its ARGB representation.",
        py::arg("hex"));
  m.def("hex_from_argb",
        &material_color_utilities::RgbHexFromArgb,
        "Returns the hexadecimal representation of a color.",
        py::arg("argb"));
  m.def("prominent_colors_from_array",
        &material_color_utilities::ProminentColorsFromImage,
        "Returns the prominent colors from an image in the shape of a 2D array.",
        py::arg("image"), py::arg("max_colors") = 64);
  m.def("prominent_colors_from_array_argb",
        &material_color_utilities::ProminentColorsFromImageArgb,
        "Returns the prominent colors from an image in the shape of a 2D array.",
        py::arg("image"), py::arg("max_colors") = 64);
  m.def("get_contrast_ratio",
        &material_color_utilities::GetContrastRatio,
        "Returns the contrast ratio of two colors.",
        py::arg("color1"), py::arg("color2"));
  m.def("theme_from_color",
        &material_color_utilities::ThemeFromColor,
        "Returns a theme from a source color.",
        py::arg("source"),
        py::arg("contrast_level") = 3,
        py::arg("variant") = material_color_utilities::Variant::kVibrant,
        py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>());
  m.def("theme_from_argb_color",
        &material_color_utilities::ThemeFromArgbColor,
        "Returns a theme from a source color.",
        py::arg("source"),
        py::arg("contrast_level") = 3,
        py::arg("variant") = material_color_utilities::Variant::kVibrant,
        py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>());
  m.def("theme_from_array",
        &material_color_utilities::ThemeFromImage,
        "Returns a theme from an image.",
        py::arg("image"),
        py::arg("contrast_level") = 3,
        py::arg("variant") = material_color_utilities::Variant::kVibrant,
        py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>());


#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
