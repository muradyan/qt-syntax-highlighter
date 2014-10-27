
# Introduction

A simple [LLL language syntax](https://github.com/ethereum/cpp-ethereum/wiki/LLL-PoC-6) highligher GUI application based on Qt library.

The purpose of this exercise is by no means to create a production ready code.
This is a simple prototype/PoC which can be extended/improved along with the
language evolution and getting feedback from the designers on what/when/how
should be highlighted.

# Building

The project is developed and tested under Ubuntu 14.04.  There shouldn't be
major problems for building on other Linux distributions, Mac and Windows as
well, though some minor twicks may be required.

Prerequisites:

1. Install Qt5 library and set the path

    export PATH=<Qt5 path>:$PATH

    mkdir build && cd build
    cmake ..
    make

# Running

To run the application go to your build directory

    cd build
    ./highligher

# Notes

1. In real world application (for production, with richer UI) one would better
use Qt designer to separate the UI description into XML.  Since this example
project contains simple UI we keep things simple.

2. Another imporvement of this project is to use MVC in order to decompose the
business logic from the UI (make it more testable, maintainable, etc.).

3. When more rules are apparent it is worth to separate the patterns along with
colouring scheme into a separate configuration file (based on json, XML or
other format).
