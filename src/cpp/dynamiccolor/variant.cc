#include "variant.h"
#include <string>

namespace material_color_utilities {

std::string VariantToString(Variant variant) {
    switch (variant) {
        case Variant::kMonochrome: return "kMonochrome";
        case Variant::kNeutral: return "kNeutral";
        case Variant::kTonalSpot: return "kTonalSpot";
        case Variant::kVibrant: return "kVibrant";
        case Variant::kExpressive: return "kExpressive";
        case Variant::kFidelity: return "kFidelity";
        case Variant::kContent: return "kContent";
        case Variant::kRainbow: return "kRainbow";
        case Variant::kFruitSalad: return "kFruitSalad";
        default: return "Unknown";
    }
}

}  // namespace material_color_utilities