#ifndef CPP_UTIL_TYPES_H
#define CPP_UTIL_TYPES_H

#include "cpp/utils/utils.h"
#include <vector>
#include <string>
#include <cpp/dynamiccolor/dynamic_scheme.h>
#include <cpp/palettes/tones.h>
#include <cpp/dynamiccolor/variant.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

namespace material_color_utilities
{

    struct CustomColor
    {
        CustomColor() : value(0), name(""), blend(false) {}
        CustomColor(const Argb &value, const std::string &name, const bool &blend)
            : value(value), name(name), blend(blend) {}

        Argb value;
        std::string name;
        bool blend;
    };

    struct ColorGroup
    {
        // Default constructor
        ColorGroup()
            : color(), onColor(), colorContainer(), onColorContainer() {}
        Argb color;
        Argb onColor;
        Argb colorContainer;
        Argb onColorContainer;
    };

    struct CustomColorGroup
    {
        // Default constructor
        CustomColorGroup()
            : color(), value(0), light(), dark() {}
        CustomColor color;
        Argb value;
        ColorGroup light;
        ColorGroup dark;
    };

    struct DynamicSchemeGroup
    {
        // Default constructor
        DynamicSchemeGroup()
            : light(),
              dark() {}
        DynamicScheme light;
        DynamicScheme dark;
    };

    struct Theme
    {
        // Default constructor
        Theme()
            : source(0),
              schemes(),
              contrastLevel(0),
              variant(Variant::kVibrant),
              customColors() {}

        static Theme FromSourceColor(Argb source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors={});
        static Theme FromImage(py::array_t<Argb> image, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors={});

        Argb source;
        std::string GetHexSource() const;
        double contrastLevel;
        Variant variant;
        DynamicSchemeGroup schemes;
        std::vector<CustomColorGroup> customColors;
    };

} // namespace material_color_utilities

#endif // CPP_UTIL_TYPES_H
