//
// Created by hdebreczeni on 21.11.2020.
//

#include "FibonacciNumber.h"

FibonacciNumber::FibonacciNumber() : Algorithm("Nth Fibonacci Number") {
    for(int size : {1, 100, 1000, 10000, 100000}){
        scoreBySize.emplace(size, -1);
    }
}

void FibonacciNumber::runTest() {
    vector<int> sizes;
    for(auto const& imap: scoreBySize){
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void FibonacciNumber::runCode(int size) {
    int a = 0, b = 1, c, i;
    for (i = 2; i <= size; i++) {
        c = a + b;
        a = b;
        b = c;
    }
}