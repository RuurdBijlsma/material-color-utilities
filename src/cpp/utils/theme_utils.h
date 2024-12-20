#ifndef CPP_THEME_UTILS_H_
#define CPP_THEME_UTILS_H_

#include <absl/types/optional.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <cpp/dynamiccolor/dynamic_scheme.h>
#include <cpp/palettes/tones.h>
#include <cpp/dynamiccolor/variant.h>

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

        Argb source;
        double contrastLevel;
        Variant variant;
        DynamicSchemeGroup schemes;
        std::vector<CustomColorGroup> customColors;
    };

    Argb SourceColorFromImage(const std::string &image);

    /**
     * Generate custom color group from source and target color
     *
     * @param source Source color
     * @param color Custom color
     * @return Custom color group
     *
     * @link https://m3.material.io/styles/color/the-color-system/color-roles
     */
    CustomColorGroup GetCustomColor(Argb source, const CustomColor &color);

    Theme ThemeFromSourceColor(Argb source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors = {});

    Theme ThemeFromImage(const std::string &image, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors = {});

} // namespace material_color_utilities

#endif // CPP_THEME_UTILS_H_
