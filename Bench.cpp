#include "Bench.h"

BenchResult Bench::run(char **args) {
    auto started = std::chrono::high_resolution_clock::now();
    BenchResult result = this->doBenchmark(args);
    auto done = std::chrono::high_resolution_clock::now();

    result.setRunningMilliseconds(std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count());

    return result;
}
