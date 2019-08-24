//
// Created by jun on 24/08/2019.
//

#ifndef BENCHTOOL_CPP_SIMPLELOOPFIBONACCIBENCH_H
#define BENCHTOOL_CPP_SIMPLELOOPFIBONACCIBENCH_H
#include "Bench.h"
#include <gmp.h>
#include <gmpxx.h>
#include <stdlib.h>

class SimpleLoopFibonacciBench : public Bench{
public:
    BenchResult  doBenchmark(char **args);
};
#endif //BENCHTOOL_CPP_SIMPLELOOPFIBONACCIBENCH_H