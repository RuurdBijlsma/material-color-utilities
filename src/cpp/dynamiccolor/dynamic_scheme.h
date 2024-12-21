/*
 * Copyright 2023 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPP_DYNAMICCOLOR_DYNAMIC_SCHEME_H_
#define CPP_DYNAMICCOLOR_DYNAMIC_SCHEME_H_

#include <optional>
#include <vector>

#include "cpp/cam/hct.h"
#include "cpp/dynamiccolor/variant.h"
#include "cpp/palettes/tones.h"
#include "cpp/utils/utils.h"

namespace material_color_utilities
{

  struct DynamicScheme
  {
    Hct source_color_hct;
    Variant variant;
    bool is_dark;
    double contrast_level;

    TonalPalette primary_palette;
    TonalPalette secondary_palette;
    TonalPalette tertiary_palette;
    TonalPalette neutral_palette;
    TonalPalette neutral_variant_palette;
    TonalPalette error_palette;

    // Default constructor
    DynamicScheme()
        : source_color_hct(), variant(), is_dark(false), contrast_level(0.0),
          primary_palette(), secondary_palette(), tertiary_palette(),
          neutral_palette(), neutral_variant_palette(), error_palette() {}

    DynamicScheme(Hct source_color_hct, Variant variant, double contrast_level,
                  bool is_dark, TonalPalette primary_palette,
                  TonalPalette secondary_palette, TonalPalette tertiary_palette,
                  TonalPalette neutral_palette,
                  TonalPalette neutral_variant_palette,
                  std::optional<TonalPalette> error_palette = std::nullopt);

    static double GetRotatedHue(Hct source_color, std::vector<double> hues,
                                std::vector<double> rotations);

    std::string SourceColorHex() const;
    Argb SourceColorArgb() const;

    std::string HexPrimaryPaletteKeyColor() const;
    std::string HexSecondaryPaletteKeyColor() const;
    std::string HexTertiaryPaletteKeyColor() const;
    std::string HexNeutralPaletteKeyColor() const;
    std::string HexNeutralVariantPaletteKeyColor() const;
    std::string HexBackground() const;
    std::string HexOnBackground() const;
    std::string HexSurface() const;
    std::string HexSurfaceDim() const;
    std::string HexSurfaceBright() const;
    std::string HexSurfaceContainerLowest() const;
    std::string HexSurfaceContainerLow() const;
    std::string HexSurfaceContainer() const;
    std::string HexSurfaceContainerHigh() const;
    std::string HexSurfaceContainerHighest() const;
    std::string HexOnSurface() const;
    std::string HexSurfaceVariant() const;
    std::string HexOnSurfaceVariant() const;
    std::string HexInverseSurface() const;
    std::string HexInverseOnSurface() const;
    std::string HexOutline() const;
    std::string HexOutlineVariant() const;
    std::string HexShadow() const;
    std::string HexScrim() const;
    std::string HexSurfaceTint() const;
    std::string HexPrimary() const;
    std::string HexOnPrimary() const;
    std::string HexPrimaryContainer() const;
    std::string HexOnPrimaryContainer() const;
    std::string HexInversePrimary() const;
    std::string HexSecondary() const;
    std::string HexOnSecondary() const;
    std::string HexSecondaryContainer() const;
    std::string HexOnSecondaryContainer() const;
    std::string HexTertiary() const;
    std::string HexOnTertiary() const;
    std::string HexTertiaryContainer() const;
    std::string HexOnTertiaryContainer() const;
    std::string HexError() const;
    std::string HexOnError() const;
    std::string HexErrorContainer() const;
    std::string HexOnErrorContainer() const;
    std::string HexPrimaryFixed() const;
    std::string HexPrimaryFixedDim() const;
    std::string HexOnPrimaryFixed() const;
    std::string HexOnPrimaryFixedVariant() const;
    std::string HexSecondaryFixed() const;
    std::string HexSecondaryFixedDim() const;
    std::string HexOnSecondaryFixed() const;
    std::string HexOnSecondaryFixedVariant() const;
    std::string HexTertiaryFixed() const;
    std::string HexTertiaryFixedDim() const;
    std::string HexOnTertiaryFixed() const;
    std::string HexOnTertiaryFixedVariant() const;

    Argb GetPrimaryPaletteKeyColor() const;
    Argb GetSecondaryPaletteKeyColor() const;
    Argb GetTertiaryPaletteKeyColor() const;
    Argb GetNeutralPaletteKeyColor() const;
    Argb GetNeutralVariantPaletteKeyColor() const;
    Argb GetBackground() const;
    Argb GetOnBackground() const;
    Argb GetSurface() const;
    Argb GetSurfaceDim() const;
    Argb GetSurfaceBright() const;
    Argb GetSurfaceContainerLowest() const;
    Argb GetSurfaceContainerLow() const;
    Argb GetSurfaceContainer() const;
    Argb GetSurfaceContainerHigh() const;
    Argb GetSurfaceContainerHighest() const;
    Argb GetOnSurface() const;
    Argb GetSurfaceVariant() const;
    Argb GetOnSurfaceVariant() const;
    Argb GetInverseSurface() const;
    Argb GetInverseOnSurface() const;
    Argb GetOutline() const;
    Argb GetOutlineVariant() const;
    Argb GetShadow() const;
    Argb GetScrim() const;
    Argb GetSurfaceTint() const;
    Argb GetPrimary() const;
    Argb GetOnPrimary() const;
    Argb GetPrimaryContainer() const;
    Argb GetOnPrimaryContainer() const;
    Argb GetInversePrimary() const;
    Argb GetSecondary() const;
    Argb GetOnSecondary() const;
    Argb GetSecondaryContainer() const;
    Argb GetOnSecondaryContainer() const;
    Argb GetTertiary() const;
    Argb GetOnTertiary() const;
    Argb GetTertiaryContainer() const;
    Argb GetOnTertiaryContainer() const;
    Argb GetError() const;
    Argb GetOnError() const;
    Argb GetErrorContainer() const;
    Argb GetOnErrorContainer() const;
    Argb GetPrimaryFixed() const;
    Argb GetPrimaryFixedDim() const;
    Argb GetOnPrimaryFixed() const;
    Argb GetOnPrimaryFixedVariant() const;
    Argb GetSecondaryFixed() const;
    Argb GetSecondaryFixedDim() const;
    Argb GetOnSecondaryFixed() const;
    Argb GetOnSecondaryFixedVariant() const;
    Argb GetTertiaryFixed() const;
    Argb GetTertiaryFixedDim() const;
    Argb GetOnTertiaryFixed() const;
    Argb GetOnTertiaryFixedVariant() const;
  };

  DynamicScheme GetSchemeInstance(Variant variant, double constrastLevel, Hct sourceColorHct, bool isDark);

} // namespace material_color_utilities

#endif // CPP_DYNAMICCOLOR_DYNAMIC_SCHEME_H_
