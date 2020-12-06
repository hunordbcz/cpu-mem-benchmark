//
// Created by hunordbcz on 07.12.2020.
//

#include "MemoryAlgorithm.h"

MemoryAlgorithm::MemoryAlgorithm(const string &name) : Algorithm(name) {
    for (int size : {1, 16, 128, 512, 1024}) {
        scoreBySize.emplace(size, -1);
    }
}
