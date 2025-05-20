//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    struct Process* next;
} Process;

void insertProcess(Process** head, int id, int arrivalTime, int burstTime) {
    Process* newNode = (Process*)malloc(sizeof(Process));
    newNode->id = id;
    newNode->arrivalTime = arrivalTime;
    newNode->burstTime = burstTime;
    newNode->completionTime = 0;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void simulate(Process* head) {
    int currentTime = 0;
    while (!head->completionTime) {
        int i = 0;
        Process* currentProcess = head;
        for (i = 0; currentProcess; i++) {
            if (currentProcess->arrivalTime <= currentTime) {
                currentProcess->completionTime = currentTime + currentProcess->burstTime;
                printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
                currentProcess = currentProcess->next;
            } else {
                currentProcess = currentProcess->next;
            }
        }
        currentTime++;
    }
}

int main() {
    Process* head = NULL;
    insertProcess(&head, 1, 0, 5);
    insertProcess(&head, 2, 2, 4);
    insertProcess(&head, 3, 4, 3);
    insertProcess(&head, 4, 6, 2);
    insertProcess(&head, 5, 8, 1);

    simulate(head);

    return 0;
}