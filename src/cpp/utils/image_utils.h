#ifndef CPP_IMAGE_UTILS_H_
#define CPP_IMAGE_UTILS_H_

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cpp/utils/utils.h>

namespace py = pybind11;

namespace material_color_utilities
{
    std::vector<Argb> ProminentColorsFromImage(py::array_t<Argb> input_array, size_t max_colors = 64);
    Argb SourceColorFromImage(py::array_t<Argb> input_array);

} // namespace material_color_utilities

#endif // CPP_IMAGE_UTILS_H_
