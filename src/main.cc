#include <pybind11/pybind11.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include <string>
#include <pybind11/stl.h> // This is required for std::vector and other STL types

material_color_utilities::Argb quiz(std::string hex)
{
  return material_color_utilities::ArgbFromHex(hex);
}

std::string hello_from_bin() { return "Hello from ruurd-colors!"; }

namespace py = pybind11;

// TODO alle classes die gebind worden moeten default constructor hebben lijkt t
// Ik moet ook alle types in Theme nog binden (scheme, tonalpallette, etc. etc., repr zou ook wel nice zijn toch).

void bind_theme(py::module &m)
{
  py::class_<material_color_utilities::Theme>(m, "Theme")
      .def(py::init<>()) // Default constructor
      .def_readwrite("source", &material_color_utilities::Theme::source)
      .def_readwrite("schemes", &material_color_utilities::Theme::schemes)
      .def_readwrite("palettes", &material_color_utilities::Theme::palettes)
      .def_readwrite("customColors", &material_color_utilities::Theme::customColors);
}

PYBIND11_MODULE(_core, m)
{
  bind_theme(m);

  m.def("argb_from_hex", &material_color_utilities::ArgbFromHex);
  m.def("hex_from_argb", &material_color_utilities::HexFromArgb);
  m.def("theme_from_source_color", &material_color_utilities::ThemeFromSourceColor);
  m.def("source_color_from_image", &material_color_utilities::SourceColorFromImage);

  py::class_<material_color_utilities::CustomColor>(m, "CustomColor")
      .def(py::init<const material_color_utilities::Argb &, const std::string &, const bool &>(),
           py::arg("value"), py::arg("name"), py::arg("blend"))
      .def_readwrite("value", &material_color_utilities::CustomColor::value)
      .def_readwrite("name", &material_color_utilities::CustomColor::name)
      .def_readwrite("blend", &material_color_utilities::CustomColor::blend);
}
