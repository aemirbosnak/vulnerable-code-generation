//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    struct Process* next;
} Process;

void simulate_cpu(Process** head) {
    time_t current_time = time(NULL);
    Process* current_process = NULL;

    while (*head) {
        Process* process = *head;

        if (process->arrival_time <= current_time && current_process == NULL) {
            current_process = process;
            *head = process->next;
        }

        if (current_process) {
            current_process->service_time--;

            if (current_process->service_time == 0) {
                printf("Process %d completed.\n", current_process->process_id);
                current_process = NULL;
            }
        }
    }
}

int main() {
    Process* head = NULL;

    // Simulate some processes
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
    process3->arrival_time = 4;
    process3->service_time = 4;

    head = process1;
    head->next = process2;
    head->next->next = process3;

    // Simulate the CPU
    simulate_cpu(&head);

    return 0;
}