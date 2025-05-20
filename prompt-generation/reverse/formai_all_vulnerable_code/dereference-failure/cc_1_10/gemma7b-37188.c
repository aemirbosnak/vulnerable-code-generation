//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int burstTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->burstTime = burstTime;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int burstTime) {
    Process* process = createProcess(id, burstTime);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    int i = 0;
    Process* currentProcess = head;
    while (currentProcess) {
        printf("Process %d is running...\n", currentProcess->id);
        currentProcess->burstTime--;
        if (currentProcess->burstTime == 0) {
            currentProcess = currentProcess->next;
            i++;
        }
        if (i == MAX_PROCESSES - 1) {
            i = 0;
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 5);
    addProcess(head, 2, 3);
    addProcess(head, 3, 4);
    addProcess(head, 4, 2);
    addProcess(head, 5, 6);

    roundRobin(head);

    return 0;
}