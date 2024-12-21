cmake_minimum_required(VERSION 3.19)
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Static linking settings
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # For static libraries
set(BUILD_SHARED_LIBS
    OFF
    CACHE BOOL "Build static libraries" FORCE)

# Python bindings setup
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG QUIET)

# Abseil setup
add_subdirectory(abseil-cpp)

# Add all .cc files from src
file(GLOB_RECURSE CPP_SOURCES src/*.cc)

# Create the Pybind11 module
pybind11_add_module(_core MODULE ${CPP_SOURCES})

# Include directories
target_include_directories(_core PRIVATE src abseil-cpp)

# Link libraries
target_link_libraries(
  _core PRIVATE absl::base absl::strings absl::synchronization absl::hash
                absl::raw_hash_set)

# Pass versions
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

# Installation step
install(TARGETS _core LIBRARY DESTINATION ${SKBUILD_PROJECT_NAME})
