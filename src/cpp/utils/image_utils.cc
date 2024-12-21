#include <cpp/utils/image_utils.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <cpp/utils/utils.h>

namespace py = pybind11;

namespace material_color_utilities
{
    void Process2DArray(py::array_t<Argb> input_array)
    {
        // Request a buffer info object from the array
        py::buffer_info buf_info = input_array.request();

        // Check that the array is 2D
        if (buf_info.ndim != 2)
        {
            throw std::runtime_error("Input array must be 2D.");
        }

        // Extract dimensions
        size_t rows = buf_info.shape[0];
        size_t cols = buf_info.shape[1];

        // Access the raw data as a pointer
        Argb *data_ptr = static_cast<Argb *>(buf_info.ptr);

        // Print the array dimensions
        std::cout << "Received a 2D array of size " << rows << "x" << cols << ":\n";

        // Iterate over the elements (row-major order)
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                // Access element at (i, j): offset = i * cols + j
                std::cout << data_ptr[i * cols + j] << " ";
            }
            std::cout << "\n";
        }
    }
} // namespace material_color_utilities