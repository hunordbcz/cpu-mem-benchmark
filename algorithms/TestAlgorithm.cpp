//
// Created by debre on 11/9/2020.
//

#include "TestAlgorithm.h"

void TestAlgorithm::runCode() {
    int value = 10;
    for (int i = 1; i < 10000; i++) {
        if (i % 2 == 0) {
            value *= i;
        } else {
            value /= i;
        }
    }
}

TestAlgorithm::TestAlgorithm() : Algorithm("Test Algorithm") {

}
