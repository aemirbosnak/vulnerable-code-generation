//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROC 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, char* name, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    strcpy(process->name, name);
    process->burst_time = burst_time;
    process->remaining_time = burst_time;
    process->next = NULL;
    return process;
}

void addProcessToQueue(Process* process, Process** head) {
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
        *head = process;
    }
}

void roundRobin(Process** head) {
    Process* currentProcess = *head;
    while (currentProcess) {
        printf("Process %d is running...\n", currentProcess->pid);
        sleep(1);
        currentProcess->remaining_time--;
        if (currentProcess->remaining_time == 0) {
            printf("Process %d has finished.\n", currentProcess->pid);
            free(currentProcess);
            *head = (*head)->next;
        }
    }
}

int main() {
    Process* processes = NULL;
    addProcessToQueue(createProcess(1, "Process A", 5), &processes);
    addProcessToQueue(createProcess(2, "Process B", 3), &processes);
    addProcessToQueue(createProcess(3, "Process C", 2), &processes);
    addProcessToQueue(createProcess(4, "Process D", 4), &processes);
    addProcessToQueue(createProcess(5, "Process E", 3), &processes);

    roundRobin(&processes);

    return 0;
}