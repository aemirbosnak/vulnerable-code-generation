//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
} process;

process* createProcess(int pid, char* name, int burst_time) {
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->pid = pid;
    strcpy(newProcess->name, name);
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcessToQueue(process* newProcess, process** head) {
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*head)->next = newProcess;
        *head = newProcess;
    }
}

void roundRobin(process** head) {
    time_t start_time = time(NULL);
    process* currentProcess = *head;
    while (currentProcess) {
        currentProcess->remaining_time--;
        if (currentProcess->remaining_time == 0) {
            printf("Process %d completed.\n", currentProcess->pid);
            free(currentProcess);
            currentProcess = NULL;
        } else if (time(NULL) - start_time >= 1) {
            start_time = time(NULL);
            currentProcess = (*head)->next;
        }
    }
    printf("All processes completed.\n");
}

int main() {
    process* head = NULL;
    addProcessToQueue(createProcess(1, "Process A", 5), &head);
    addProcessToQueue(createProcess(2, "Process B", 3), &head);
    addProcessToQueue(createProcess(3, "Process C", 8), &head);
    addProcessToQueue(createProcess(4, "Process D", 2), &head);
    addProcessToQueue(createProcess(5, "Process E", 6), &head);

    roundRobin(&head);

    return 0;
}