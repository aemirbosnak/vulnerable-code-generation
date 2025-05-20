//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
    Process* process = malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;
    process->remainingTime = burstTime;
    process->next = NULL;

    return process;
}

void roundRobin(Process* head) {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process %d is running...\n", currentProcess->id);
        sleep(1);
        currentProcess->remainingTime--;
        if (currentProcess->remainingTime == 0) {
            printf("Process %d has finished.\n", currentProcess->id);
            free(currentProcess);
            currentProcess = NULL;
        } else {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = createProcess(1, 0, 5);
    Process* process2 = createProcess(2, 2, 3);
    Process* process3 = createProcess(3, 4, 2);

    head = process1;
    head->next = process2;
    head->next->next = process3;

    roundRobin(head);

    return 0;
}