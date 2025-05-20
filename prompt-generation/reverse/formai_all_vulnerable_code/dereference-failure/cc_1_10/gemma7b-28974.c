//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SCHED_Quantum 4
#define MAX_PROCESS_NUM 5

typedef struct Process {
    char name[20];
    int arrivalTime;
    int processingTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
    Process* currentProcess = head;
    while (currentProcess) {
        if (currentProcess->remainingTime > 0) {
            currentProcess->remainingTime--;
            printf("%s is running...\n", currentProcess->name);
            sleep(SCHED_Quantum);
        } else {
            currentProcess = currentProcess->next;
        }
    }
}

void addProcess(int arrivalTime, int processingTime, char name[]) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->arrivalTime = arrivalTime;
    newProcess->processingTime = processingTime;
    newProcess->remainingTime = processingTime;
    newProcess->name[0] = name[0];
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

int main() {
    addProcess(0, 5, "A");
    addProcess(2, 4, "B");
    addProcess(4, 3, "C");
    addProcess(6, 2, "D");
    addProcess(8, 1, "E");

    schedule();

    return 0;
}