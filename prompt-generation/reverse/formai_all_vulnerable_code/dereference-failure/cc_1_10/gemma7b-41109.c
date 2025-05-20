//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    struct Process* next;
};

void insertProcess(struct Process** head, int arrivalTime, int burstTime) {
    struct Process* newNode = (struct Process*)malloc(sizeof(struct Process));
    newNode->pid = rand() % MAX_PROCESS;
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

void schedule(struct Process** head) {
    struct Process* currentProcess = *head;
    while (currentProcess) {
        // Calculate completion time
        currentProcess->completionTime = currentProcess->arrivalTime + currentProcess->burstTime;

        // Sort processes by completion time
        struct Process* previousProcess = NULL;
        struct Process* currentProcessTemp = currentProcess;
        while (currentProcessTemp->next) {
            if (currentProcessTemp->completionTime < (previousProcess ? previousProcess->completionTime : 0)) {
                previousProcess = currentProcessTemp;
                currentProcessTemp = currentProcessTemp->next;
            } else {
                break;
            }
        }

        // Execute process
        printf("Process %d completed at time %d\n", currentProcess->pid, currentProcess->completionTime);

        // Free process
        free(currentProcess);
        *head = currentProcessTemp;
    }
}

int main() {
    struct Process* head = NULL;

    // Insert processes
    insertProcess(&head, 0, 5);
    insertProcess(&head, 2, 3);
    insertProcess(&head, 4, 4);
    insertProcess(&head, 6, 2);
    insertProcess(&head, 8, 3);

    // Schedule processes
    schedule(&head);

    return 0;
}