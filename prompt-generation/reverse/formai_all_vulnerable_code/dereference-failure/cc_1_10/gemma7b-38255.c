//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 5
#define SCHED_Quantum 3

struct process {
    int pid;
    char name[20];
    int burst_time;
    int remaining_time;
    struct process* next;
};

void roundrobin(struct process** head) {
    struct process* current = *head;
    struct process* next = NULL;

    while (current) {
        next = current->next;
        current->remaining_time--;
        if (current->remaining_time == 0) {
            printf("Process %d (%s) completed.\n", current->pid, current->name);
            *head = current->next;
            free(current);
        } else {
            current = next;
        }
    }
}

int main() {
    struct process* head = NULL;
    struct process* tail = NULL;

    // Create a few processes
    for (int i = 0; i < MAX_PROC; i++) {
        struct process* newProcess = (struct process*)malloc(sizeof(struct process));
        newProcess->pid = i + 1;
        sprintf(newProcess->name, "Process %d", newProcess->pid);
        newProcess->burst_time = rand() % 10 + 1;
        newProcess->remaining_time = newProcess->burst_time;

        if (head == NULL) {
            head = newProcess;
            tail = newProcess;
        } else {
            tail->next = newProcess;
            tail = newProcess;
        }
    }

    // Simulate the scheduling algorithm
    roundrobin(&head);

    return 0;
}