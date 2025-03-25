from pathlib import Path

import PIL.Image
import pytest

from material_color_utilities import (
    CustomColor,
    Theme,
    Variant,
    argb_from_hex,
    get_contrast_ratio,
    hex_from_argb,
    prominent_colors_from_image,
    theme_from_color,
    theme_from_image,
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
    custom_colors = [CustomColor("#4285F4", "Google Blue", True)]
    theme = theme_from_color("#FC03A3", 0.15, Variant.VIBRANT, custom_colors)
    assert isinstance(theme, Theme)
    assert theme.source == "#fc03a3"
    assert theme.schemes.light.primary == "#9f0065"


def test_theme_from_image(assets_folder: Path):
    image = PIL.Image.open(assets_folder / "test.jpg")
    custom_colors = [CustomColor("#4285F4", "Google Blue", True)]
    theme = theme_from_image(image, 0.5, Variant.CONTENT, custom_colors)
    assert isinstance(theme, Theme)


def test_prominent_colors_from_image(assets_folder: Path):
    image = PIL.Image.open(assets_folder / "test.jpg")
    colors = prominent_colors_from_image(image, 5)
    assert isinstance(colors, list)
    assert len(colors) <= 5


def test_get_contrast_ratio():
    color1 = "#000000"
    color2 = "#FFFFFF"
    ratio = get_contrast_ratio(color1, color2)
    assert ratio == pytest.approx(21.0, rel=1e-2)


def test_dict():
    custom_colors = [CustomColor("#4285F4", "Google Blue", True)]
    theme = theme_from_color("#FC03A3", 8, Variant.VIBRANT, custom_colors)
    theme_dict = theme.dict()
    assert isinstance(theme_dict, dict)
