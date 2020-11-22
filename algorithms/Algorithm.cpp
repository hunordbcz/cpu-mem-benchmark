//
// Created by debre on 11/9/2020.
//

#include "Algorithm.h"

#define RDTSC_START()            \
    __asm__ volatile("CPUID\n\t" \
                     "RDTSC\n\t" \
                     "mov %%edx, %0\n\t" \
                     "mov %%eax, %1\n\t" \
                     : "=r" (start_hi), "=r" (start_lo) \
                     :: "%rax", "%rbx", "%rcx", "%rdx");

#define RDTSC_STOP()              \
    __asm__ volatile("RDTSCP\n\t" \
                     "mov %%edx, %0\n\t" \
                     "mov %%eax, %1\n\t" \
                     "CPUID\n\t" \
                     : "=r" (end_hi), "=r" (end_lo) \
                     :: "%rax", "%rbx", "%rcx", "%rdx");


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
        RDTSC_START()
        runCode(size);
        RDTSC_STOP()

        scoreBySize[size] = getScore();
    }

    long long score = 0;
    map<int, long long>::iterator itr;
    for (itr = scoreBySize.begin(); itr != scoreBySize.end(); ++itr) {
        score += itr->second;
    }

    finalScore = score / (long long) scoreBySize.size();
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


