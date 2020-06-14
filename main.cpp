#include <iostream>
#include <chrono>
#include "SimpleFibonacciBench.h"
#include "SimpleLoopFibonacciBench.h"
#include <stdlib.h>
#include <sys/resource.h>

enum bench_type{
    recursive = 2,
    loop = 1
};

int main(int argc, char **argv) {

    Bench *bench = NULL;
    bench_type type = loop;
    char* number = "99999";

    if(argc >= 2){
        char* benchType = argv[1];
        type = static_cast<bench_type>(atol(benchType));
    }
    if(argc >= 3){
        number = argv[2];
    }

    switch(type){
        case recursive:{
            //need to change stack size...
            rlim_t kStackSize = 16 * std::stoi(number);
            struct rlimit rl;

            rl.rlim_cur = kStackSize;

            setrlimit(RLIMIT_STACK, &rl);
            bench = new SimpleFibonacciBench();
        }
            break;
        case loop:{
            bench = new SimpleLoopFibonacciBench();
        }
            break;
    }



    auto result = bench->run(&number);

    std::cout << result.getRunningMilliseconds() << " " << result.result() <<  "\n";

    return 0;
}
