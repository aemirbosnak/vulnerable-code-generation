//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    int status;
} Process;

void initialize_processes(Process **processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i] = malloc(sizeof(Process));
        processes[i]->process_id = i + 1;
        processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->execution_time = rand() % MAX_QUEUE_SIZE;
        processes[i]->remaining_time = processes[i]->execution_time;
        processes[i]->status = 0;
    }
}

void schedule_processes(Process **processes, int num_processes) {
    // Round robin scheduling algorithm
    int current_time = 0;
    int quantum = 5;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i]->status == 0 && processes[i]->arrival_time <= current_time) {
                processes[i]->status = 1;
                current_time += quantum;
                processes[i]->remaining_time--;
                if (processes[i]->remaining_time == 0) {
                    completed_processes++;
                }
            }
        }

        current_time++;
    }
}

int main() {
    Process **processes = NULL;
    int num_processes = 10;

    initialize_processes(&processes, num_processes);
    schedule_processes(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Process ID: %d, Completion Time: %d\n", processes[i]->process_id, processes[i]->arrival_time);
    }

    return 0;
}