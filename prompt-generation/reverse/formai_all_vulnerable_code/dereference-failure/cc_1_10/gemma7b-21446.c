//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int burst_time;
    int waiting_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->process_id = id;
    newProcess->burst_time = burstTime;
    newProcess->waiting_time = 0;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process** head, int id, int burstTime) {
    Process* newProcess = createProcess(id, burstTime);
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
        *head = newProcess;
    }
}

void roundRobin(Process** head) {
    int timeQuantum = 5;
    int currentProcess = 0;
    Process* processQueue = *head;

    while (processQueue) {
        Process* currentProcessPtr = processQueue;

        for (int i = 0; i < timeQuantum; i++) {
            if (currentProcessPtr->burst_time > 0) {
                currentProcessPtr->burst_time--;
            } else {
                currentProcessPtr->waiting_time++;
                currentProcessPtr = processQueue->next;
                processQueue = processQueue->next;
                currentProcess = 0;
            }
        }

        if (currentProcessPtr->burst_time == 0) {
            printf("Process %d completed.\n", currentProcessPtr->process_id);
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(&head, 1, 8);
    addProcess(&head, 2, 4);
    addProcess(&head, 3, 12);
    addProcess(&head, 4, 6);
    addProcess(&head, 5, 10);

    roundRobin(&head);

    return 0;
}