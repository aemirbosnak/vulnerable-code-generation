//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define QUANTUM 4

typedef struct process {
    int pid;
    int priority;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} process;

void round_robin(process* processes, int num_processes) {
    int i, time = 0;
    int* completion_time = (int*) malloc(num_processes * sizeof(int));
    int* turnaround_time = (int*) malloc(num_processes * sizeof(int));
    int* waiting_time = (int*) malloc(num_processes * sizeof(int));
    int* burst_time = (int*) malloc(num_processes * sizeof(int));
    int total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_processes = num_processes;

    for (i = 0; i < num_processes; i++) {
        burst_time[i] = processes[i].burst_time;
        waiting_time[i] = turnaround_time[i] = completion_time[i] = 0;
    }

    while (remaining_processes > 0) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time < QUANTUM) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                } else {
                    time += QUANTUM;
                    processes[i].remaining_time -= QUANTUM;
                }

                if (processes[i].remaining_time == 0) {
                    completion_time[i] = time;
                    remaining_processes--;
                    turnaround_time[i] = completion_time[i] - processes[i].burst_time;
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                }
            }
        }
    }

    printf("Round Robin Scheduling:\n");
    printf("PID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, burst_time[i], 
        waiting_time[i], turnaround_time[i], completion_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average Waiting Time: %f\n", (float) total_waiting_time / num_processes);
    printf("Average Turnaround Time: %f\n", (float) total_turnaround_time / num_processes);

    free(completion_time);
    free(turnaround_time);
    free(waiting_time);
    free(burst_time);
}

int main() {
    int i;
    process processes[] = {{1, 6, 11}, {2, 4, 5}, {3, 8, 4}, {4, 3, 6}, {5, 5, 7}};
    int num_processes = sizeof(processes) / sizeof(process);

    round_robin(processes, num_processes);

    return 0;
}