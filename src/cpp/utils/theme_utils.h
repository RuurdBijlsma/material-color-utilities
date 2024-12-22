#ifndef CPP_THEME_UTILS_H_
#define CPP_THEME_UTILS_H_

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>
#include <cpp/dynamiccolor/variant.h>
#include <cpp/utils/util_types.h>
namespace py = pybind11;

namespace material_color_utilities
{

    Theme ThemeFromColor(std::string source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors = {});
    Theme ThemeFromArgbColor(Argb source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors = {});
    Theme ThemeFromImage(py::array_t<Argb> image, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors = {});

} // namespace material_color_utilities

#endif // CPP_THEME_UTILS_H_
