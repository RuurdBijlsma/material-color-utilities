#ifndef CPP_THEME_UTILS_H_
#define CPP_THEME_UTILS_H_

#include <absl/types/optional.h>
#include <vector>
#include <string>
#include <unordered_map>

namespace material_color_utilities {

struct CustomColor {
    Argb value;
    std::string name;
    bool blend;
};

struct ColorGroup {
    Argb color;
    Argb onColor;
    Argb colorContainer;
    Argb onColorContainer;
};

struct CustomColorGroup {
    CustomColor color;
    Argb value;
    ColorGroup light;
    ColorGroup dark;
};

struct Theme {
    int source;
    struct {
        DynamicScheme light;
        DynamicScheme dark;
    } schemes;
    struct {
        TonalPalette primary;
        TonalPalette secondary;
        TonalPalette tertiary;
        TonalPalette neutral;
        TonalPalette neutralVariant;
        TonalPalette error;
    } palettes;
    std::vector<CustomColorGroup> customColors;
};

int SourceColorFromImage(const std::string& image);

/**
 * Generate custom color group from source and target color
 *
 * @param source Source color
 * @param color Custom color
 * @return Custom color group
 *
 * @link https://m3.material.io/styles/color/the-color-system/color-roles
 */
CustomColorGroup GetCustomColor(int source, const CustomColor& color);

Theme ThemeFromSourceColor(int source, const std::vector<CustomColor>& customColors = {});

Theme ThemeFromImage(const std::string& image, const std::vector<CustomColor>& customColors = {});

}  // namespace material_color_utilities

#endif  // CPP_THEME_UTILS_H_
