//
// Created by hdebreczeni on 17.11.2020.
//

#ifndef SCS_TERMINAL_SYSTEMINFO_H
#define SCS_TERMINAL_SYSTEMINFO_H

#include "iostream"
#include <sys/utsname.h>

class SystemInfo {
public:
    void printCPUInfo();
};


#endif //SCS_TERMINAL_SYSTEMINFO_H
