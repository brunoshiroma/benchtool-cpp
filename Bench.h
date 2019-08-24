//
// Created by jun on 23/08/2019.
//

#include "BenchResult.h"
#include <chrono>

#ifndef BENCHTOOL_CPP_BENCH_H
#define BENCHTOOL_CPP_BENCH_H
class Bench{
public:
    virtual BenchResult run(char** args);

    virtual BenchResult doBenchmark(char** args) = 0;
};
#endif //BENCHTOOL_CPP_BENCH_H

