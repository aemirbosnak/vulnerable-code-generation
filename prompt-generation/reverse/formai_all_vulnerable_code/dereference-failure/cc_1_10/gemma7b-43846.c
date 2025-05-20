//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

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

void addProcess(process* head, process* newProcess) {
    if (head == NULL) {
        head = newProcess;
    } else {
        head->next = newProcess;
        head = newProcess;
    }
}

void roundRobin(process* head) {
    time_t start_time = time(NULL);
    process* currentProcess = head;

    while (currentProcess) {
        printf("Process %d: ", currentProcess->pid);
        printf("Remaining time: %d\n", currentProcess->remaining_time);

        currentProcess->remaining_time--;

        if (currentProcess->remaining_time == 0) {
            printf("Process %d completed.\n", currentProcess->pid);
            free(currentProcess);
            currentProcess = head;
        } else {
            currentProcess = currentProcess->next;
        }

        time_t end_time = time(NULL);
        int time_taken = end_time - start_time;
        printf("Time taken: %d seconds\n", time_taken);
        start_time = end_time;
    }
}

int main() {
    process* head = NULL;

    // Create some processes
    process* process1 = createProcess(1, "Process 1", 5);
    process* process2 = createProcess(2, "Process 2", 3);
    process* process3 = createProcess(3, "Process 3", 4);
    process* process4 = createProcess(4, "Process 4", 2);
    process* process5 = createProcess(5, "Process 5", 6);

    // Add processes to the queue
    addProcess(head, process1);
    addProcess(head, process2);
    addProcess(head, process3);
    addProcess(head, process4);
    addProcess(head, process5);

    // Round Robin scheduling
    roundRobin(head);

    return 0;
}