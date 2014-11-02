
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

# Find the required libraries
find_package(Qt5 COMPONENTS Quick)

aux_source_directory(${CMAKE_SOURCE_DIR}/src highlighter_sources)
file(GLOB highlighter_resources src/*.qrc)
qt5_add_resources(highlighter_resources_rcc ${highlighter_resources})

# Tell CMake to create the helloworld executable
add_executable(highligher ${highlighter_sources} ${highlighter_resources_rcc})

qt5_use_modules(highligher Quick)
