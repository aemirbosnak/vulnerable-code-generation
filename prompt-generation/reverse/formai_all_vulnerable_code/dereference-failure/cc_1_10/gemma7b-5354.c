//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_TIME 10

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    int completionTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int processingTime) {
    Process* process = malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->processingTime = processingTime;
    process->completionTime = 0;
    process->next = NULL;
    return process;
}

void simulateRoundRobin(Process* processes) {
    int currentTime = 0;
    int i = 0;
    int quantum = 2;

    processes->next = processes;

    while (!processes->next->completionTime) {
        for (i = 0; i < MAX_PROCESSORS; i++) {
            if (processes->next->arrivalTime <= currentTime && processes->next->completionTime == 0) {
                processes->next->completionTime = currentTime + quantum;
                printf("Process %d completed at time %d\n", processes->next->id, processes->next->completionTime);
                processes->next = processes->next->next;
            }
        }

        currentTime++;
    }
}

int main() {
    Process* processes = createProcess(1, 0, 5);
    processes = createProcess(2, 2, 4);
    processes = createProcess(3, 4, 3);
    processes = createProcess(4, 6, 2);

    simulateRoundRobin(processes);

    return 0;
}