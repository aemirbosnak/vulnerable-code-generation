//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 32
#define MAX_PROCESS_MEMORY_USAGE_LENGTH 10

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int memoryUsage;
} Process;

void getProcesses(Process* processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[i].name, line + 6, MAX_PROCESS_NAME_LENGTH - 1);
            processes[i].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            processes[i].memoryUsage = atoi(line + 7);
        }

        i++;
    }

    fclose(file);
}

void printProcesses(Process* processes, int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        printf("PID: %d\n", processes[i].pid);
        printf("Name: %s\n", processes[i].name);
        printf("Memory Usage: %d bytes\n\n", processes[i].memoryUsage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = 0;

    while (numProcesses < MAX_PROCESSES) {
        getProcesses(processes);
        numProcesses = 0;

        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].pid > 0) {
                numProcesses++;
            }
        }
    }

    printProcesses(processes, numProcesses);

    return 0;
}