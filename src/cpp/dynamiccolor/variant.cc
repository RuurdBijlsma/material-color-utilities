#include <string>
#include "variant.h"

namespace material_color_utilities
{

    std::string VariantToString(Variant variant)
    {
        switch (variant)
        {
        case Variant::kMonochrome:
            return "MONOCHROME";
        case Variant::kNeutral:
            return "NEUTRAL";
        case Variant::kTonalSpot:
            return "TONALSPOT";
        case Variant::kVibrant:
            return "VIBRANT";
        case Variant::kExpressive:
            return "EXPRESSIVE";
        case Variant::kFidelity:
            return "FIDELITY";
        case Variant::kContent:
            return "CONTENT";
        case Variant::kRainbow:
            return "RAINBOW";
        case Variant::kFruitSalad:
            return "FRUITSALAD";
        default:
            return "UNKNOWN";
        }
    }

} // namespace material_color_utilities
