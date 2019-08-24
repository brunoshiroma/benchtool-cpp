cmake_minimum_required(VERSION 3.12)
project(benchtool_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
        )

find_package(GMP REQUIRED)
add_executable(benchtool_cpp Bench.h BenchResult.h main.cpp  BenchResult.cpp Bench.cpp SimpleFibonacciBench.h SimpleFibonacciBench.cpp SimpleLoopFibonacciBench.h SimpleLoopFibonacciBench.cpp)
target_link_libraries(benchtool_cpp gmp gmpxx)

#check linux
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    set_target_properties(
            benchtool_cpp
            PROPERTIES
            OUTPUT_NAME "benchtool_cpp"
            PREFIX "linux_"
            SUFFIX ""
    )

    elseif(APPLE)
    set_target_properties(
            benchtool_cpp
            PROPERTIES
            OUTPUT_NAME "benchtool_cpp"
            PREFIX "macos_"
            SUFFIX ""
    )
    else(WIN32 OR MINGW OR MSYS OR CYGWIN)
    set_target_properties(
            benchtool_cpp
            PROPERTIES
            OUTPUT_NAME "benchtool_cpp"
            PREFIX "win_"
            SUFFIX ".exe"
    )
endif()


