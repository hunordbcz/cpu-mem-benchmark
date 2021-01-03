//
// Created by hunordbcz on 07.12.2020.
//

#ifndef SCS_TERMINAL_MEMORYALGORITHM_H
#define SCS_TERMINAL_MEMORYALGORITHM_H


#include "Algorithm.h"

#include <algorithm>
#include <vector>
#include <random>

class MemoryAlgorithm : public Algorithm {
public:
    explicit MemoryAlgorithm(const string &name);

protected:
    virtual int runCode(int size) = 0;

    struct Node {
        int payload;
        Node* next = nullptr;
    };
};


#endif //SCS_TERMINAL_MEMORYALGORITHM_H
