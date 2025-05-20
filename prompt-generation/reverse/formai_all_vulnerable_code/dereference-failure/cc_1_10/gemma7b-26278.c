//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4

// Struct to store process information
typedef struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    struct Process* next;
} Process;

// Function to simulate a round robin scheduling algorithm
void roundRobin(Process* head) {
    Process* currentProcess = head;
    int i = 0;

    // Rotate processes until all have completed or a time quantum is reached
    while (currentProcess && i < MAX_PROCESSORS) {
        // Execute the current process for its burst time
        printf("Process %d is running...\n", currentProcess->id);
        sleep(currentProcess->burstTime);

        // Increment the process's completion time
        currentProcess->arrivalTime++;

        // Move to the next process in the queue
        currentProcess = currentProcess->next;

        // Increment the round robin counter
        i++;
    }
}

int main() {
    // Create a linked list of processes
    Process* head = NULL;
    Process* process = malloc(sizeof(Process));
    process->id = 1;
    process->burstTime = 5;
    process->arrivalTime = 0;
    process->next = NULL;
    head = process;

    process = malloc(sizeof(Process));
    process->id = 2;
    process->burstTime = 3;
    process->arrivalTime = 1;
    process->next = NULL;
    head->next = process;

    process = malloc(sizeof(Process));
    process->id = 3;
    process->burstTime = 2;
    process->arrivalTime = 2;
    process->next = NULL;
    head->next->next = process;

    process = malloc(sizeof(Process));
    process->id = 4;
    process->burstTime = 4;
    process->arrivalTime = 3;
    process->next = NULL;
    head->next->next->next = process;

    // Simulate the round robin scheduling algorithm
    roundRobin(head);

    return 0;
}