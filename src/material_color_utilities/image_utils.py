import numpy as np
from PIL.Image import Image
from material_color_utilities._core import (
    prominent_colors_from_array,
    CustomColor,
    Theme,
    Variant,
)


def image_to_argb(img: Image) -> np.ndarray:
    # Convert the image to 128x128 RGBA
    img = img.convert("RGBA")
    img.thumbnail((128, 128))

    # Extract channels: Alpha, Red, Green, Blue
    rgba_array = np.array(img)
    alpha = rgba_array[:, :, 3].astype(np.uint32) << 24
    red = rgba_array[:, :, 0].astype(np.uint32) << 16
    green = rgba_array[:, :, 1].astype(np.uint32) << 8
    blue = rgba_array[:, :, 2].astype(np.uint32)

    # Combine into ARGB format
    return (alpha | red | green | blue).ravel()


def prominent_colors_from_image(img: Image, count: int = 64) -> list[int]:
    return prominent_colors_from_array(image_to_argb(img), count)


def _theme_from_image(
    img: Image,
    contrast: float = 3,
    variant: Variant = Variant.VIBRANT,
    custom_colors: list[CustomColor] = [],
) -> Theme:
    return Theme.from_array(image_to_argb(img), contrast, variant, custom_colors)


Theme.from_image = _theme_from_image
