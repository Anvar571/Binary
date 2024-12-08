cmake_minimum_required(VERSION 3.10)
project(vmachine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_executable(vmachine
    src/main.cpp
    src/data_detector.cpp
)

# Include directories
target_include_directories(vmachine PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)