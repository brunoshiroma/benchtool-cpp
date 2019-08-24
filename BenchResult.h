//
// Created by jun on 23/08/2019.
//

#ifndef BENCHTOOL_CPP_BENCHRESULT_H
#define BENCHTOOL_CPP_BENCHRESULT_H
using namespace std;

class BenchResult{
public:
    char* result();
    long getRunningMilliseconds();
    void setRunningMilliseconds(long runningMilliseconds);
    void setResult(char* t);

protected:
    char* value;
    long runningMilliseconds;
};
#endif //BENCHTOOL_CPP_BENCHRESULT_H

