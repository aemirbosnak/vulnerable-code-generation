//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int processingTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->processingTime = processingTime;
    process->next = NULL;
    return process;
}

void simulate() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create a list of processes
    Process* process1 = createProcess(1, 0, 5);
    Process* process2 = createProcess(2, 2, 4);
    Process* process3 = createProcess(3, 4, 3);
    Process* process4 = createProcess(4, 6, 2);
    Process* process5 = createProcess(5, 8, 1);

    // Add processes to the list
    if (head == NULL) {
        head = process1;
        tail = process1;
    } else {
        tail->next = process1;
        tail = process1;
    }

    // Simulate the CPU scheduling algorithm
    int currentTime = 0;
    while (!tail->next) {
        // Find the process that arrives at the current time
        Process* currentProcess = head;
        while (currentProcess && currentProcess->arrivalTime > currentTime) {
            currentProcess = currentProcess->next;
        }

        // If the process arrives, start its execution
        if (currentProcess) {
            printf("Process %d started at time %d\n", currentProcess->id, currentTime);
            currentTime += currentProcess->processingTime;
            printf("Process %d finished at time %d\n", currentProcess->id, currentTime);
            free(currentProcess);
            currentProcess = NULL;
        }

        // Increment the current time
        currentTime++;
    }

    // Print the final state of the system
    printf("All processes have finished execution.\n");
}

int main() {
    simulate();
    return 0;
}