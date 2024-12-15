#include <pybind11/pybind11.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include <string>

material_color_utilities::Argb quiz(std::string hex)
{
  return material_color_utilities::ArgbFromHex(hex);
}

std::string hello_from_bin() { return "Hello from ruurd-colors!"; }

namespace py = pybind11;

PYBIND11_MODULE(_core, m)
{
  m.doc() = "pybind11 hello module";

  m.def("hello_from_bin", &hello_from_bin, R"pbdoc(
      A function that returns a Hello string.
  )pbdoc");

  m.def("quiz", &quiz, R"pbdoc(
      A function that quiz.
  )pbdoc");

  m.def("argb_from_hex", &material_color_utilities::ArgbFromHex, R"pbdoc(
      Convert hex string to an ARGB integer value.
  )pbdoc");

  m.def("hex_from_argb", &material_color_utilities::HexFromArgb, R"pbdoc(
      Convert ARGB integer to hex string.
  )pbdoc");
}
