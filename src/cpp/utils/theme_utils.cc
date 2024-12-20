#include <absl/types/optional.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "cpp/utils/theme_utils.h"
#include "cpp/blend/blend.h"
#include "cpp/scheme/scheme_vibrant.h"
#include "cpp/palettes/tones.h"

namespace material_color_utilities
{

    CustomColorGroup GetCustomColor(Argb source, const CustomColor &color)
    {
        Argb value = color.value;
        Argb from = value;
        Argb to = source;

        if (color.blend)
        {
            value = BlendHarmonize(from, to);
        }

        auto tones = TonalPalette(source);
        CustomColorGroup result;

        result.color = color;
        result.value = value;

        result.light = ColorGroup();

        result.light.color = tones.get(40);
        result.light.onColor = tones.get(100);
        result.light.colorContainer = tones.get(90);
        result.light.onColorContainer = tones.get(10);

        result.dark.color = tones.get(80);
        result.dark.onColor = tones.get(20);
        result.dark.colorContainer = tones.get(30);
        result.dark.onColorContainer = tones.get(90);

        return result;
    }

    Theme ThemeFromSourceColor(Argb source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors)
    {
        auto hctSource = Hct(source);
        Theme theme;
        theme.contrastLevel = contrastLevel;
        theme.variant = variant;
        theme.source = source;
        theme.schemes.light = GetSchemeInstance(variant, contrastLevel, hctSource, false);
        theme.schemes.dark = GetSchemeInstance(variant, contrastLevel, hctSource, true);

        for (const auto &c : customColors)
        {
            theme.customColors.push_back(GetCustomColor(source, c));
        }

        return theme;
    }

    // Mocked function for example (replace with actual implementations)
    Argb SourceColorFromImage(const std::string &image)
    {
        // Assuming we process the image here and return a source color
        return 0xFFFF0000; // Dummy color, replace with actual image processing logic
    }

    Theme ThemeFromImage(const std::string &image, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors)
    {
        Argb source = SourceColorFromImage(image);
        return ThemeFromSourceColor(source, contrastLevel, variant, customColors);
    }

} // namespace material_color_utilities