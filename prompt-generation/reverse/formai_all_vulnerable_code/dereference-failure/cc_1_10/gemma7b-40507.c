//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROCESSES 5
#define MAX_SLEEP_TIME 10

// Define the processes
struct process {
    int id;
    int arrivalTime;
    int executionTime;
    int sleepTime;
    struct process* next;
};

// Round Robin Scheduling Algorithm
void roundRobin(struct process* processes) {
    struct process* currentProcess = processes;
    while (currentProcess) {
        printf("Process %d is running...\n", currentProcess->id);
        sleep(currentProcess->executionTime);
        currentProcess->sleepTime--;
        if (currentProcess->sleepTime == 0) {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    // Create a linked list of processes
    struct process* processes = NULL;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        processes = malloc(sizeof(struct process));
        processes->id = i + 1;
        processes->arrivalTime = rand() % MAX_SLEEP_TIME;
        processes->executionTime = rand() % MAX_SLEEP_TIME;
        processes->sleepTime = rand() % MAX_SLEEP_TIME;
        processes->next = NULL;

        if (processes != NULL) {
            processes = processes->next;
        } else {
            processes = processes;
        }
    }

    // Round Robin Scheduling Algorithm
    roundRobin(processes);

    return 0;
}