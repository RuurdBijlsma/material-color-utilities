#ifndef CPP_HEX_UTILS_H_
#define CPP_HEX_UTILS_H_

#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdint>
#include "cpp/utils/utils.h"

namespace material_color_utilities {

// Helper function to convert a hex string to an integer
int ParseIntHex(const std::string &value);

/**
 * Converts a hex color code string to its ARGB representation.
 * @param hex String representing color as hex code. Accepts strings with or
 *     without leading #, and string representing the color using 3, 6, or 8
 *     hex characters.
 * @return ARGB representation of the color as a 32-bit unsigned integer.
 */
Argb ArgbFromHex(std::string hex);

}  // namespace material_color_utilities

#endif // CPP_HEX_UTILS_H_