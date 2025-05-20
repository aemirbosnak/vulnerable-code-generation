//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
    struct Process* next;
} Process;

void roundrobin(Process** ready_queue, Process** waiting_queue) {
    int i = 0;
    Process* current_process = ready_queue[0];

    while (current_process) {
        printf("Process %d is running...", current_process->process_id);
        sleep(current_process->burst_time);

        current_process->waiting_time++;
        current_process->turn_around_time = current_process->waiting_time + current_process->burst_time;

        ready_queue[0] = current_process->next;
        waiting_queue[i++] = current_process;

        current_process = ready_queue[0];
    }
}

int main() {
    Process* processes[MAX_PROCESS] = {NULL};
    Process* waiting_queue[MAX_QUEUE_SIZE] = {NULL};
    Process* ready_queue[MAX_QUEUE_SIZE] = {NULL};

    // Create processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i] = (Process*)malloc(sizeof(Process));
        processes[i]->process_id = i + 1;
        processes[i]->name[0] = 'A' + i;
        processes[i]->burst_time = rand() % 5 + 1;
        processes[i]->waiting_time = 0;
        processes[i]->turn_around_time = 0;
        processes[i]->next = NULL;
    }

    // Initialize queues
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        waiting_queue[i] = NULL;
        ready_queue[i] = NULL;
    }

    // Insert processes into waiting queue
    for (int i = 0; i < MAX_PROCESS; i++) {
        waiting_queue[i] = processes[i];
    }

    // Start round robin scheduling
    roundrobin(ready_queue, waiting_queue);

    // Print results
    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", processes[i]->process_id, processes[i]->waiting_time, processes[i]->turn_around_time);
    }

    return 0;
}