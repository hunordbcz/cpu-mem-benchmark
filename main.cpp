#include <iostream>
#include "algorithms/Algorithm.h"
#include "algorithms/TestAlgorithm.h"
#include "Benchmark.h"

int main() {
    auto *benchmark = new Benchmark;
    benchmark->start();
    return 0;
}
