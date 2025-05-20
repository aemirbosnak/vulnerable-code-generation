//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

void schedule(Process* head) {
    time_t current_time = time(NULL);
    Process* current_process = head;

    while (current_process) {
        if (current_process->arrival_time <= current_time && current_process->service_time > 0) {
            printf("Process %d is being serviced\n", current_process->process_id);
            current_process->service_time--;
            current_time++;
        } else {
            current_process = current_process->next;
        }
    }
}

int main() {
    Process* head = NULL;

    // Create a few processes
    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->service_time = 5;

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->service_time = 3;

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 3;
    process3->service_time = 4;

    // Link the processes together
    process1->next = process2;
    process2->next = process3;

    // Schedule the processes
    schedule(head);

    return 0;
}