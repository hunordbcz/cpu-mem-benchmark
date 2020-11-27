//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_LUCASLEHMER_H
#define SCS_TERMINAL_LUCASLEHMER_H


#include "Algorithm.h"

class LucasLehmer : public Algorithm {
public:
    LucasLehmer();

    void runTest() override;

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_LUCASLEHMER_H
