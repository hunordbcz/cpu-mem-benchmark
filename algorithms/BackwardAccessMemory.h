//
// Created by hunordbcz on 07.12.2020.
//

#ifndef SCS_TERMINAL_BACKWARDACCESSMEMORY_H
#define SCS_TERMINAL_BACKWARDACCESSMEMORY_H


#include "MemoryAlgorithm.h"

class BackwardAccessMemory : public MemoryAlgorithm {
public:
    BackwardAccessMemory();

protected:
    int runCode(int size) override;
};


#endif //SCS_TERMINAL_BACKWARDACCESSMEMORY_H
