//
// Created by debre on 11/9/2020.
//

#ifndef SCS_TERMINAL_ALGORITHM_H
#define SCS_TERMINAL_ALGORITHM_H

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

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

using namespace std;

class Algorithm {
protected:
    map<int, long long> scoreBySize;
    bool isActive;
    string name;

    uint32_t end_hi = 0;
    uint32_t end_lo = 0;

    uint64_t getScore();

    uint32_t start_hi = 0;
    uint32_t start_lo = 0;
public:
    explicit Algorithm(const string &name);

private:
    long long finalScore = -1;

    uint64_t elapsed(uint32_t startHigh, uint32_t startLow,
                     uint32_t endHigh, uint32_t endLow);


protected:

    void execute(const vector<int> &iterations);

    virtual void runCode(int size) = 0;

public:
    virtual void runTest() = 0;

    long long getFinalScore();

    map<int, long long> getScoresBySize();

    bool getIsActive() const;

    void setIsActive(bool isActive);

    string getName();

    void resetScores();
};


#endif //SCS_TERMINAL_ALGORITHM_H
