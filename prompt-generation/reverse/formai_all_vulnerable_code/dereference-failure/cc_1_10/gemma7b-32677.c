//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void simulate_cpu_scheduling(process **processes) {
    int quantum = 5;
    int time_slice = 0;
    int completed = 0;

    while (!completed) {
        for (int i = 0; i < MAX_PROCESS; i++) {
            if (processes[i]->waiting_time <= time_slice && processes[i]->burst_time > 0) {
                processes[i]->burst_time--;
                processes[i]->waiting_time++;
                time_slice++;

                if (processes[i]->burst_time == 0) {
                    completed++;
                    processes[i]->turnaround_time = time_slice - processes[i]->waiting_time;
                }
            }
        }

        time_slice = (time_slice % quantum) ? quantum : 0;
    }
}

int main() {
    process *processes = (process *)malloc(MAX_PROCESS * sizeof(process));

    // Create processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].pid = i;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Simulate CPU scheduling
    simulate_cpu_scheduling(processes);

    // Print results
    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }

    free(processes);

    return 0;
}