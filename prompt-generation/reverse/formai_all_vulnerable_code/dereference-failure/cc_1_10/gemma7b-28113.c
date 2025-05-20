//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    char name[20];
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

void scheduleProcess(Process* head) {
    // Randomly select a process from the ready queue
    Process* currentProcess = head;
    srand(time(NULL));
    int randIndex = rand() % MAX_PROCESSES;
    while (currentProcess->id != randIndex) {
        currentProcess = currentProcess->next;
    }

    // Print the selected process
    printf("Process %d: %s, Remaining Time: %d\n", currentProcess->id, currentProcess->name, currentProcess->remainingTime);

    // Update the remaining time of the process
    currentProcess->remainingTime--;

    // If the process is completed, remove it from the ready queue
    if (currentProcess->remainingTime == 0) {
        free(currentProcess);
    }

    // Schedule the next process
    scheduleProcess(head);
}

int main() {
    // Create a linked list of processes
    Process* head = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->id = i;
        sprintf(newProcess->name, "Process %d", i);
        newProcess->burstTime = rand() % 10;
        newProcess->remainingTime = newProcess->burstTime;
        newProcess->next = head;
        head = newProcess;
    }

    // Schedule the processes
    scheduleProcess(head);

    return 0;
}