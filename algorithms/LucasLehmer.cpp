//
// Created by hdebreczeni on 21.11.2020.
//

#include "LucasLehmer.h"

LucasLehmer::LucasLehmer() : Algorithm("Lucas Lehmer Primality Test") {
    for (int size : {1, 100, 1000, 10000, 100000}) {
        scoreBySize.emplace(size, -1);
    }
}

void LucasLehmer::runTest() {
    vector<int> sizes;
    for (auto const &imap: scoreBySize) {
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void LucasLehmer::runCode(int size) {
    RDTSC_START()
    RDTSC_STOP()
}
