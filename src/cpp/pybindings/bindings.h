#ifndef CPP_BINDINGS_BINDINGS_H_
#define CPP_BINDINGS_BINDINGS_H_

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_theme(py::module &m);
void bind_hct(py::module &m);
void bind_dynamic_scheme_group(py::module &m);
void bind_custom_color_group(py::module &m);
void bind_custom_color(py::module &m);
void bind_color_group(py::module &m);
void bind_variant(py::module &m);
void bind_tonal_palette(py::module &m);
void bind_dynamic_scheme(py::module &m);

#endif  // CPP_BINDINGS_BINDINGS_H_
