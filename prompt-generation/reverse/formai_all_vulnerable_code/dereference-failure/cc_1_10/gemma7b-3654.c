//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int process_id;
    char name[20];
    int cpu_burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process *process) {
    process->waiting_time = process->cpu_burst_time - 1;
}

void calculate_turnaround_time(Process *process) {
    process->turnaround_time = process->waiting_time + process->cpu_burst_time;
}

void simulate_cpu_scheduling(Process *processes, int num_processes) {
    int current_time = 0;
    int quantum = 5;
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = processes[i].cpu_burst_time - 1;
    }

    while (current_time < processes[0].turnaround_time) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].waiting_time > 0) {
                processes[i].waiting_time--;
                current_time++;
            }
        }

        if (current_time % quantum == 0) {
            printf("Time: %d\n", current_time);
            for (int i = 0; i < num_processes; i++) {
                printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", processes[i].name, processes[i].waiting_time, processes[i].turnaround_time);
            }
            printf("\n");
        }
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int num_processes = 0;

    // Create processes
    processes[num_processes].process_id = num_processes++;
    strcpy(processes[num_processes].name, "Process A");
    processes[num_processes].cpu_burst_time = 8;

    processes[num_processes].process_id = num_processes++;
    strcpy(processes[num_processes].name, "Process B");
    processes[num_processes].cpu_burst_time = 12;

    processes[num_processes].process_id = num_processes++;
    strcpy(processes[num_processes].name, "Process C");
    processes[num_processes].cpu_burst_time = 6;

    processes[num_processes].process_id = num_processes++;
    strcpy(processes[num_processes].name, "Process D");
    processes[num_processes].cpu_burst_time = 10;

    processes[num_processes].process_id = num_processes++;
    strcpy(processes[num_processes].name, "Process E");
    processes[num_processes].cpu_burst_time = 4;

    // Simulate CPU scheduling
    simulate_cpu_scheduling(processes, num_processes);

    return 0;
}