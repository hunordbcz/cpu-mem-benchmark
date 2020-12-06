//
// Created by hdebreczeni on 21.11.2020.
//

#include "PiApproximation.h"

PiApproximation::PiApproximation() : Algorithm("Pi approximation with Taylor series") {
    for (int size : {1, 10, 100, 1000, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}) {
        scoreBySize.emplace(size, -1);
    }
}

void PiApproximation::runCode(int size) {
    RDTSC_START()
    double sum = 0.0;
    int sign = 1;
    for (int i = 0; i < size; ++i) {
        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
    }
    (void) (4.0 * sum);
    RDTSC_STOP();
}


