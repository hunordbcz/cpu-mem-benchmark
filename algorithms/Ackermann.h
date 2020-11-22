//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_ACKERMANN_H
#define SCS_TERMINAL_ACKERMANN_H


#include "Algorithm.h"

class Ackermann : public Algorithm {
public:
    Ackermann();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_ACKERMANN_H
