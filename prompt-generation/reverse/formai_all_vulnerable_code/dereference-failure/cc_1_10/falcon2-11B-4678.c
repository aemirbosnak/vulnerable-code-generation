//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int priority;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    int averageTurnAroundTime;
    int averageWaitingTime;
} Process;

Process createProcess(int id, int priority, int burstTime) {
    Process process;
    process.id = id;
    process.priority = priority;
    process.burstTime = burstTime;
    process.waitingTime = 0;
    process.turnAroundTime = 0;
    process.averageTurnAroundTime = 0;
    process.averageWaitingTime = 0;
    return process;
}

void printProcess(Process process) {
    printf("Process %d: ", process.id);
    printf("Priority: %d\n", process.priority);
    printf("Burst Time: %d\n", process.burstTime);
    printf("Waiting Time: %d\n", process.waitingTime);
    printf("Turn Around Time: %d\n", process.turnAroundTime);
    printf("Average Turn Around Time: %f\n", process.averageTurnAroundTime);
    printf("Average Waiting Time: %f\n", process.averageWaitingTime);
}

int main() {
    srand(time(NULL));
    int numProcesses = 10;
    Process* processes = malloc(numProcesses * sizeof(Process));
    int processIndex = 0;
    int i;
    
    for (i = 0; i < numProcesses; i++) {
        int priority = rand() % 100;
        int burstTime = rand() % 100;
        Process process = createProcess(i + 1, priority, burstTime);
        processes[processIndex++] = process;
    }
    
    for (i = 0; i < numProcesses; i++) {
        printProcess(processes[i]);
    }
    
    return 0;
}