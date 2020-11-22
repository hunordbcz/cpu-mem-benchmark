//
// Created by hdebreczeni on 21.11.2020.
//

#include "DigitOfPi.h"

DigitOfPi::DigitOfPi() : Algorithm("Nth Digit of Pi") {
    for(int size : {1, 100, 1000, 10000, 100000}){
        scoreBySize.emplace(size, -1);
    }
}

void DigitOfPi::runTest() {
    vector<int> sizes;
    for(auto const& imap: scoreBySize){
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void DigitOfPi::runCode(int size) {
    int p = 1;
    int q = 2;

    int res;

    // While N > 0 compute the Nth digit
    // by dividing p and q and store the
    // result into variable res
    // and go to next digit
    while (size > 0) {
        size--;
        p *= 10;
        res = p / q;
        p %= q;
    }
}


