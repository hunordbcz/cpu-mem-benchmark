//
// Created by hunordbcz on 22.11.2020.
//

#ifndef SCS_TERMINAL_LIIDS_H
#define SCS_TERMINAL_LIIDS_H


#include "Algorithm.h"

class LIIDS : public Algorithm {
public:
    LIIDS();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_LIIDS_H
