//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

void insertProcess(Process** head, int id, int arrivalTime, int burstTime) {
    Process* newNode = malloc(sizeof(Process));
    newNode->id = id;
    newNode->arrivalTime = arrivalTime;
    newNode->burstTime = burstTime;
    newNode->remainingTime = burstTime;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void scheduleProcess(Process** head) {
    time_t currentTime = time(NULL);
    Process* currentProcess = NULL;

    while (*head) {
        if (currentProcess == NULL || (*head)->arrivalTime <= currentTime) {
            currentProcess = *head;
            *head = (*head)->next;
        } else {
            break;
        }
    }

    if (currentProcess) {
        printf("Process %d is being scheduled.\n", currentProcess->id);
        currentProcess->remainingTime--;
        if (currentProcess->remainingTime == 0) {
            printf("Process %d is completed.\n", currentProcess->id);
        }
    } else {
        printf("No processes are ready.\n");
    }
}

int main() {
    Process* processes = NULL;

    insertProcess(&processes, 1, 0, 5);
    insertProcess(&processes, 2, 2, 4);
    insertProcess(&processes, 3, 4, 3);
    insertProcess(&processes, 4, 6, 2);
    insertProcess(&processes, 5, 8, 1);

    scheduleProcess(&processes);
    scheduleProcess(&processes);
    scheduleProcess(&processes);

    return 0;
}