# material_color_utilities API Documentation

## Functions

### `argb_from_hex(hex: str) -> int`
Converts a hex color code string to its ARGB representation.

- **Parameters**:
  - `hex`: A string representing the hex color code (e.g., `"#4285f4"`).

- **Returns**:
  - An integer representing the ARGB color value (e.g., `0xFF4285F4`).

---

### `hex_from_argb(argb: int) -> str`
Returns the hexadecimal representation of a color.

- **Parameters**:
  - `argb`: An integer representing the ARGB color value (e.g., `0xFF4285F4`).

- **Returns**:
  - A string representing the hex color code (e.g., `"#4285f4"`).

---

### `prominent_colors_from_image(image: PIL.Image.Image, max_colors: int = 128) -> list[str]`
Returns the prominent colors from a PIL image.

- **Parameters**:
  - `image`: PIL Image (this will be converted to RGBA and resized to fit in 128x128 by the package)
  - `max_colors`: An optional integer specifying the maximum number of colors to return (default is `128`).

- **Returns**:
  - A list of hex colors representing the prominent colors.

---

### `get_contrast_ratio(color1: str, color2: str) -> float`
Returns the contrast ratio of two colors.

- **Parameters**:
  - `color1`: The first hex color value (e.g., `#4285F4`).
  - `color2`: The second hex color value (e.g., `#FFFFFF`).

- **Returns**:
  - A float representing the contrast ratio between the two colors.

---

### `theme_from_color(source: str, contrast_level: float = 0.25, variant: Variant = Variant.VIBRANT, custom_colors: list[CustomColor] = []) -> Theme`
Returns a theme from a source color.

- **Parameters**:
  - `source`: A string representing the hex color code (e.g., `"#4285F4"`).
  - `contrast_level`: An optional float specifying the contrast level (default is `0.25`).
  - `variant`: An optional `Variant` specifying the color variant (default is `Variant.kVibrant`).
  - `custom_colors`: An optional list of `CustomColor` objects to apply (default is an empty list).

- **Returns**:
  - A `Theme` object representing the generated theme.

---

### `theme_from_image(image: PIL.Image.Image, contrast_level: float = 0.25, variant: Variant = Variant.kVibrant, custom_colors: list[CustomColor] = []) -> Theme`
Returns a theme from an image.

- **Parameters**:
  - `image`: A `PIL.Image.Image` object representing the image.
  - `contrast_level`: An optional integer specifying the contrast level (default is `3`).
  - `variant`: An optional `Variant` specifying the color variant (default is `Variant.kVibrant`).
  - `custom_colors`: An optional list of `CustomColor` objects to apply (default is an empty list).

- **Returns**:
  - A `Theme` object representing the generated theme.

## Classes

### `CustomColor`
Represents a custom color with an optional name and blend property.

- **Attributes**:
  - `value: str`: The hex value of the color.
  - `name: str`: The name of the color.
  - `blend: bool`: A boolean indicating whether the color should be blended.

---

### `Theme`
Represents a theme generated from a source color.

- **Attributes**:
  - `argb: int`: The source ARGB color value.
  - `source: hex`: The source color in hex format.
  - `schemes: DynamicSchemeGroup`: A list of dynamic schemes associated with the theme.
  - `contrast_level: float`: The contrast level of the theme.
  - `variant: Variant`: The color variant of the theme.
  - `custom_colors: list[CustomColorGroup]`: A list of custom colors applied to the theme.

---

### `Hct`
Represents a color in the HCT (Hue, Chroma, Tone) color model.

- **Attributes**:
  - `argb: int`: The ARGB representation of the color.
  - `hex: str`: The hex representation of the color.
  - `hue: float`: The hue of the color.
  - `chroma: float`: The chroma of the color.
  - `tone: float`: The tone of the color.

---

### `DynamicSchemeGroup`
Represents a group of dynamic color schemes.

- **Attributes**:
  - `light: DynamicScheme`: The light dynamic scheme.
  - `dark: DynamicScheme`: The dark dynamic scheme.

---

### `CustomColorGroup`
Represents a group of custom colors.

- **Attributes**:
  - `color: CustomColor`: The base color of the group.
  - `value: str`: The hex color of the group.
  - `light: ColorGroup`: The light variant of the custom color.
  - `dark: ColorGroup`: The dark variant of the custom color.

---

### `Variant`
An enum representing different color variants.

- **Values**:
  - `MONOCHROME`: Monochrome color variant.
  - `NEUTRAL`: Neutral color variant.
  - `TONALSPOT`: Tonal Spot color variant.
  - `VIBRANT`: Vibrant color variant.
  - `EXPRESSIVE`: Expressive color variant.
  - `FIDELITY`: Fidelity color variant.
  - `CONTENT`: Content color variant.
  - `RAINBOW`: Rainbow color variant.
  - `FRUITSALAD`: Fruit Salad color variant.

---

### `TonalPalette`
Represents a tonal color palette based on HCT values.

- **Attributes**:
  - `hue: float`: The hue of the color palette.
  - `chroma: float`: The chroma of the color palette.
  - `key_color: float`: The key color of the palette.
- **Methods**:
  - `get(tone: float) -> str`: Get a color from this palette at the specified tone.

---

### `DynamicScheme`
Represents a dynamic color scheme generated from a source color.

- **Attributes**:
  - `source_color_hct: Hct`: The source color in HCT format.
  - `variant: Variant`: The color variant of the scheme.
  - `is_dark: bool`: A boolean indicating whether the scheme is dark.
  - `contrast_level: float`: The contrast level of the scheme.
  - `primary_palette: TonalPalette`: The primary color palette.
  - `secondary_palette: TonalPalette`: The secondary color palette.
  - `tertiary_palette: TonalPalette`: The tertiary color palette.
  - `neutral_palette: TonalPalette`: The neutral color palette.
  - `error_palette: TonalPalette`: The error color palette.
  - `surface_container_low: str`: The low surface container color.
  - `surface_container: str`: The surface container color.
  - `surface_container_high: str`: The high surface container color.
  - `surface_container_highest: str`: The highest surface container color.
  - `on_surface: str`: The color for text/icons on the surface.
  - `surface_variant: str`: The surface variant color.
  - `on_surface_variant: str`: The color for text/icons on the surface variant.
  - `inverse_surface: str`: The inverse surface color.
  - `inverse_on_surface: str`: The color for text/icons on the inverse surface.
  - `outline: str`: The outline color.
  - `outline_variant: str`: The outline variant color.
  - `shadow: str`: The shadow color.
  - `scrim: str`: The scrim color.
  - `surface_tint: str`: The surface tint color.
  - `primary: str`: The primary color.
  - `on_primary: str`: The color for text/icons on primary color.
  - `primary_container: str`: The primary container color.
  - `on_primary_container: str`: The color for text/icons on the primary container.
  - `inverse_primary: str`: The inverse primary color.
  - `secondary: str`: The secondary color.
  - `on_secondary: str`: The color for text/icons on secondary color.
  - `secondary_container: str`: The secondary container color.
  - `on_secondary_container: str`: The color for text/icons on the secondary container.
  - `tertiary: str`: The tertiary color.
  - `on_tertiary: str`: The color for text/icons on tertiary color.
  - `tertiary_container: str`: The tertiary container color.
  - `on_tertiary_container: str`: The color for text/icons on the tertiary container.
  - `error: str`: The error color.
  - `on_error: str`: The color for text/icons on error color.
  - `error_container: str`: The error container color.
  - `on_error_container: str`: The color for text/icons on the error container.
  - `primary_fixed: str`: The fixed primary color.
  - `primary_fixed_dim: str`: The dimmed fixed primary color.
  - `on_primary_fixed: str`: The color for text/icons on the fixed primary color.
  - `on_primary_fixed_variant: str`: The color for text/icons on the fixed primary variant.
  - `secondary_fixed: str`: The fixed secondary color.
  - `secondary_fixed_dim: str`: The dimmed fixed secondary color.
  - `on_secondary_fixed: str`: The color for text/icons on the fixed secondary color.
  - `on_secondary_fixed_variant: str`: The color for text/icons on the fixed secondary variant.
  - `tertiary_fixed: str`: The fixed tertiary color.
  - `tertiary_fixed_dim: str`: The dimmed fixed tertiary color.
  - `on_tertiary_fixed: str`: The color for text/icons on the fixed tertiary color.
  - `on_tertiary_fixed_variant: str`: The color for text/icons on the fixed tertiary variant.
