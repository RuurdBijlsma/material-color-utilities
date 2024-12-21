#ifndef CPP_COLOR_UTILS_H_
#define CPP_COLOR_UTILS_H_

#include "cpp/utils/utils.h"
#include <cpp/utils/util_types.h>

namespace material_color_utilities {

    CustomColorGroup GetCustomColor(Argb source, const CustomColor &color);
    double GetContrastRatio(std::string color1, std::string color2);

}  // namespace material_color_utilities

#endif // CPP_COLOR_UTILS_H_
