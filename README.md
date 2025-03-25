# Material Color Utilities

Material Color Utilities is a Python package for working with Material Design color systems. This package includes
utilities for generating themes from colors or images, extracting prominent colors from images, converting colors, and
calculating contrast ratios.

<video autoplay muted loop src="https://user-images.githubusercontent.com/6655696/146014425-8e8e04bc-e646-4cc2-a3e7-97497a3e1b09.mp4" data-canonical-src="https://user-images.githubusercontent.com/6655696/146014425-8e8e04bc-e646-4cc2-a3e7-97497a3e1b09.mp4" class="d-block rounded-bottom-2 width-fit" style="max-width:640px;"></video>

---

## Installation

Install the package directly from pip:

```bash
pip install material-color-utilities
```

---

## Features

- **Theming**
    - Generate Material Design themes from source colors or images.
- **Image Processing**
    - Extract prominent colors from images.
- **Contrast Ratio**
    - Calculate contrast ratios between colors.

---

## Usage

Complete API documentation here: [API docs](https://github.com/RuurdBijlsma/material-color-utilities/blob/main/docs/api.md).

### Importing the Library

```python
from material_color_utilities import (
    CustomColor,
    Variant,
    argb_from_hex,
    hex_from_argb,
    prominent_colors_from_image,
    theme_from_color,
    theme_from_image,
    get_contrast_ratio
)
```

### Generate a Theme

#### From a Source Color

```python
theme = theme_from_color("#FC03A3", 3.0, Variant.EXPRESSIVE)
# now apply the theme somewhere
# Example, assuming dark theme:
button.color = theme.schemes.dark.primary
button.text_color = theme.schemes.dark.on_primary
background.color = theme.schemes.dark.surface_container
text_paragraph.color = theme.schemes.dark.on_surface
```

#### From an Image

This package will handle converting to RGBA and resizing for performance, so any PIL image can be passed.

```python
from PIL import Image

image = Image.open("path/to/image.jpg")
# You can *optionally* pass a list of custom colors to generate palettes that harmonize with the source color.
custom_colors = [CustomColor("#4285F4", "Google Blue", True)]
theme = theme_from_image(image, 4.0, Variant.CONTENT, custom_colors)
```

#### Theme to dict

A `Theme` object can be converted to a dict, an example theme dict can be found [here](https://github.com/RuurdBijlsma/material-color-utilities/blob/main/docs/theme_dict_example.py).

```python
theme = theme_from_color("#FF0000")
theme_dict = theme.dict()
```

### Extract Prominent Colors from an Image

This package will handle converting to RGBA and resizing for performance, so any PIL image can be passed.

```python
from PIL import Image

image = Image.open("path/to/image.jpg")
colors = prominent_colors_from_image(image, 5)
print(colors)  # Outputs a list of up to 5 prominent colors
```

### Calculate Contrast Ratio

```python
ratio = get_contrast_ratio("#000000", "#FFFFFF")
print(ratio)  # Outputs: 21.0
```

### Convert Colors

#### ARGB from HEX

```python
argb = argb_from_hex("#4285f4")
print(argb)  # Outputs: 4286017588 (0xFF4285F4)
```

#### HEX from ARGB

```python
hex_color = hex_from_argb(0xFF4285F4)
print(hex_color)  # Outputs: "#4285f4"
```

---

## Testing

To run the tests, install `uv`, and execute:

```bash
uv sync --dev # install packages
uv run pytest tests
```

---

## License

This project is "forked" from [material-foundation/material-color-utilities/](https://github.com/material-foundation/material-color-utilities).

This project is licensed under the Apache License 2.0. See the [LICENSE](https://github.com/RuurdBijlsma/material-color-utilities/blob/main/LICENSE) file for details.

---

## Links

- **PyPI:** [https://pypi.org/project/material-color-utilities](https://pypi.org/project/material-color-utilities/)
- Original C++ source: [https://github.com/material-foundation/material-color-utilities](https://github.com/material-foundation/material-color-utilities)
- **Material Design Guidelines:** [https://material.io/design](https://material.io/design)

## How to publish a release

* Push to main
* Create release on GitHub
* Wait 30 minutes
