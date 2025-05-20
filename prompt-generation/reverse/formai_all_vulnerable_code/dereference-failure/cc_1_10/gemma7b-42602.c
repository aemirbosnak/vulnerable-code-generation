//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Queue *queue;
} Process;

typedef struct Queue {
    int size;
    Process **processes;
    struct Queue *next;
} Queue;

void initialize_processes(Process **processes) {
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i] = (Process *)malloc(sizeof(Process));
        processes[i]->pid = i + 1;
        processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->burst_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->remaining_time = processes[i]->burst_time;
        processes[i]->queue = NULL;
    }
}

void simulate_cpu_scheduling(Process **processes) {
    time_t start_time = time(NULL);
    int current_time = processes[0]->arrival_time;

    while (time(NULL) - start_time < 10) {
        for (int i = 0; i < MAX_PROCESS; i++) {
            if (processes[i]->arrival_time <= current_time && processes[i]->remaining_time > 0) {
                processes[i]->remaining_time--;
                current_time++;
            }
        }

        current_time++;
    }

    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process %d completed with remaining time %d\n", processes[i]->pid, processes[i]->remaining_time);
    }
}

int main() {
    Process **processes = (Process *)malloc(MAX_PROCESS * sizeof(Process));
    initialize_processes(processes);
    simulate_cpu_scheduling(processes);

    return 0;
}