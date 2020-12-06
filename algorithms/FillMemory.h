//
// Created by hunordbcz on 07.12.2020.
//

#ifndef SCS_TERMINAL_FILLMEMORY_H
#define SCS_TERMINAL_FILLMEMORY_H


#include "MemoryAlgorithm.h"

class FillMemory : public MemoryAlgorithm{
public:
    FillMemory();

protected:
    void runCode(int size) override;
};


#endif //SCS_TERMINAL_FILLMEMORY_H
