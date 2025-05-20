//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NUMBER 10

typedef struct Process {
    char name[20];
    int arrivalTime;
    int processingTime;
    int remainingTime;
    struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int arrivalTime, int processingTime) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    strcpy(newProcess->name, name);
    newProcess->arrivalTime = arrivalTime;
    newProcess->processingTime = processingTime;
    newProcess->remainingTime = processingTime;
    newProcess->next = NULL;

    if (head == NULL) {
        head = newProcess;
    } else {
        Process* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newProcess;
    }
}

void schedule() {
    Process* currentProcess = head;
    while (currentProcess) {
        printf("%s is being processed...\n", currentProcess->name);
        currentProcess->remainingTime--;
        if (currentProcess->remainingTime == 0) {
            printf("%s has finished processing.\n", currentProcess->name);
            free(currentProcess);
            currentProcess = head;
        } else {
            currentProcess = currentProcess->next;
        }
    }
}

int main() {
    insertProcess("A", 0, 5);
    insertProcess("B", 2, 4);
    insertProcess("C", 3, 3);
    insertProcess("D", 4, 2);

    schedule();

    return 0;
}