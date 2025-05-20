//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROC 4
#define MAX_TIME 100

typedef struct Process {
    int id;
    int arrivalTime;
    int executionTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int executionTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->executionTime = executionTime;
    process->next = NULL;
    return process;
}

void simulate(Process* processes) {
    time_t currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < NUM_PROC) {
        for (Process* process = processes; process; process = process->next) {
            if (process->arrivalTime <= currentTime && process->executionTime > 0) {
                process->executionTime--;
                currentTime++;

                if (process->executionTime == 0) {
                    completedProcesses++;
                    printf("Process %d completed at time %d\n", process->id, currentTime);
                }
            }
        }

        sleep(1);
    }
}

int main() {
    Process* processes = createProcess(0, 0, 20);
    processes = createProcess(1, 10, 15);
    processes = createProcess(2, 5, 10);
    processes = createProcess(3, 7, 12);

    simulate(processes);

    return 0;
}