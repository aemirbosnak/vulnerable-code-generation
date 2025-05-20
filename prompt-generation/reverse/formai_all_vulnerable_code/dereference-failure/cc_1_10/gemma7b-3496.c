//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

void create_process(Process **processes, int index) {
    processes[index] = (Process *)malloc(sizeof(Process));
    processes[index]->process_id = index + 1;
    processes[index]->arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[index]->execution_time = rand() % MAX_QUEUE_SIZE;
    processes[index]->waiting_time = 0;
    processes[index]->turnaround_time = 0;
}

void simulate_cpu(Process **processes, int num_processes) {
    int current_time = 0;
    int i = 0;
    for (i = 0; i < num_processes; i++) {
        processes[i]->waiting_time++;
        if (processes[i]->arrival_time == current_time) {
            processes[i]->waiting_time = 0;
            current_time += processes[i]->execution_time;
            processes[i]->turnaround_time = current_time - processes[i]->arrival_time;
        }
    }
}

int main() {
    Process **processes = (Process **)malloc(MAX_PROCESSES * sizeof(Process));
    for (int i = 0; i < MAX_PROCESSES; i++) {
        create_process(processes, i);
    }

    simulate_cpu(processes, MAX_PROCESSES);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i]->process_id, processes[i]->waiting_time, processes[i]->turnaround_time);
    }

    return 0;
}