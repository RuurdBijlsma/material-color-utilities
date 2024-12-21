#include <cpp/utils/image_utils.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <cpp/utils/utils.h>
#include <cpp/quantize/celebi.h>
#include <cpp/score/score.h>

namespace py = pybind11;

namespace material_color_utilities
{
    std::vector<Argb> ProminentColorsFromImage(py::array_t<Argb> image, size_t max_colors)
    {
        // Request a buffer info object from the array
        py::buffer_info buf_info = image.request();
        if (buf_info.ndim != 1)
        {
            throw std::runtime_error("Input array must be 1D.");
        }

        Argb *data_ptr = static_cast<Argb *>(buf_info.ptr);
        size_t size = buf_info.shape[0];
        std::vector<Argb> vec(data_ptr, data_ptr + size);

        QuantizerResult a = QuantizeCelebi(vec, max_colors);
        std::vector<Argb> colors = RankedSuggestions(a.color_to_count);
        return colors;
    }

    Argb SourceColorFromImage(py::array_t<Argb> image)
    {
        auto prominent_colors = ProminentColorsFromImage(image);
        return prominent_colors[0];
    }
} // namespace material_color_utilities
