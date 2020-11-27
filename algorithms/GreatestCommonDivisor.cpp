//
// Created by hdebreczeni on 21.11.2020.
//

#include "GreatestCommonDivisor.h"
#include "math.h"

GreatestCommonDivisor::GreatestCommonDivisor() : Algorithm("Greatest Common Divisor") {
    for (int size : {1, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}) {
        scoreBySize.emplace(size, -1);
    }
}

void GreatestCommonDivisor::runCode(int size) {
    int a = size;
    int b = sqrt(size);
    RDTSC_START()
    while (a != b) {
        if (a == 0 || b == 0) {
            break;
        }
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    (void) a;
    RDTSC_STOP()
}

void GreatestCommonDivisor::runTest() {
    vector<int> sizes;
    for (auto const &imap: scoreBySize) {
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}
