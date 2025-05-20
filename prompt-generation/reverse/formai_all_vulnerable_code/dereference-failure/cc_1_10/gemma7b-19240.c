//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int waiting_time;
    int turnaround_time;
} Process;

void create_processes(Process **processes) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = (Process *)malloc(sizeof(Process));
        processes[i]->process_id = i;
        processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->service_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->waiting_time = 0;
        processes[i]->turnaround_time = 0;
    }
}

void simulate_scheduling(Process **processes) {
    // Round robin scheduling algorithm
    int current_time = 0;
    int quantum = 5;
    int processes_in_queue = 0;

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i]->arrival_time <= current_time) {
            processes_in_queue++;
            processes[i]->waiting_time = current_time - processes[i]->arrival_time;
        }
    }

    while (processes_in_queue) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i]->arrival_time <= current_time && processes[i]->service_time > 0) {
                processes[i]->service_time--;
                current_time++;
                processes[i]->waiting_time++;
            }
        }

        processes_in_queue--;
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i]->turnaround_time = current_time - processes[i]->arrival_time;
    }
}

int main() {
    Process **processes = (Process **)malloc(MAX_PROCESSES * sizeof(Process));
    create_processes(processes);
    simulate_scheduling(processes);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i]->process_id, processes[i]->arrival_time, processes[i]->service_time, processes[i]->waiting_time, processes[i]->turnaround_time);
    }

    return 0;
}