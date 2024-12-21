from pathlib import Path

import PIL.Image
import pytest
from ruurd_colors import (
    argb_from_hex,
    hex_from_argb,
    prominent_colors_from_image,
    get_contrast_ratio,
    CustomColor,
    Theme,
    Variant,
)


def test_argb_from_hex():
    assert argb_from_hex("#4285f4") == 0xFF4285F4
    assert argb_from_hex("#000000") == 0xFF000000
    assert argb_from_hex("#ffffff") == 0xFFFFFFFF


def test_hex_from_argb():
    assert hex_from_argb(0xFF4285F4) == "#4285f4"
    assert hex_from_argb(0xFF000000) == "#000000"
    assert hex_from_argb(0xFFFFFFFF) == "#ffffff"


def test_theme_from_source_color():
    custom_colors = [CustomColor(0xFF4285F4, "Google Blue", True)]
    theme = Theme.from_source_color(0xFFFC03A3, 3.0, Variant.MONOCHROME, custom_colors)
    assert isinstance(theme, Theme)
    assert theme.source == 0xFFFC03A3


def test_theme_from_image(assets_folder: Path):
    image = PIL.Image.open(assets_folder / "test.jpg")
    custom_colors = [CustomColor(0xFF4285F4, "Google Blue", True)]
    theme = Theme.from_image(image, 4.0, Variant.EXPRESSIVE, custom_colors)
    assert isinstance(theme, Theme)


def test_prominent_colors_from_image(assets_folder: Path):
    image = PIL.Image.open(assets_folder / "test.jpg")
    colors = prominent_colors_from_image(image, 5)
    assert isinstance(colors, list)
    assert len(colors) <= 5


def test_get_contrast_ratio():
    color1 = 0xFF000000
    color2 = 0xFFFFFFFF
    ratio = get_contrast_ratio(color1, color2)
    assert ratio == pytest.approx(21.0, rel=1e-2)
