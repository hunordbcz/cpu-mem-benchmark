//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_PIAPPROXIMATION_H
#define SCS_TERMINAL_PIAPPROXIMATION_H


#include "Algorithm.h"

class PiApproximation : public Algorithm {
public:
    PiApproximation();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_PIAPPROXIMATION_H
