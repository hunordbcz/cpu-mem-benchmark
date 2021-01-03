//
// Created by hdebreczeni on 21.11.2020.
//

#ifndef SCS_TERMINAL_GREATESTCOMMONDIVISOR_H
#define SCS_TERMINAL_GREATESTCOMMONDIVISOR_H


#include "Algorithm.h"

class GreatestCommonDivisor : public Algorithm {
public:
    GreatestCommonDivisor();

protected:
    int runCode(int size) override;
};


#endif //SCS_TERMINAL_GREATESTCOMMONDIVISOR_H
