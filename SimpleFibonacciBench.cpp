#include "SimpleFibonacciBench.h"

BenchResult SimpleFibonacciBench::doBenchmark(char **args) {

    mpz_t current, next;

    mpz_init_set_str(current, "0", 10);
    mpz_init_set_str(next, "1", 10);

    long maxInterations = atol(args[0]);

    mpz_t* calculateResult = calculateNext(current, next, maxInterations);

    BenchResult * result;

    result = new BenchResult();

    char* strResult = mpz_get_str(NULL, 10, *calculateResult);

    result->setResult(strResult);

    return *result;
}

mpz_t* SimpleFibonacciBench::calculateNext(mpz_t previous, mpz_t current, long maxInterations) {
    return this->calculateNext(previous, current, maxInterations, 1);
}

mpz_t* SimpleFibonacciBench::calculateNext(mpz_t previous, mpz_t current, long maxInterations,
                                             long currentInteration) {
    ++currentInteration;

    mpz_t result;
    mpz_init(result);

    mpz_add(result, previous, current);

    if(currentInteration == maxInterations){
        mpz_t * returnResult;
        returnResult = &result;
        return returnResult;
    }
    else{
        return calculateNext(current, result, maxInterations, currentInteration);
    }
}