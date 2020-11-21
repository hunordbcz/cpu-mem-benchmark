//
// Created by hdebreczeni on 21.11.2020.
//

#include "DigitOfPi.h"

DigitOfPi::DigitOfPi() : Algorithm("Nth Digit of Pi") {

}

void DigitOfPi::runCode() {
    int p = 1;
    int q = 2;
    int N = 10000;

    int res;

    // While N > 0 compute the Nth digit
    // by dividing p and q and store the
    // result into variable res
    // and go to next digit
    while (N > 0) {
        N--;
        p *= 10;
        res = p / q;
        p %= q;
    }

    cout<<res;
}


