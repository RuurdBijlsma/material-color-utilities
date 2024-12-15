cmake_minimum_required(VERSION 3.15)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

# Ensure position-independent code for static libraries
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Force static linking for Abseil
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

# Abseil
set(ABSL_BUILD_SHARED OFF CACHE BOOL "" FORCE)
add_subdirectory(abseil-cpp)

# Add all .cc files from src/cpp
file(GLOB_RECURSE CPP_SOURCES src/cpp/*.cc)

# Create the Pybind11 module
pybind11_add_module(_core MODULE src/main.cc ${CPP_SOURCES})

# Make #includes discoverable
target_include_directories(_core PRIVATE src)

# Link the module to Abseil statically
target_link_libraries(_core PRIVATE absl::base absl::strings absl::synchronization)

install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
