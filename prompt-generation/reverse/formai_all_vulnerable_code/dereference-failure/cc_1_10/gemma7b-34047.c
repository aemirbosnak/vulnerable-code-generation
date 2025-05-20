//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
} Process;

void initialize_processes(Process **processes) {
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i] = malloc(sizeof(Process));
        processes[i]->pid = i + 1;
        processes[i]->name[0] = 'A' + i;
        processes[i]->cpu_burst = rand() % 10 + 1;
        processes[i]->waiting_time = 0;
        processes[i]->turnaround_time = 0;
    }
}

void simulate_round_robin(Process **processes) {
    int quantum = 5;
    int current_process = 0;
    int time_quantum = 0;

    while (!processes[current_process]->waiting_time) {
        time_quantum++;
        printf("Time quantum %d: Process %c is running\n", time_quantum, processes[current_process]->name);
        processes[current_process]->waiting_time--;
        processes[current_process]->turnaround_time++;

        if (time_quantum % quantum == 0) {
            current_process = (current_process + 1) % MAX_PROCESS;
        }
    }

    printf("Simulation complete\n");
}

int main() {
    Process **processes = (Process**)malloc(MAX_PROCESS * sizeof(Process));
    initialize_processes(processes);
    simulate_round_robin(processes);

    return 0;
}