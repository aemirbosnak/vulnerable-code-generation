//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int memoryUsage;
} Process;

void getProcesses(Process* processes, int numProcesses) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= numProcesses) {
            break;
        }

        char* token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "VmRSS") == 0) {
            processes[i].memoryUsage = atoi(strtok(NULL, " ")) * 1024; // Convert to bytes
        } else if (strcmp(token, "Name") == 0) {
            strncpy(processes[i].name, strtok(NULL, " "), MAX_PROCESS_NAME_LENGTH - 1);
            processes[i].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
        }

        i++;
    }

    fclose(file);
}

void printProcesses(Process* processes, int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        printf("%d: %s (%d bytes)\n", processes[i].pid, processes[i].name, processes[i].memoryUsage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses = 0;

    getProcesses(processes, MAX_PROCESSES);
    numProcesses = sizeof(processes) / sizeof(Process);

    printf("Processes using RAM:\n");
    printProcesses(processes, numProcesses);

    return 0;
}