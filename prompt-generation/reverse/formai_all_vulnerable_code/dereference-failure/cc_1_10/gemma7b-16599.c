//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct process {
    int id;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    struct process* next;
} process;

process* createProcess() {
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->id = rand() % MAX_PROCESSES;
    newProcess->arrivalTime = rand() % MAX_TIME;
    newProcess->serviceTime = rand() % MAX_TIME;
    newProcess->completionTime = 0;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(process* head, process* newProcess) {
    if (head == NULL) {
        head = newProcess;
    } else {
        newProcess->next = head;
        head = newProcess;
    }
}

void schedule() {
    process* head = createProcess();
    addProcess(head, createProcess());
    addProcess(head, createProcess());
    addProcess(head, createProcess());
    addProcess(head, createProcess());

    time_t tStart = time(NULL);

    process* currentProcess = head;
    while (currentProcess) {
        int timeToComplete = currentProcess->serviceTime - time(NULL) - tStart;
        if (timeToComplete <= 0) {
            currentProcess->completionTime = time(NULL) + tStart;
            printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
            free(currentProcess);
            currentProcess = head;
        } else {
            currentProcess = currentProcess->next;
        }
    }

    time_t tEnd = time(NULL);
    printf("Total time elapsed: %d seconds\n", tEnd - tStart);
}

int main() {
    schedule();
    return 0;
}