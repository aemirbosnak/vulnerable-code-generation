//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    struct Process* next;
} Process;

void simulateCPUScheduling(Process* head) {
    int currentTime = 0;
    Process* currentProcess = NULL;

    while (head || currentTime) {
        if (!currentProcess && head) {
            currentProcess = head;
            head = head->next;
        }

        if (currentProcess && currentProcess->arrivalTime == currentTime) {
            currentProcess->completionTime = currentTime + currentProcess->serviceTime;
            printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
            currentProcess = NULL;
        }

        currentTime++;
    }

    printf("All processes completed.\n");
}

int main() {
    Process* head = NULL;

    // Create some processes
    Process* process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->arrivalTime = 0;
    process1->serviceTime = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->arrivalTime = 2;
    process2->serviceTime = 3;

    Process* process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->arrivalTime = 3;
    process3->serviceTime = 4;

    Process* process4 = malloc(sizeof(Process));
    process4->id = 4;
    process4->arrivalTime = 4;
    process4->serviceTime = 2;

    Process* process5 = malloc(sizeof(Process));
    process5->id = 5;
    process5->arrivalTime = 5;
    process5->serviceTime = 3;

    // Link the processes together
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;
    process4->next = process5;

    // Simulate the CPU scheduling algorithm
    simulateCPUScheduling(head);

    return 0;
}