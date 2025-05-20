//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* create_process(int id, int arrival_time, int execution_time) {
    Process* process = malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrival_time;
    process->execution_time = execution_time;
    process->remaining_time = execution_time;
    process->next = NULL;
    return process;
}

void schedule_process(Process* head) {
    time_t current_time = time(NULL);
    Process* current_process = head;

    while (current_process) {
        if (current_process->arrival_time <= current_time && current_process->remaining_time > 0) {
            printf("Process %d is running...\n", current_process->process_id);
            current_process->remaining_time--;
            sleep(MAX_TIME_Quantum);
        } else {
            current_process = current_process->next;
        }
    }

    printf("All processes have completed execution.\n");
}

int main() {
    Process* head = NULL;

    // Create some processes
    head = create_process(1, 0, 5);
    head = create_process(2, 2, 4);
    head = create_process(3, 1, 3);
    head = create_process(4, 3, 2);
    head = create_process(5, 4, 6);

    // Schedule the processes
    schedule_process(head);

    return 0;
}