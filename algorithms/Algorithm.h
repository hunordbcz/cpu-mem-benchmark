//
// Created by debre on 11/9/2020.
//

#ifndef SCS_TERMINAL_ALGORITHM_H
#define SCS_TERMINAL_ALGORITHM_H

#include <cstdint>
#include <cstdio>
#include <iostream>

using namespace std;

class Algorithm {
protected:
    bool isActive;
    string name;

public:
    explicit Algorithm(const string &name);

private:
    long long finalScore = -1;

    uint32_t start_hi = 0, start_lo = 0;
    uint32_t end_hi = 0, end_lo = 0;

    uint64_t elapsed(uint32_t startHigh, uint32_t startLow,
                     uint32_t endHigh, uint32_t endLow);

    uint64_t getScore();



protected:

    virtual void runCode() = 0;

public:
    void execute(int iterations);

    long long getFinalScore();

    bool getIsActive() const;

    void setIsActive(bool isActive);

    string getName();
};


#endif //SCS_TERMINAL_ALGORITHM_H
