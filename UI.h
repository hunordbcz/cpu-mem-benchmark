//
// Created by debre on 11/9/2020.
//

#ifndef SCS_TERMINAL_UI_H
#define SCS_TERMINAL_UI_H

#include <iostream>
#include <utility>
#include "vector"
#include "algorithms/Algorithm.h"
#include "SystemInfo.h"

using namespace std;

class UI {
public:

    bool showSpecs;
    bool showHelp;
    bool showMenu = true;

    UI(vector<Algorithm *> cpu, vector<Algorithm *> memory) {
        this->cpuAlgorithms = std::move(cpu);
        this->memoryAlgorithms = std::move(memory);
        this->systemInfo = new SystemInfo();

        this->run();
    }

    void refreshSetup(const string &message) {
        system("clear");
        printSetupMenu(message);
    }

    void refreshTesting() {
        system("clear");
        printTestingMenu();
    }

    void setShowSpecs(bool showSpecs) {
        UI::showSpecs = showSpecs;
    }

    void setShowHelp(bool showHelp) {
        UI::showHelp = showHelp;
    }

    void setShowMenu(bool showMenu) {
        UI::showMenu = showMenu;
    }

private:
    vector<Algorithm *> cpuAlgorithms;
    vector<Algorithm *> memoryAlgorithms;

    SystemInfo *systemInfo;


    void printSetupMenu(const string &message) {
        if (showSpecs) {
            systemInfo->printCPUInfo();
        }

        if (showMenu) {
            cout
                    << "CPU algorithms to be tested:" << endl;

            for (int i = 0; i < cpuAlgorithms.size(); i++) {
                Algorithm *algorithm = cpuAlgorithms.at(i);
                cout << i << " " << (algorithm->getIsActive() ? "[YES]" : "[NO]")
                     << " - " << algorithm->getName() << endl;
            }

            cout
                    << "------------------------" << endl
                    << "Memory algorithms to be tested:" << endl;

            unsigned int cpuSize = cpuAlgorithms.size();
            for (int i = 0; i < memoryAlgorithms.size(); i++) {
                Algorithm *algorithm = memoryAlgorithms.at(i);
                cout << i + cpuSize << " " << (algorithm->getIsActive() ? "[YES]" : "[NO]")
                     << " - " << algorithm->getName() << endl;
            }

            cout
                    << "------------------------" << endl;
        }

        if (showHelp) {

        }


        if (!message.empty()) {
            cout
                    << "Message: " << message << endl
                    << "------------------------" << endl;
        }

        cout << "> ";
    }

    void printTestingMenu() {
        if (showSpecs) {
            systemInfo->printCPUInfo();
        }

        cout
                << "------------------------" << endl
                << "Memory algorithms:" << endl;

        for (Algorithm *algorithm: memoryAlgorithms) {
            if (!algorithm->getIsActive()) {
                continue;
            }

            cout << algorithm->getName();
            if (algorithm->getFinalScore() == -1) {
                cout << " - RUNNING" << endl;
            } else {
                cout << " - Score: " << algorithm->getFinalScore() << endl;
            }
        }

        cout
                << "CPU algorithms:" << endl;

        for (Algorithm *algorithm: cpuAlgorithms) {
            if (!algorithm->getIsActive()) {
                continue;
            }

            cout << algorithm->getName();
            if (algorithm->getFinalScore() == -1) {
                cout << " - RUNNING" << endl;
            } else {
                cout << " - Score: " << algorithm->getFinalScore() << endl;
            }
        }
    }

    void run() {

    }
};


#endif //SCS_TERMINAL_UI_H
