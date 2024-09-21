cmake_minimum_required(VERSION 3.14)

project(CG)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Force x64 architecture, run "cmake .. -A x64"
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "This project can only be built on a 64-bit platform.")
endif()

set(DEPENDENCY_BUILD_FOLDER "${CMAKE_SOURCE_DIR}/dep")

# specify where to search for libraries 
link_directories(
    ${DEPENDENCY_BUILD_FOLDER}/GLFW_/lib
    ${DEPENDENCY_BUILD_FOLDER}/GLAD/bin
)
# specify where to search for a library headerfiles
include_directories(
    ${DEPENDENCY_BUILD_FOLDER}/GLFW_/include
    ${DEPENDENCY_BUILD_FOLDER}/GLAD/include
)

# Add the library
add_executable(CG src/main.cpp src/GpuLayer/GpuLayer.cpp src/GpuLayer/GpuLayer.h)

# link the needed libraries
target_link_libraries(${PROJECT_NAME}
    glfw3
    Glad
)