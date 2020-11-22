//
// Created by hdebreczeni on 21.11.2020.
//

#include "GreatestCommonDivisor.h"

GreatestCommonDivisor::GreatestCommonDivisor() : Algorithm("Greatest Common Divisor") {
    for(int size : {1, 100, 1000, 10000, 100000}){
        scoreBySize.emplace(size, -1);
    }
}

int GreatestCommonDivisor::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void GreatestCommonDivisor::runCode(int size) {
    gcd(size,97);
}

void GreatestCommonDivisor::runTest() {
    vector<int> sizes;
    for(auto const& imap: scoreBySize){
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}
