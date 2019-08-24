cmake_minimum_required(VERSION 3.14)
project(benchtool_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
        )

find_package(GMP REQUIRED)

add_executable(benchtool_cpp Bench.h BenchResult.h main.cpp  BenchResult.cpp Bench.cpp SimpleFibonacciBench.h SimpleFibonacciBench.cpp SimpleLoopFibonacciBench.h SimpleLoopFibonacciBench.cpp)
target_link_libraries(benchtool_cpp gmp gmpxx)