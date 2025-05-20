//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int completion_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int executionTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = id;
    newProcess->arrival_time = arrivalTime;
    newProcess->execution_time = executionTime;
    newProcess->completion_time = 0;
    newProcess->next = NULL;
    return newProcess;
}

void simulate(Process* processes) {
    time_t currentTime = 0;
    Process* currentProcess = NULL;

    while (!processes || processes->completion_time <= currentTime) {
        // Find the process that arrives at the current time
        Process* nextProcess = processes;
        while (nextProcess && nextProcess->arrival_time > currentTime) {
            nextProcess = nextProcess->next;
        }

        // If a process arrives, it becomes the current process
        if (nextProcess) {
            currentProcess = nextProcess;
            currentTime = currentProcess->arrival_time;
        }

        // If the current process is completed, it moves to the completed processes list
        if (currentProcess && currentProcess->execution_time <= currentTime) {
            currentProcess->completion_time = currentTime;
            printf("Process %d completed.\n", currentProcess->process_id);
            currentProcess = NULL;
        }

        // Increment the current time
        currentTime++;
    }

    // Print the completion time for each process
    printf("Process completion times:\n");
    processes = processes->next;
    while (processes) {
        printf("Process %d: Completion time %d\n", processes->process_id, processes->completion_time);
        processes = processes->next;
    }
}

int main() {
    Process* processes = NULL;

    // Create a few processes
    processes = createProcess(1, 0, 5);
    processes = createProcess(2, 2, 4);
    processes = createProcess(3, 4, 3);
    processes = createProcess(4, 6, 2);

    // Simulate the processes
    simulate(processes);

    return 0;
}