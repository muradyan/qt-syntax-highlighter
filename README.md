
# Introduction

A simple syntax highligher GUI application based on Qt library.

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
