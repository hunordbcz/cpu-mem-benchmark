//
// Created by hunordbcz on 07.12.2020.
//

#ifndef SCS_TERMINAL_NORMALACCESSMEMORY_H
#define SCS_TERMINAL_NORMALACCESSMEMORY_H


#include "Algorithm.h"
#include "MemoryAlgorithm.h"

class NormalAccessMemory : public MemoryAlgorithm{
public:
    NormalAccessMemory();

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_NORMALACCESSMEMORY_H
