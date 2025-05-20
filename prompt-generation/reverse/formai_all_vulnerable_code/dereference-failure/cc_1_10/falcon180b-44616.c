//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PRIORITY 10
#define MAX_TIME_QUANTUM 10

typedef struct {
    int processID;
    char processName[MAX_PROCESS_NAME_LENGTH];
    int priority;
    int timeQuantum;
    int remainingTime;
} Process;

int processCount = 0;
Process *processTable;

void initialize() {
    processTable = (Process *) malloc(MAX_PROCESSES * sizeof(Process));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processTable[i].processID = -1;
    }
}

int addProcess(char *name, int priority, int timeQuantum) {
    if (processCount >= MAX_PROCESSES) {
        printf("Error: Process table is full.\n");
        return -1;
    }
    processTable[processCount].processID = processCount;
    strcpy(processTable[processCount].processName, name);
    processTable[processCount].priority = priority;
    processTable[processCount].timeQuantum = timeQuantum;
    processTable[processCount].remainingTime = timeQuantum;
    processCount++;
    return processCount - 1;
}

void printProcessTable() {
    printf("Process ID\tProcess Name\tPriority\tTime Quantum\tRemaining Time\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t%s\t%d\t%d\t%d\n", processTable[i].processID, processTable[i].processName, processTable[i].priority, processTable[i].timeQuantum, processTable[i].remainingTime);
    }
}

int getNextProcess(int currentProcessID) {
    int nextProcessID = -1;
    int minRemainingTime = MAX_TIME_QUANTUM;
    for (int i = 0; i < processCount; i++) {
        if (processTable[i].processID!= currentProcessID && processTable[i].remainingTime < minRemainingTime) {
            minRemainingTime = processTable[i].remainingTime;
            nextProcessID = processTable[i].processID;
        }
    }
    return nextProcessID;
}

void roundRobinScheduling() {
    int currentProcessID = 0;
    int quantumCount = 0;
    while (processCount > 0) {
        if (quantumCount == MAX_TIME_QUANTUM) {
            quantumCount = 0;
            currentProcessID = getNextProcess(currentProcessID);
        }
        quantumCount++;
        if (processTable[currentProcessID].remainingTime > 0) {
            processTable[currentProcessID].remainingTime--;
        } else {
            printf("Process %d completed execution.\n", currentProcessID);
            currentProcessID = getNextProcess(currentProcessID);
        }
    }
}

int main() {
    initialize();
    addProcess("Process 1", 1, 2);
    addProcess("Process 2", 2, 3);
    addProcess("Process 3", 3, 1);
    printProcessTable();
    roundRobinScheduling();
    return 0;
}