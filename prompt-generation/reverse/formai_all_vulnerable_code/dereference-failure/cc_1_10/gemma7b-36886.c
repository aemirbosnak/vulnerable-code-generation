//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void schedule(struct process *processes) {
    int i = 0;
    int quantum = 0;
    int completed = 0;

    while (!completed) {
        // Calculate the next process to be scheduled
        int next_process = -1;
        for (i = 0; i < MAX_PROCESS; i++) {
            if (processes[i].burst_time > quantum) {
                next_process = i;
            }
        }

        // If a process is scheduled, update its waiting time and quantum
        if (next_process != -1) {
            processes[next_process].waiting_time++;
            quantum = processes[next_process].burst_time;
        }

        // Check if all processes are completed
        completed = 1;
        for (i = 0; i < MAX_PROCESS; i++) {
            if (processes[i].waiting_time != processes[i].turnaround_time) {
                completed = 0;
            }
        }

        // Print the current state of the scheduler
        printf("Time: %d\n", quantum);
        printf("Process: %d\n", processes[next_process].pid);
        printf("Waiting Time: %d\n", processes[next_process].waiting_time);
        printf("Turnaround Time: %d\n\n", processes[next_process].turnaround_time);
    }
}

int main() {
    struct process processes[MAX_PROCESS] = {
        {1, 5, 0, 0},
        {2, 4, 0, 0},
        {3, 3, 0, 0},
        {4, 2, 0, 0},
        {5, 1, 0, 0}
    };

    schedule(processes);

    return 0;
}