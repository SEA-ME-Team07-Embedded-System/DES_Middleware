cmake_minimum_required(VERSION 3.10)
project(PiracerInterface)

# Find the Python3 libraries
find_package(Python3 COMPONENTS Development)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(PiracerInterface main.cpp PiracerClass.cpp GamePad.cpp)

# Link Python libraries
target_link_libraries(PiracerInterface Python3::Python pthread)

