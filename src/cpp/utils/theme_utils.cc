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
        result.light = {
            tones.get(40),
            tones.get(100),
            tones.get(90),
            tones.get(10),
        };
        result.dark = {
            tones.get(80),
            tones.get(20),
            tones.get(30),
            tones.get(90),
        };

        return result;
    }

    Theme ThemeFromSourceColor(Argb source, const std::vector<CustomColor> &customColors)
    {
        auto hctSource = Hct(source);
        auto darkScheme = SchemeVibrant(hctSource, true);
        auto lightScheme = SchemeVibrant(hctSource, false);
        auto tones = TonalPalette(source);
        // auto palette = CorePalette::of(source);
        Theme theme;
        theme.source = source;
        theme.schemes.light = lightScheme;
        theme.schemes.dark = darkScheme;
        // theme.palettes.primary = palette.a1;
        // theme.palettes.secondary = palette.a2;
        // theme.palettes.tertiary = palette.a3;
        // theme.palettes.neutral = palette.n1;
        // theme.palettes.neutralVariant = palette.n2;
        // theme.palettes.error = palette.error;

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

    Theme ThemeFromImage(const std::string &image, const std::vector<CustomColor> &customColors)
    {
        Argb source = SourceColorFromImage(image);
        return ThemeFromSourceColor(source, customColors);
    }

} // namespace material_color_utilities