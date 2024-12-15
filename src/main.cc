#include <pybind11/pybind11.h>
#include "cpp/utils/utils.h"

double quiz(int j)
{
  return material_color_utilities::Linearized(j);
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
}
