//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process {
    int pid;
    char name[20];
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

void createProcess(Process** head) {
    *head = (Process*)malloc(sizeof(Process));
    (*head)->pid = 1;
    strcpy((*head)->name, "Process 1");
    (*head)->burstTime = 5;
    (*head)->remainingTime = (*head)->burstTime;
    (*head)->next = NULL;
}

void addProcess(Process** head, Process* newProcess) {
    newProcess->next = NULL;
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
        *head = newProcess;
    }
}

void roundRobin(Process** head) {
    int timeQuantum = 3;
    Process* currentProcess = *head;
    while (currentProcess) {
        if (currentProcess->remainingTime > 0) {
            currentProcess->remainingTime -= timeQuantum;
            printf("Process %d is running for %d time units.\n", currentProcess->pid, timeQuantum);
        } else {
            printf("Process %d has completed execution.\n", currentProcess->pid);
            free(currentProcess);
            currentProcess = (*head)->next;
        }
    }
}

int main() {
    Process* head = NULL;
    createProcess(&head);
    addProcess(&head, (Process*)malloc(sizeof(Process)));
    addProcess(&head, (Process*)malloc(sizeof(Process)));
    addProcess(&head, (Process*)malloc(sizeof(Process)));
    roundRobin(&head);
    return 0;
}