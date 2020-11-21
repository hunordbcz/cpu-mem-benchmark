//
// Created by hdebreczeni on 21.11.2020.
//

#include "FibonacciNumber.h"

FibonacciNumber::FibonacciNumber() : Algorithm("Nth Fibonacci Number") {

}

void FibonacciNumber::runCode() {
    int n = 100;

    int a = 0, b = 1, c, i;
    for(i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
}
