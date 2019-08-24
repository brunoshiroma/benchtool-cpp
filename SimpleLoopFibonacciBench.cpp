//
// Created by jun on 24/08/2019.
//
#include "SimpleLoopFibonacciBench.h"

BenchResult SimpleLoopFibonacciBench::doBenchmark(char **args) {

    mpz_t current, next, resultSum;

    mpz_init_set_str(current, "0", 10);
    mpz_init_set_str(next, "1", 10);
    mpz_init_set_str(resultSum, "0", 10);

    long maxInterations = atol(args[0]);

    for(int i = 1; i < maxInterations; i++){

        mpz_add(resultSum, current, next);
        mpz_set(current, next);
        mpz_set(next, resultSum);
    }

    BenchResult * result;

    result = new BenchResult();

    char* strResult = mpz_get_str(NULL, 10, resultSum);
    unsigned long l = mpz_get_ui(resultSum);

    result->setResult(strResult);

    return *result;

}
