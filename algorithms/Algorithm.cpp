//
// Created by debre on 11/9/2020.
//

#include "Algorithm.h"

uint64_t Algorithm::elapsed(uint32_t startHigh, uint32_t startLow, uint32_t endHigh, uint32_t endLow) {
    uint64_t start = (((uint64_t) startHigh) << 32) | startLow;
    uint64_t end = (((uint64_t) endHigh) << 32) | endLow;
    return end - start;
}

void Algorithm::execute(const vector<int> &iterations) {
    if (!isActive) {
        return;
    }

    start_hi = 0;
    start_lo = 0;
    end_hi = 0;
    end_lo = 0;

    for (int size : iterations) {
        long long iterationScore = 0;
        for(int i = 0; i < 10; i++){
            RDTSC_START()
            runCode(size);
//            RDTSC_STOP()
            iterationScore += getScore();
        }

        scoreBySize[size] = iterationScore / 10;
    }

    long long finalScore = 0;
    map<int, long long>::iterator itr;
    for (itr = scoreBySize.begin(); itr != scoreBySize.end(); ++itr) {
        finalScore += itr->second;
    }

    this->finalScore = finalScore / (long long) scoreBySize.size();
}

uint64_t Algorithm::getScore() {
    return elapsed(start_hi, start_lo, end_hi, end_lo);
}

bool Algorithm::getIsActive() const {
    return isActive;
}

void Algorithm::setIsActive(bool isActive) {
    this->isActive = isActive;
}

string Algorithm::getName() {
    return this->name;
}

Algorithm::Algorithm(const string &name) {
    this->name = name;
}

long long Algorithm::getFinalScore() {
    return this->finalScore;
}

map<int, long long> Algorithm::getScoresBySize() {
    return scoreBySize;
}


