//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

struct Process {
    int pid;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    struct Process* next;
};

void schedule(struct Process* head) {
    // Round robin scheduling algorithm
    struct Process* currentProcess = head;
    int i = 0;

    while (currentProcess) {
        printf("Process %d is being serviced...\n", currentProcess->pid);
        currentProcess->completionTime = i + currentProcess->serviceTime;
        i++;

        currentProcess = currentProcess->next;
    }
}

int main() {
    struct Process* head = NULL;

    // Create some processes
    struct Process* process1 = malloc(sizeof(struct Process));
    process1->pid = 1;
    process1->arrivalTime = 0;
    process1->serviceTime = 5;

    struct Process* process2 = malloc(sizeof(struct Process));
    process2->pid = 2;
    process2->arrivalTime = 2;
    process2->serviceTime = 3;

    struct Process* process3 = malloc(sizeof(struct Process));
    process3->pid = 3;
    process3->arrivalTime = 4;
    process3->serviceTime = 4;

    // Add processes to the linked list
    head = process1;
    process1->next = process2;
    process2->next = process3;

    // Schedule the processes
    schedule(head);

    return 0;
}