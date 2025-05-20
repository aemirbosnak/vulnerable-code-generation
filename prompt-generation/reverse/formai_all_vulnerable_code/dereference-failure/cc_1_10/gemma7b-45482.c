//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME_Quantum 10

typedef struct process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int process_id, int arrival_time, int execution_time) {
    process* new_process = malloc(sizeof(process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->execution_time = execution_time;
    new_process->remaining_time = execution_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, int process_id, int arrival_time, int execution_time) {
    process* new_process = create_process(process_id, arrival_time, execution_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void preemptive_round_robin(process* head) {
    time_t current_time = time(NULL);
    process* current_process = head;
    int time_quantum = MAX_TIME_Quantum;

    while (current_process) {
        // Calculate remaining time for the current process
        int remaining_time = current_process->remaining_time - time_quantum;

        // If the remaining time is less than or equal to the time quantum,
        // complete the process
        if (remaining_time <= 0) {
            current_process->remaining_time = 0;
            printf("Process %d completed.\n", current_process->process_id);
        } else {
            // Otherwise, update the remaining time and move to the next process
            current_process->remaining_time = remaining_time;
            current_process = current_process->next;
        }

        // Sleep for the time quantum
        sleep(time_quantum);
    }

    printf("All processes completed.\n");
}

int main() {
    process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 4);
    add_process(head, 3, 4, 3);
    add_process(head, 4, 6, 2);

    preemptive_round_robin(head);

    return 0;
}