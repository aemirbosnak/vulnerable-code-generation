//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    struct Process* next;
} Process;

void initialize_scheduler(Process** processes, int num_processes) {
    *processes = NULL;
    for (int i = 0; i < num_processes; i++) {
        processes[i] = NULL;
    }
}

void add_process(Process** processes, int process_id, int arrival_time, int burst_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->next = NULL;

    if (*processes == NULL) {
        *processes = new_process;
    } else {
        (*processes)->next = new_process;
    }
}

void simulate_scheduler(Process** processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        Process* current_process = processes[i];
        if (current_process != NULL) {
            // Calculate remaining time
            int remaining_time = current_process->burst_time - 1;
            // Update burst time
            current_process->burst_time = remaining_time;
            // Move to the ready queue
            processes[i] = NULL;
            printf("Process %d is in the ready queue\n", current_process->process_id);
        }
    }
}

int main() {
    Process** processes = NULL;
    initialize_scheduler(&processes, 3);

    add_process(processes, 1, 0, 5);
    add_process(processes, 2, 1, 4);
    add_process(processes, 3, 2, 3);

    simulate_scheduler(processes, 3);

    return 0;
}