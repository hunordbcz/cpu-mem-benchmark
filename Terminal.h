//
// Created by debre on 11/8/2020.
//

#ifndef SCS_TERMINAL_TERMINAL_H
#define SCS_TERMINAL_TERMINAL_H

#include "string"
#include "vector"

using namespace std;

class Terminal {
private:
    vector<string> algorithms = {
            "Algorithm 2",
            "Algorithm 1"
    };

public:

    Terminal() {

    }

    char readChar();

    void printString(const string&);

    void printMenu();

    void clear();
};

#endif //SCS_TERMINAL_TERMINAL_H
