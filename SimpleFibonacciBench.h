//
// Created by jun on 23/08/2019.
//

#ifndef BENCHTOOL_CPP_SIMPLEFIBONACCIBENCH_H
#define BENCHTOOL_CPP_SIMPLEFIBONACCIBENCH_H
#include "Bench.h"
#include <gmp.h>
#include <gmpxx.h>
#include <stdlib.h>

class SimpleFibonacciBench : public Bench{
public:
    BenchResult  doBenchmark(char **args);

private:
    mpz_t* calculateNext(mpz_t previous, mpz_t current, long maxInterations);

    mpz_t* calculateNext(mpz_t previous, mpz_t current, long maxInterations, long currentInteration);
};
#endif //BENCHTOOL_CPP_SIMPLEFIBONACCIBENCH_H