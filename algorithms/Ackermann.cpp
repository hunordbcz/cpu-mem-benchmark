//
// Created by hdebreczeni on 21.11.2020.
//

#include "Ackermann.h"

Ackermann::Ackermann() : Algorithm("Ackermann") {
    for (int size : {1}) {
        scoreBySize.emplace(size, -1);
    }
}

int ack(int n, int m) {
    if (m == 0) return n + 1;
    if (n == 0) return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

int Ackermann::runCode(int size) {
    int val;
    RDTSC_START();
    val = ack(size, size);
    RDTSC_STOP();

    return val;
}
