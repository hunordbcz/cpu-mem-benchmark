#include "TestAlgorithm.h"

TestAlgorithm::TestAlgorithm() : Algorithm("Test Algorithm") {
    for (int size : {1, 100, 1000, 10000, 100000}) {
        scoreBySize.emplace(size, -1);
    }
}

void TestAlgorithm::runTest() {
    vector<int> sizes;
    for (auto const &imap: scoreBySize) {
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void TestAlgorithm::runCode(int size) {
    RDTSC_START()
    int value = 10;
    for (int i = 1; i < size; i++) {
        if (i % 2 == 0) {
            value *= i;
        } else {
            value /= i;
        }
    }
    RDTSC_STOP()
}
