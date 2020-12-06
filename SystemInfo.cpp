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
    cout << "Number of Cores conf.: \t" << get_nprocs_conf() << endl;
    printf("system uptime : %ld days, %ld:%02ld:%02ld\n",
           si.uptime / day, (si.uptime % day) / hour,
           (si.uptime % hour) / minute, si.uptime % minute);
    printf("total RAM   : %5.1f MB\n", si.totalram / megabyte);
    printf("free RAM   : %5.1f MB\n", si.freeram / megabyte);
    printf("process count : %d\n", si.procs);
    cout << endl;


    //Virtual Memory


    struct sysinfo memInfo;

    sysinfo (&memInfo);
    long long totalVirtualMem = memInfo.totalram;
//Add other values in next statement to avoid int overflow on right hand side...
    totalVirtualMem += memInfo.totalswap;
    totalVirtualMem *= memInfo.mem_unit;
    cout << "Virtual Memory: " << totalVirtualMem << endl;

    //Virtual Memory Currently used
    long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
//Add other values in next statement to avoid int overflow on right hand side...
    virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
    virtualMemUsed *= memInfo.mem_unit;
    cout << "Virtual Memory currently used: " << virtualMemUsed << endl;

    //Virtual Memory currently used by current process
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    cout << "Virtual Memory currently used by current process: " << result << endl;

    long long totalPhysMem = memInfo.totalram;
//Multiply in next statement to avoid int overflow on right hand side...
    totalPhysMem *= memInfo.mem_unit;
    cout << "Total physical memory:" << totalPhysMem << endl;

    long long physMemUsed = memInfo.totalram - memInfo.freeram;
//Multiply in next statement to avoid int overflow on right hand side...
    physMemUsed *= memInfo.mem_unit;
    cout << "Physical memory used:" << physMemUsed << endl;

    //Physical Memory used
    file = fopen("/proc/self/status", "r");
    result = -1;

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    cout << "Physical Memory currently used by current process: " << result << endl;


    //CPU used
    double percent;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow,
           &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle) {
        //Overflow detection. Just skip this value.
        percent = -1.0;
    } else {
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
                (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    cout << "Cpu used: " << percent << endl;

    struct tms timeSample;
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

    cout << "Current Core usage: " << percent * get_nprocs_conf() << endl;
}