#ifndef CPP_UTIL_TYPES_H
#define CPP_UTIL_TYPES_H

#include <vector>
#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cpp/dynamiccolor/dynamic_scheme.h>
#include <cpp/palettes/tones.h>
#include <cpp/dynamiccolor/variant.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"

namespace py = pybind11;

namespace material_color_utilities
{
    struct CustomColor
    {
        CustomColor() : value(0), name(""), blend(false) {}
        CustomColor(const Argb &value, const std::string &name, const bool &blend)
            : value(value), name(name), blend(blend) {}
        CustomColor(const std::string &value, const std::string &name, const bool &blend)
            : value(ArgbFromHex(value)), name(name), blend(blend) {}

        Argb value;
        std::string GetHexValue() const;
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
        std::string GetHexColor() const;
        std::string GetHexOnColor() const;
        std::string GetHexColorContainer() const;
        std::string GetHexOnColorContainer() const;
    };

    struct CustomColorGroup
    {
        // Default constructor
        CustomColorGroup()
            : color(), value(0), light(), dark() {}
        CustomColor color;
        std::string GetHexValue() const;
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

        Argb source;
        std::string GetHexSource() const;
        double contrastLevel;
        Variant variant;
        DynamicSchemeGroup schemes;
        std::vector<CustomColorGroup> customColors;
    };

} // namespace material_color_utilities

#endif // CPP_UTIL_TYPES_H
