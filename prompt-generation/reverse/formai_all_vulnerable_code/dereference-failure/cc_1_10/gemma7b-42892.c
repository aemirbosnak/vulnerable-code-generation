//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
    Process* process = malloc(sizeof(Process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;
    process->remainingTime = burstTime;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int arrivalTime, int burstTime) {
    Process* process = createProcess(id, arrivalTime, burstTime);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t currentTime = time(NULL);
    Process* currentProcess = head;
    while (currentProcess) {
        if (currentProcess->arrivalTime <= currentTime && currentProcess->remainingTime > 0) {
            printf("Process %d is running...\n", currentProcess->id);
            currentProcess->remainingTime--;
            currentTime++;
        } else {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 3);
    addProcess(head, 4, 6, 2);

    roundRobin(head);

    return 0;
}