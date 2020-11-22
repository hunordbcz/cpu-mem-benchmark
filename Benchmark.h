//
// Created by debre on 11/8/2020.
//

#ifndef SCS_TERMINAL_BENCHMARK_H
#define SCS_TERMINAL_BENCHMARK_H

#include <utility>
#include <vector>
#include <thread>
#include "Terminal.h"
#include "UI.h"
#include "algorithms/TestAlgorithm.h"
#include "algorithms/GreatestCommonDivisor.h"
#include "algorithms/FibonacciNumber.h"
#include "algorithms/PiApproximation.h"
#include "algorithms/Ackermann.h"
#include "algorithms/LucasLehmer.h"
#include "algorithms/LIIDS.h"

using namespace std;

class Benchmark {
public:
    typedef enum {
        SETUP,
        TEST,
        RESULT,
    } STATUS;

private:
    vector<Algorithm *> cpuAlgorithms;
    vector<Algorithm *> memoryAlgorithms;

    typedef enum {
        INVALID,
        EXIT,
        TOGGLE_ALGORITHM,
        CONTINUE
    } COMMAND;

    STATUS status;
    UI *ui;

    void processCommand(pair<COMMAND, int> pair, string *message) {
        switch (pair.first) {
            case INVALID:
                message->assign("Invalid Command");
                break;
            case EXIT:
                exit(EXIT_SUCCESS);
            case CONTINUE:
                break;
            case TOGGLE_ALGORITHM:
                int index = pair.second;
                unsigned long sizeCpu = cpuAlgorithms.size();
                if (sizeCpu > index) {
                    Algorithm *pAlgorithm = cpuAlgorithms.at(index);
                    pAlgorithm->setIsActive(!pAlgorithm->getIsActive());
                } else {
                    Algorithm *pAlgorithm = memoryAlgorithms.at(index - sizeCpu);
                    pAlgorithm->setIsActive(!pAlgorithm->getIsActive());
                }
                break;
        }
    }

    COMMAND readCommand(string *message) {
        message->clear();

        string input;
        cin >> input;
        pair<COMMAND, int> result = parseCommand(input);

        processCommand(result, message);
        return result.first;
    }

    pair<COMMAND, int> parseCommand(const string &text) {
        COMMAND command;
        int value = -1;

        if (text == "exit" || text == "quit") {
            command = EXIT;
        } else if (text == "start" || text == "start" || text == "test" || text == "continue") {
            status = TEST;
            command = CONTINUE;
        } else {
            try {
                value = stoi(text);

                unsigned long sizeCpu = cpuAlgorithms.size();
                unsigned long sizeMemory = memoryAlgorithms.size();
                if (sizeCpu + sizeMemory - 1 >= value) {
                    command = TOGGLE_ALGORITHM;
                } else {
                    command = INVALID;
                }
            } catch (invalid_argument &e) {
                command = INVALID;
            }
        }

        return make_pair(command, value);
    }

public:

    Benchmark() {
        cpuAlgorithms.push_back(new GreatestCommonDivisor);
        cpuAlgorithms.push_back(new FibonacciNumber);
        cpuAlgorithms.push_back(new PiApproximation);
        cpuAlgorithms.push_back(new LIIDS);
//        cpuAlgorithms.push_back(new Ackermann);
        cpuAlgorithms.push_back(new LucasLehmer);
        memoryAlgorithms.push_back(new TestAlgorithm);
        memoryAlgorithms.push_back(new TestAlgorithm);
        memoryAlgorithms.push_back(new TestAlgorithm);

        this->ui = new UI(cpuAlgorithms, memoryAlgorithms);
        this->status = SETUP;
    }

    void start() {
        setup();
    }

    void setup(){
        string message;
        do {
            ui->refreshSetup(message);
            readCommand(&message);
        } while (SETUP == status);

        testing();
    }

    void testing(){
        thread thread(&Benchmark::runTests, this);
        do {
            ui->refreshTesting();
        } while (TEST == status);

        ui->refreshTesting();
        thread.join();

        string test;
        cin >> test;

        setup();
    }

    void runTests() {
        for (Algorithm *algorithm : cpuAlgorithms) {
            if (!algorithm->getIsActive()) {
                continue;
            }
            algorithm->runTest();
        }

        for (Algorithm *algorithm : memoryAlgorithms) {
            if (!algorithm->getIsActive()) {
                continue;
            }
            algorithm->runTest();
        }

        status = RESULT;
    }
};


#endif //SCS_TERMINAL_BENCHMARK_H
