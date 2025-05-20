//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process {
    int pid;
    char name[20];
    int burstTime;
    int remainingTime;
    struct Process* next;
} Process;

void createProcess(Process** head) {
    *head = malloc(sizeof(Process));
    (*head)->pid = 1;
    strcpy((*head)->name, "Process A");
    (*head)->burstTime = 5;
    (*head)->remainingTime = 5;
    (*head)->next = NULL;
}

void addProcess(Process** head, Process* newProcess) {
    Process* current = *head;
    if (current) {
        while (current->next) {
            current = current->next;
        }
        current->next = newProcess;
    } else {
        *head = newProcess;
    }
}

void scheduleProcess(Process** head) {
    Process* current = *head;
    time_t startTime = time(NULL);
    while (current) {
        time_t endTime = startTime + current->burstTime;
        sleep(current->burstTime);
        current->remainingTime -= current->burstTime;
        printf("Process %s completed with remaining time %d\n", current->name, current->remainingTime);
        startTime = endTime;
        current = current->next;
    }
}

int main() {
    Process* head = NULL;
    createProcess(&head);
    addProcess(&head, malloc(sizeof(Process)));
    addProcess(&head, malloc(sizeof(Process)));
    scheduleProcess(&head);
    return 0;
}