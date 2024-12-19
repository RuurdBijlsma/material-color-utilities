#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cpp/utils/utils.h"
#include "cpp/utils/hex_utils.h"
#include "cpp/utils/theme_utils.h"
#include "cpp/pybindings/bindings.h"
#include <string>
namespace py = pybind11;

// TODO alle classes die gebind worden moeten default constructor hebben lijkt t
// Ik moet ook alle types in Theme nog binden (scheme, tonalpallette, etc. etc., repr zou ook wel nice zijn toch).
// snakecase instances in cpp weghalen, in bindings alleen snakecase hebben
// alle argb -> binded versions to hex conversion

PYBIND11_MODULE(_core, m)
{
  bind_theme(m);
  bind_dynamic_scheme(m);
  bind_tonal_palette(m);
  bind_custom_color(m);
  bind_custom_color_group(m);
  bind_variant(m);

  m.def("argb_from_hex", &material_color_utilities::ArgbFromHex);
  m.def("hex_from_argb", &material_color_utilities::HexFromArgb);
  m.def("theme_from_source_color", &material_color_utilities::ThemeFromSourceColor);
  m.def("source_color_from_image", &material_color_utilities::SourceColorFromImage);
}
