//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_TIME 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    struct Process* next;
};

void insertProcess(struct Process** head, int id, int arrivalTime, int burstTime) {
    struct Process* newNode = (struct Process*)malloc(sizeof(struct Process));
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

void scheduleProcess(struct Process** head) {
    struct Process* currentProcess = *head;
    struct Process* nextProcess = NULL;

    while (currentProcess) {
        currentProcess->remainingTime--;

        if (currentProcess->remainingTime == 0) {
            printf("Process %d completed.\n", currentProcess->id);

            if (nextProcess) {
                currentProcess = nextProcess;
                nextProcess = NULL;
            } else {
                currentProcess = NULL;
            }
        } else if (nextProcess) {
            nextProcess = currentProcess->next;
        }
    }
}

int main() {
    struct Process* head = NULL;

    insertProcess(&head, 1, 0, 5);
    insertProcess(&head, 2, 2, 4);
    insertProcess(&head, 3, 4, 3);
    insertProcess(&head, 4, 6, 2);
    insertProcess(&head, 5, 8, 1);

    scheduleProcess(&head);

    return 0;
}