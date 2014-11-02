
# Introduction

A simple exercise to create [LLL language
syntax](https://github.com/ethereum/cpp-ethereum/wiki/LLL-PoC-6) highligher GUI
application based on Qt library.

QtQuick is used to decompose the interface logic from the application logic,
though it must be further polished and enriched to cover all the use cases.

# Building

This examples comes with CMake files to build the project.  The project is
developed and tested under Ubuntu 14.04.  Though, there shouldn't be major
problems for building on other Linux distributions, MacOS and Windows as well,
though some minor twicks may be required.

Install Qt5 library and set the path

    export PATH=<Qt5 path>:$PATH

Then invoke the following commands:

    mkdir build && cd build
    cmake ..
    make

# Running

To run the application go to your build directory

    cd build
    ./highligher

# Notes

Possible refinement of the program is to separate the highlighting patterns
along with colouring scheme into a separate configuration file (based on json,
XML or other format).
