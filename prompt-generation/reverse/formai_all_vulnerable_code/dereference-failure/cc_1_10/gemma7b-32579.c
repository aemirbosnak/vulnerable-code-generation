//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 2

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    struct Process* next;
} Process;

void RoundRobin(Process* head) {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process %d is running...\n", currentProcess->id);
        currentProcess->processingTime--;
        if (currentProcess->processingTime == 0) {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create a few processes
    Process* process1 = malloc(sizeof(Process));
    process1->id = 1;
    process1->arrivalTime = 0;
    process1->processingTime = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->id = 2;
    process2->arrivalTime = 2;
    process2->processingTime = 3;

    Process* process3 = malloc(sizeof(Process));
    process3->id = 3;
    process3->arrivalTime = 4;
    process3->processingTime = 4;

    // Add processes to the queue
    if (head == NULL) {
        head = process1;
        tail = process1;
    } else {
        tail->next = process1;
        tail = process1;
    }

    if (head->next) {
        tail->next = process2;
        tail = process2;
    }

    if (head->next->next) {
        tail->next = process3;
        tail = process3;
    }

    // Round Robin scheduling algorithm
    RoundRobin(head);

    return 0;
}