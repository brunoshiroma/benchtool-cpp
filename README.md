# Benchtool - C++
[![Build Status](https://travis-ci.org/brunoshiroma/benchtool-cpp.svg?branch=master)](https://travis-ci.org/brunoshiroma/benchtool-cpp)

Simple benchmark, using:
 * C++17 (maybe compatible with older version)
 * GMP ( GNU Multiple Precision Arithmetic Library )

Calculates N elements of fibonacci

## devcontainer
Uses ubuntu 2204 and libgmp-dev

## build
```bash
# with libgmp-dev installed or using the devcontainer in vs code
cmake .
make
#running
./linux_benchtool_cpp 1 100 5
```