//
// Created by hdebreczeni on 17.11.2020.
//

#include "sys/sysinfo.h"
#include "SystemInfo.h"
#include <iostream>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"

using namespace std;

static unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;
static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

SystemInfo::SystemInfo() {
    FILE *file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

int parseLine(char *line) {
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char *p = line;
    while (*p < '0' || *p > '9') p++;
    line[i - 3] = '\0';
    i = atoi(p);
    return i;
}


void SystemInfo::printCPUInfo() {
    const long minute = 60;
    const long hour = minute * 60;
    const long day = hour * 24;
    const double megabyte = 1024 * 1024;

    struct sysinfo si{};
    sysinfo (&si);


    //Virtual Memory

    cout << "Total Cores:\t " << get_nprocs_conf() << endl;
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    printf("Total RAM:\t %5.1f MB\n", si.totalram / megabyte);

    //Physical Memory used
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    printf("RAM usage:\t %2.1f MB\n", result / (double) 1024);


    //CPU used
    double percent;
    struct tms timeSample{};
    clock_t now;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU) {
        //Overflow detection. Just skip this value.
        percent = -1.0;
    } else {
        percent = (timeSample.tms_stime - lastSysCPU) +
                  (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    double cpuUsage = percent * get_nprocs_conf();
    if (cpuUsage > 100) {
        cpuUsage = 100;
    } else if (cpuUsage < 0) {
        cpuUsage = 0;
    }

    cout << "CPU Usage:\t " << cpuUsage << "%" << endl;
}