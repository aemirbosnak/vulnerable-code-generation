//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

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

void addProcessToQueue(process* newProcess, process** queue) {
    if (*queue == NULL) {
        *queue = newProcess;
    } else {
        (*queue)->next = newProcess;
        *queue = newProcess;
    }
}

void preemptiveRoundRobin(process** queue) {
    time_t start_time = time(NULL);
    process* currentProcess = *queue;
    while (currentProcess) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        currentProcess->remaining_time -= time_spent;
        if (currentProcess->remaining_time <= 0) {
            printf("Process %d completed.\n", currentProcess->pid);
            free(currentProcess);
            *queue = currentProcess->next;
        } else {
            start_time = end_time;
        }
    }
}

int main() {
    process* processQueue = NULL;
    process* process1 = createProcess(1, "Process A", 5);
    process* process2 = createProcess(2, "Process B", 3);
    process* process3 = createProcess(3, "Process C", 8);
    process* process4 = createProcess(4, "Process D", 4);
    process* process5 = createProcess(5, "Process E", 6);

    addProcessToQueue(process1, &processQueue);
    addProcessToQueue(process2, &processQueue);
    addProcessToQueue(process3, &processQueue);
    addProcessToQueue(process4, &processQueue);
    addProcessToQueue(process5, &processQueue);

    preemptiveRoundRobin(&processQueue);

    return 0;
}