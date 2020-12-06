//
// Created by hunordbcz on 30.11.2020.
//

#ifndef SCS_TERMINAL_FILECREATION_H
#define SCS_TERMINAL_FILECREATION_H

#include "MemoryAlgorithm.h"

class RandomAccessMemory : public MemoryAlgorithm{
public:
    RandomAccessMemory();

protected:
    void runCode(int size) override;


};


#endif //SCS_TERMINAL_FILECREATION_H
