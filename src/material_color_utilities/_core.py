from __future__ import annotations
from enum import StrEnum
from typing import Any

import numpy as np


class Theme:
    argb: int
    source: int | None
    schemes: DynamicSchemeGroup
    contrast_level: float | None
    variant: Variant
    custom_colors: CustomColorGroup | None

    def __init__(self) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class Hct:
    """The HCT (Hue-Chroma-Tone) color space is a cylindrical color space that is based on the Munsell color system.
    It is used to represent colors in a way that is more intuitive to humans.

    More info:
        https://github.com/material-foundation/material-color-utilities/blob/main/concepts/color_spaces.md
    """

    argb: int | None
    hex: str | None
    hue: float
    chroma: float
    tone: float

    def __init__(self) -> None: ...

    def __init__(self, argb: int) -> None: ...

    def __init__(self, hex: str) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class DynamicSchemeGroup:
    light: DynamicScheme
    dark: DynamicScheme

    def __init__(self) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class DynamicScheme:
    """The Dynamic Scheme comprises color attributes that are combined in a predetermined way to meet the needs
    of a user context or preference. It is essentially a mapping of color roles to color at specific tone in a
    tonal palette. For example, primary = 207H 80C 90T, onPrimary = 207H 80C 40T.

    More info:
    1. https://github.com/material-foundation/material-color-utilities/blob/main/concepts/dynamic_color_scheme.md
    2. https://github.com/material-foundation/material-color-utilities/blob/main/concepts/scheme_generation.md
    """

    source_color_hct: Hct
    variant: Variant
    is_dark: bool
    contrast_level: float
    primary_palette: TonalPalette
    secondary_palette: TonalPalette
    tertiary_palette: TonalPalette
    neutral_palette: TonalPalette
    neutral_variant_palette: TonalPalette
    error_palette: TonalPalette

    surface_container_low: str
    surface_container: str
    surface_container_high: str
    surface_container_highest: str
    on_surface: str
    surface_variant: str
    on_surface_variant: str
    inverse_surface: str
    inverse_on_surface: str
    outline: str
    outline_variant: str
    shadow: str
    scrim: str
    surface_tint: str
    primary: str
    on_primary: str
    primary_container: str
    on_primary_container: str
    inverse_primary: str
    secondary: str
    on_secondary: str
    secondary_container: str
    on_secondary_container: str
    tertiary: str
    on_tertiary: str
    tertiary_container: str
    on_tertiary_container: str
    error: str
    on_error: str
    error_container: str
    on_error_container: str
    primary_fixed: str
    primary_fixed_dim: str
    on_primary_fixed: str
    on_primary_fixed_variant: str
    secondary_fixed: str
    secondary_fixed_dim: str
    on_secondary_fixed: str
    on_secondary_fixed_variant: str
    tertiary_fixed: str
    tertiary_fixed_dim: str
    on_tertiary_fixed: str
    on_tertiary_fixed_variant: str

    def __init__(self) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...

    @staticmethod
    def get_rotated_hue(
        source_color: int, hues: list[float], rotations: list[float]
    ) -> float: ...


class TonalPalette:
    """A set of colors that share hue and chroma in HCT color space and vary in tones.

    From a perception perspective, we can say that they are "tones of the same color".
    MCU produces 6 tonal palettes: primary, secondary, tertiary, neutral, neutral variant, and error.
    Each comprises tones ranging from 0 to 100 that serves as the basis for mapping specific tones to specific roles.
    """

    hue: float
    chroma: float
    key_color: Hct | None

    def __init__(self) -> None: ...

    def __init__(self, argb: int) -> None: ...

    def __init__(self, hct: Hct) -> None: ...

    def __init__(self, hue: float, chroma: float) -> None: ...

    def __init__(self, hue: float, chroma: float, key_color: Hct) -> None: ...

    def get(self, tone: float) -> str: ...

    def get_argb(self, tone: float) -> int: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class CustomColor:
    value_argb: int
    value: str
    name: str
    blend: bool

    def __init__(self) -> None: ...

    def __init__(self, value: int, name: str, blend: bool) -> None: ...

    def __init__(self, value: str, name: str, blend: bool) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class CustomColorGroup:
    color: CustomColor
    value_argb: int
    value: str
    light: CustomColor
    dark: CustomColor

    def __init__(self) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class ColorGroup:
    color_argb: int
    on_color_argb: int
    color_container_argb: int
    on_color_container_argb: int
    color: str
    on_color: str
    color_container: str
    on_color_container: str

    def __init__(self) -> None: ...

    def dict(self) -> dict[str, Any]: ...

    def __repr__(self) -> str: ...


class Variant(StrEnum):
    """Each variant is a set of design decisions on the assignment of color values from tonal palettes to color roles."""

    MONOCHROME: str
    NEUTRAL: str
    TONALSPOT: str
    VIBRANT: str
    EXPRESSIVE: str
    FIDELITY: str
    CONTENT: str
    RAINBOW: str
    FRUITSALAD: str


def argb_from_hex(hex: str) -> int:
    """Converts a hex color code string to its ARGB representation.

    Args:
        hex: A hex color code string.

    Returns:
        The ARGB representation of the color.
    """
    ...


def hex_from_argb(argb: int) -> str:
    """Returns the hexadecimal representation of a color.

    Args:
        argb: The ARGB color value.

    Returns:
        The hexadecimal representation of the color.
    """
    ...


def prominent_colors_from_array(image: np.ndarray, max_colors: int = 64) -> list[str]:
    """Returns the prominent hex colors from an image in the shape of a 2D array.

    More info:
        https://github.com/material-foundation/material-color-utilities/blob/main/concepts/color_extraction.md

    Args:
        image: A 1D array of ARGB values representing the image.
        max_colors: The maximum number of prominent colors to return (default is 64).

    Returns:
        A list of colors in hex format.
    """
    ...


def prominent_colors_from_array_argb(
    image: np.ndarray, max_colors: int = 64
) -> list[int]:
    """Returns the prominent ARGB colors from an image in the shape of a 1D array.

    Args:
        image: A 1D array of ARGB values representing the image.
        max_colors: The maximum number of prominent colors to return (default is 64).

    Returns:
        A list of colors in ARGB format.
    """
    ...


def get_contrast_ratio(color1: str, color2: str) -> float:
    """Returns the contrast ratio of two colors.

    How to use contrast for accessibility:
        https://github.com/material-foundation/material-color-utilities/blob/main/concepts/contrast_for_accessibility.md

    Args:
        color1: The hex value of the first color.
        color2: The hex value of the second color.

    Returns:
        The contrast ratio between the two colors.
    """
    ...


def theme_from_color(
    source: str,
    contrast_level: int = 3,
    variant: Variant = Variant.VIBRANT,
    custom_colors: list[CustomColor] | None = None,
) -> Theme:
    """Returns a theme from a source color.

    Args:
        source: The hex value of the source color.
        contrast_level: The contrast level (default is 3).
        variant: The variant type (default is 0).
        custom_colors: A list of custom colors (default is an empty list).

    Returns:
        A theme object
    """
    ...


def theme_from_argb_color(
    source: int,
    contrast_level: int = 3,
    variant: Variant = Variant.VIBRANT,
    custom_colors: list[CustomColor] | None = None,
) -> Theme:
    """Returns a theme from a source ARGB color.

    Args:
        source: The ARGB value of the source color.
        contrast_level: The contrast level (default is 3).
        variant: The variant type (default is 0).
        custom_colors: A list of custom colors (default is an empty list).

    Returns:
        A theme object
    """
    ...


def theme_from_array(
    image: np.ndarray,
    contrast_level: int = 3,
    variant: Variant = Variant.VIBRANT,
    custom_colors: list[CustomColor] | None = None,
) -> Theme:
    """Returns a theme from an image.

    Args:
        image: A 1D array of ARGB values representing the image.
        contrast_level: The contrast level (default is 3).
        variant: The variant type (default is 0).
        custom_colors: A list of custom colors (default is an empty list).

    Returns:
        A theme object
    """
    ...
