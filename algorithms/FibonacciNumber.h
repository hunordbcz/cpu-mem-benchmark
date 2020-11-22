//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_FIBONACCINUMBER_H
#define SCS_TERMINAL_FIBONACCINUMBER_H


#include "Algorithm.h"

class FibonacciNumber : public Algorithm {
public:
    FibonacciNumber();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_FIBONACCINUMBER_H
