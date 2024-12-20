from __future__ import annotations
from enum import Enum

class Variant(Enum): ...
class Theme: ...
class CustomColor: ...

def argb_from_hex(hex: str) -> int: ...
def hex_from_argb(argb: int) -> str: ...

def theme_from_source_color(
    source: int,
    contrast_level: float,
    variant: Variant,
    custom_colors: list[CustomColor],
) -> Theme: ...
def source_color_from_image(image: str) -> int: ...
