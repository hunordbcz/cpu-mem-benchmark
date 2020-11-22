//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_DIGITOFPI_H
#define SCS_TERMINAL_DIGITOFPI_H


#include "Algorithm.h"

class DigitOfPi : public Algorithm {
public:
    DigitOfPi();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_DIGITOFPI_H
