//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int id;
    int arrivalTime;
    int processingTime;
    struct Process* next;
} Process;

void initializeQueue(Process** head) {
    *head = NULL;
}

void enqueue(Process** head, Process* newProcess) {
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
        *head = newProcess;
    }
}

void schedule(Process** head) {
    Process* currentProcess = *head;
    time_t currentTime = time(NULL);

    while (currentProcess) {
        if (currentTime >= currentProcess->arrivalTime) {
            printf("Process %d is running...\n", currentProcess->id);
            sleep(currentProcess->processingTime);
            printf("Process %d has finished.\n", currentProcess->id);
            currentProcess = currentProcess->next;
        } else {
            break;
        }
    }

    printf("All processes have finished.\n");
}

int main() {
    Process* head = NULL;
    initializeQueue(&head);

    Process* newProcess1 = malloc(sizeof(Process));
    newProcess1->id = 1;
    newProcess1->arrivalTime = 0;
    newProcess1->processingTime = 5;
    enqueue(&head, newProcess1);

    Process* newProcess2 = malloc(sizeof(Process));
    newProcess2->id = 2;
    newProcess2->arrivalTime = 2;
    newProcess2->processingTime = 3;
    enqueue(&head, newProcess2);

    Process* newProcess3 = malloc(sizeof(Process));
    newProcess3->id = 3;
    newProcess3->arrivalTime = 4;
    newProcess3->processingTime = 2;
    enqueue(&head, newProcess3);

    schedule(&head);

    return 0;
}