#include <absl/types/optional.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "cpp/utils/theme_utils.h"
#include "cpp/blend/blend.h"
#include "cpp/scheme/scheme_vibrant.h"
#include "cpp/palettes/tones.h"
#include "cpp/utils/image_utils.h"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cpp/utils/color_utils.h>

namespace py = pybind11;

namespace material_color_utilities
{

    Theme ThemeFromArgbColor(Argb source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors)
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

    Theme ThemeFromColor(std::string source, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors)
    {
        return ThemeFromArgbColor(ArgbFromHex(source), contrastLevel, variant, customColors);
    }

    Theme ThemeFromImage(py::array_t<Argb> image, double contrastLevel, Variant variant, const std::vector<CustomColor> &customColors)
    {
        return ThemeFromArgbColor(ArgbSourceColorFromImage(image), contrastLevel, variant, customColors);
    }

} // namespace material_color_utilities
