//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

void roundRobin(Process* head) {
    Process* current = head;
    while (current) {
        printf("Process %d is being serviced...\n", current->process_id);
        current->remaining_time--;
        if (current->remaining_time == 0) {
            printf("Process %d has finished.\n", current->process_id);
            current = current->next;
        }
    }
}

int main() {
    Process* head = NULL;
    Process* tail = NULL;

    // Create some processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* newProcess = (Process*)malloc(sizeof(Process));
        newProcess->process_id = i + 1;
        newProcess->arrival_time = rand() % 10;
        newProcess->service_time = rand() % 5;
        newProcess->remaining_time = newProcess->service_time;

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