#include "BenchResult.h"
#include <gmp.h>
#include <gmpxx.h>

long BenchResult::getRunningMilliseconds() {
    return this->runningMilliseconds;
}

void BenchResult::setRunningMilliseconds(long runningMilliseconds) {
    this->runningMilliseconds = runningMilliseconds;
}

void BenchResult::setResult(char* t) {
    this->value = t;
}

char* BenchResult::result() {
    return this->value;
}