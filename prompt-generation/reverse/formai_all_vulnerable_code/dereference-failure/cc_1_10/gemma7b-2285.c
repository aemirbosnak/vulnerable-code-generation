//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    struct Process* next;
} Process;

void roundRobin(Process* head) {
    Process* currentProcess = head;
    int timeQuantum = 5;

    while (currentProcess) {
        printf("Process %d is running...", currentProcess->id);
        sleep(timeQuantum);
        currentProcess->completionTime = timeQuantum;
        currentProcess = currentProcess->next;
    }
}

void main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create some processes
    Process* process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->arrivalTime = 0;
    process1->burstTime = 3;

    Process* process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->arrivalTime = 2;
    process2->burstTime = 4;

    Process* process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->arrivalTime = 3;
    process3->burstTime = 2;

    Process* process4 = malloc(sizeof(Process));
    process4->id = 4;
    process4->arrivalTime = 4;
    process4->burstTime = 5;

    Process* process5 = malloc(sizeof(Process));
    process5->id = 5;
    process5->arrivalTime = 5;
    process5->burstTime = 3;

    // Link the processes together
    process1->next = process2;
    process2->next = process3;
    process3->next = process4;
    process4->next = process5;
    process5->next = NULL;

    // Round robin scheduling
    roundRobin(process1);

    // Print the completion times
    printf("Completion times:");
    process1->completionTime = time(NULL);
    printf("\nProcess %d: %d", process1->id, process1->completionTime);
    process2->completionTime = time(NULL);
    printf("\nProcess %d: %d", process2->id, process2->completionTime);
    process3->completionTime = time(NULL);
    printf("\nProcess %d: %d", process3->id, process3->completionTime);
    process4->completionTime = time(NULL);
    printf("\nProcess %d: %d", process4->id, process4->completionTime);
    process5->completionTime = time(NULL);
    printf("\nProcess %d: %d", process5->id, process5->completionTime);
}