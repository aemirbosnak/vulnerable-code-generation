//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process {
    int pid;
    int arrival_time;
    int service_time;
    struct process* next;
} process;

void roundRobin(process* head) {
    process* current = head;
    time_t start_time = time(NULL);
    time_t end_time;
    int time_quantum = 5;

    while (current) {
        end_time = time(NULL);
        if (end_time - start_time >= time_quantum) {
            start_time = time(NULL);
            current->service_time--;
            printf("Process %d finished\n", current->pid);
        }
        current = current->next;
    }

    printf("All processes finished\n");
}

int main() {
    process* head = NULL;
    process* tail = NULL;

    // Create a few processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        process* newProcess = (process*)malloc(sizeof(process));
        newProcess->pid = i + 1;
        newProcess->arrival_time = rand() % 10;
        newProcess->service_time = rand() % 5;

        if (head == NULL) {
            head = newProcess;
            tail = newProcess;
        } else {
            tail->next = newProcess;
            tail = newProcess;
        }
    }

    // Round Robin scheduling
    roundRobin(head);

    return 0;
}