#include <cpp/palettes/tones.h>
#include <cpp/contrast/contrast.h>
#include <cpp/blend/blend.h>
#include <cpp/utils/util_types.h>
#include <cpp/utils/hex_utils.h>
#include <cpp/utils/utils.h>
#include <cpp/utils/color_utils.h>

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

    double GetContrastRatio(std::string color1, std::string color2)
    {
        double tone1 = LstarFromArgb(ArgbFromHex(color1));
        double tone2 = LstarFromArgb(ArgbFromHex(color2));
        double contrast_ratio = RatioOfTones(tone1, tone2);
        return contrast_ratio;
    }
} // namespace material_color_utilities
