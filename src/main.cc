#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include "cpp/pybindings/bindings.h"
#include <string>
namespace py = pybind11;

// TODO alle classes die gebind worden moeten default constructor hebben lijkt t
// Ik moet ook alle types in Theme nog binden (scheme, tonalpallette, etc. etc., repr zou ook wel nice zijn toch).
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
  bind_variant(m);

  m.def("argb_from_hex", &material_color_utilities::ArgbFromHex, "Converts a hex color code string to its ARGB representation.", py::arg("hex"));
  m.def("hex_from_argb", &material_color_utilities::HexFromArgb, "Returns the hexadecimal representation of a color.", py::arg("argb"));
  m.def("theme_from_source_color", &material_color_utilities::ThemeFromSourceColor, "Returns a theme from a source color.", py::arg("source"), py::arg("contrast_level"), py::arg("variant"), py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>());
  m.def("source_color_from_image", &material_color_utilities::ThemeFromImage, "Returns a theme from an image.", py::arg("image"), py::arg("contrast_level"), py::arg("variant"), py::arg("custom_colors") = std::vector<material_color_utilities::CustomColor>());
  m.def("source_color_from_image", &material_color_utilities::SourceColorFromImage, "Returns the source color from an image.", py::arg("image"));
}
