#include <cpp/utils/util_types.h>

namespace material_color_utilities
{
    std::string Theme::GetHexSource() const
    {
        return RgbHexFromArgb(source);
    }
}
