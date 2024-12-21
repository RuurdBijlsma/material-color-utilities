#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdint>
#include "cpp/utils/hex_utils.h"

namespace material_color_utilities {

// Helper function to convert a hex string to an integer
int ParseIntHex(const std::string& value) {
    int result;
    std::istringstream(value) >> std::hex >> result;
    return result;
}

Argb ArgbFromHex(std::string hex) {
    // Remove leading '#'
    if (!hex.empty() && hex[0] == '#') {
        hex = hex.substr(1);
    }

    // Determine the format (3, 6, or 8 characters)
    bool isThree = hex.length() == 3;
    bool isSix = hex.length() == 6;
    bool isEight = hex.length() == 8;

    if (!isThree && !isSix && !isEight) {
        throw std::invalid_argument("Unexpected hex " + hex);
    }

    int r = 0, g = 0, b = 0;

    if (isThree) {
        r = ParseIntHex(std::string(2, hex[0]));
        g = ParseIntHex(std::string(2, hex[1]));
        b = ParseIntHex(std::string(2, hex[2]));
    } else if (isSix) {
        r = ParseIntHex(hex.substr(0, 2));
        g = ParseIntHex(hex.substr(2, 2));
        b = ParseIntHex(hex.substr(4, 2));
    } else if (isEight) {
        r = ParseIntHex(hex.substr(2, 2));
        g = ParseIntHex(hex.substr(4, 2));
        b = ParseIntHex(hex.substr(6, 2));
    }

    return (255u << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

}  // namespace material_color_utilities
