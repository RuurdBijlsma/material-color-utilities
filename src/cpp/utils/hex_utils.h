#ifndef CPP_HEX_UTILS_H_
#define CPP_HEX_UTILS_H_

#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdint>
#include "cpp/utils/utils.h"

namespace material_color_utilities
{

    int ParseIntHex(const std::string &value);
    Argb ArgbFromHex(std::string hex);

} // namespace material_color_utilities

#endif // CPP_HEX_UTILS_H_
