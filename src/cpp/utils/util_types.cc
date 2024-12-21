#include <cpp/utils/util_types.h>

namespace material_color_utilities
{
    std::string Theme::GetHexSource() const
    {
        return RgbHexFromArgb(source);
    }

    std::string CustomColor::GetHexValue() const
    {
        return RgbHexFromArgb(value);
    }

    std::string CustomColorGroup::GetHexValue() const
    {
        return RgbHexFromArgb(value);
    }

    std::string ColorGroup::GetHexColor() const
    {
        return RgbHexFromArgb(color);
    }

    std::string ColorGroup::GetHexOnColor() const
    {
        return RgbHexFromArgb(onColor);
    }

    std::string ColorGroup::GetHexColorContainer() const
    {
        return RgbHexFromArgb(colorContainer);
    }

    std::string ColorGroup::GetHexOnColorContainer() const
    {
        return RgbHexFromArgb(onColorContainer);
    }
}
