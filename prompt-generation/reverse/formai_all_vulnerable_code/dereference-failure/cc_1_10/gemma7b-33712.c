//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int pid;
    int arrival_time;
    int service_time;
    struct process* next;
} process;

process* create_process(int pid, int arrival_time, int service_time) {
    process* p = (process*)malloc(sizeof(process));
    p->pid = pid;
    p->arrival_time = arrival_time;
    p->service_time = service_time;
    p->next = NULL;
    return p;
}

void round_robin(process* ready_queue, process* current_process) {
    if (ready_queue) {
        current_process = ready_queue;
        ready_queue = ready_queue->next;
        current_process->service_time--;
        if (current_process->service_time == 0) {
            printf("Process %d completed.\n", current_process->pid);
        } else {
            round_robin(ready_queue, current_process);
        }
    }
}

int main() {
    process* processes = NULL;
    process* ready_queue = NULL;
    process* current_process = NULL;

    // Create some processes
    processes = create_process(1, 0, 5);
    processes = create_process(2, 2, 4);
    processes = create_process(3, 1, 3);
    processes = create_process(4, 3, 2);
    processes = create_process(5, 0, 6);

    // Initialize the ready queue
    ready_queue = processes;

    // Start the round robin scheduler
    round_robin(ready_queue, current_process);

    return 0;
}