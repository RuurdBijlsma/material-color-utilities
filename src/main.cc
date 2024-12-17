#include <pybind11/pybind11.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include <string>

material_color_utilities::Argb quiz(std::string hex)
{
  return material_color_utilities::ArgbFromHex(hex);
}

std::string hello_from_bin() { return "Hello from ruurd-colors!"; }

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.def("argb_from_hex", &material_color_utilities::ArgbFromHex);
    m.def("hex_from_argb", &material_color_utilities::HexFromArgb);
    m.def("theme_from_source_color", &material_color_utilities::ThemeFromSourceColor);
    m.def("theme_from_image", &material_color_utilities::ThemeFromImage);
    m.def("CustomColor", &material_color_utilities::CustomColor);
}
