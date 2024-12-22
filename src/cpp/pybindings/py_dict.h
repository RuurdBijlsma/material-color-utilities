#ifndef CPP_PY_DICTS_H_
#define CPP_PY_DICTS_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/attr.h>
#include "cpp/utils/util_types.h"

namespace py = pybind11;
using namespace pybind11::literals;

py::dict ThemeDict(const material_color_utilities::Theme &t);
py::dict CustomColorGroupDict(const material_color_utilities::CustomColorGroup &c);
py::dict CustomColorDict(const material_color_utilities::CustomColor &c);
py::dict ColorGroupDict(const material_color_utilities::ColorGroup &c);
py::dict DynamicSchemeGroupDict(const material_color_utilities::DynamicSchemeGroup &d);
py::dict DynamicSchemeDict(const material_color_utilities::DynamicScheme &d);
py::dict TonalPaletteDict(const material_color_utilities::TonalPalette &t);
py::dict HctDict(const material_color_utilities::Hct &h);

#endif // CPP_PY_DICTS_H_
