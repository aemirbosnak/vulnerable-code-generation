//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_Quantum 3

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int id, int arrivalTime, int burstTime) {
    Process* newNode = malloc(sizeof(Process));
    newNode->id = id;
    newNode->arrivalTime = arrivalTime;
    newNode->burstTime = burstTime;
    newNode->remainingTime = burstTime;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Process* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void schedule() {
    Process* currentProcess = head;
    while (currentProcess) {
        if (currentProcess->remainingTime > 0) {
            currentProcess->remainingTime--;
            printf("Process %d is running\n", currentProcess->id);
        } else {
            printf("Process %d has finished\n", currentProcess->id);
            free(currentProcess);
            currentProcess = head;
        }
    }
}

int main() {
    addProcess(1, 0, 5);
    addProcess(2, 2, 4);
    addProcess(3, 4, 3);
    addProcess(4, 6, 2);
    addProcess(5, 8, 1);

    schedule();

    return 0;
}