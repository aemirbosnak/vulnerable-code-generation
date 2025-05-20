//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    unsigned int pid;
    unsigned int memoryUsage;
} Process;

int getProcesses(Process *processes, int maxProcesses) {
    FILE *fp;
    char line[512];
    char *token;
    int count = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL && count < maxProcesses) {
        token = strtok(line, ":\n");
        if (token!= NULL) {
            strcpy(processes[count].name, token);
            processes[count].pid = atoi(strtok(NULL, ":\n"));
            processes[count].memoryUsage = atoi(strtok(NULL, ":\n")) * 1024;
            count++;
        }
    }

    fclose(fp);
    return count;
}

void printProcesses(Process *processes, int numProcesses) {
    printf("Process\tPID\tMemory Usage (KB)\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memoryUsage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = getProcesses(processes, MAX_PROCESSES);
    printProcesses(processes, numProcesses);

    return 0;
}