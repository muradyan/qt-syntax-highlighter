
cmake_minimum_required(VERSION 2.8.11)

project(SyntaxHighlighter)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(NOT COMPILER_SUPPORTS_CXX11)
    message (FATAL_ERROR "C++11 compiler support is required")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find the QtWidgets library
find_package(Qt5Widgets)

aux_source_directory(src highlighter_sources)

# Tell CMake to create the helloworld executable
add_executable(highligher ${highlighter_sources})

# Use the Widgets module from Qt 5.
target_link_libraries(highligher Qt5::Widgets)
