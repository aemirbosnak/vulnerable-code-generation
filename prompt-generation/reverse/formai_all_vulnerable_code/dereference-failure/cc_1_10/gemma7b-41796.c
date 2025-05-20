//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PROCESS 5

typedef struct Process {
    char name[20];
    int priority;
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process *process) {
    process->waiting_time = 0;
    for (int i = 0; i < NUM_PROCESS; i++) {
        if (process->priority < process[i].priority) {
            process->waiting_time++;
        }
    }
}

void calculate_turnaround_time(Process *process) {
    process->turnaround_time = process->waiting_time + process->cpu_burst;
}

void simulate_cpu_scheduling(Process *process) {
    calculate_waiting_time(process);
    calculate_turnaround_time(process);
    printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", process->name, process->waiting_time, process->turnaround_time);
}

int main() {
    Process processes[NUM_PROCESS];

    // Create processes
    for (int i = 0; i < NUM_PROCESS; i++) {
        processes[i].name[i] = 'A' + i;
        processes[i].priority = i;
        processes[i].cpu_burst = rand() % 5 + 1;
    }

    // Simulate CPU scheduling
    for (int i = 0; i < NUM_PROCESS; i++) {
        simulate_cpu_scheduling(&processes[i]);
    }

    return 0;
}