//
// Created by debre on 11/9/2020.
//

#include <zconf.h>
#include "TestAlgorithm.h"

TestAlgorithm::TestAlgorithm() : Algorithm("Test Algorithm") {
    for(int size : {1, 100, 1000, 10000, 100000}){
        scoreBySize.emplace(size, -1);
    }
}

void TestAlgorithm::runTest() {
    vector<int> sizes;
    for(auto const& imap: scoreBySize){
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void TestAlgorithm::runCode(int size) {
    int value = 10;
    for (int i = 1; i < size; i++) {
        if (i % 2 == 0) {
            value *= i;
        } else {
            value /= i;
        }
        usleep(1);
    }
}
