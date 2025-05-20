//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int quantum = 2;
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        int min_burst_time = INT_MAX;
        int min_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time += quantum;
            continue;
        }

        processes[min_index].burst_time -= quantum;
        current_time += quantum;

        if (processes[min_index].burst_time == 0) {
            completed_processes++;
        } else {
            processes[min_index].waiting_time += current_time - processes[min_index].burst_time;
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    printf("\nEnter the process details:\n");

    int i;
    for (i = 0; i < n; i++) {
        printf("Process ID %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}