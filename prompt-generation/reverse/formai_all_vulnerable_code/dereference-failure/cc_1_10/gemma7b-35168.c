//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

typedef struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* createProcess(int pid, char* name, int burst_time) {
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->pid = pid;
    strcpy(newProcess->name, name);
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(process** head, int pid, char* name, int burst_time) {
    process* newProcess = createProcess(pid, name, burst_time);
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
    }
}

void roundRobin(process* head) {
    int timeQuantum = 5;
    process* currentProcess = head;
    while (currentProcess) {
        printf("Process ID: %d, Remaining Time: %d\n", currentProcess->pid, currentProcess->remaining_time);
        currentProcess->remaining_time -= timeQuantum;
        if (currentProcess->remaining_time == 0) {
            printf("Process ID: %d completed.\n", currentProcess->pid);
            free(currentProcess);
            currentProcess = NULL;
        } else {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    process* head = NULL;
    addProcess(&head, 1, "Process A", 10);
    addProcess(&head, 2, "Process B", 8);
    addProcess(&head, 3, "Process C", 6);
    addProcess(&head, 4, "Process D", 4);
    addProcess(&head, 5, "Process E", 2);

    roundRobin(head);

    return 0;
}