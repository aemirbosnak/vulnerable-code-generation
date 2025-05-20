//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
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
    int i, j, sum_wt = 0, sum_tat = 0, completed_processes = 0;
    int temp_wt[n], temp_tat[n];

    for (i = 0; i < n; i++) {
        temp_wt[i] = 0;
        temp_tat[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > 0) {
            for (j = 0; j < n; j++) {
                if (temp_wt[j] <= temp_wt[i] && processes[j].burst_time > 0) {
                    temp_wt[i] += temp_wt[j];
                }
            }
            temp_wt[i] += processes[i].burst_time;
            processes[i].waiting_time = temp_wt[i];
            sum_wt += temp_wt[i];
        } else {
            processes[i].waiting_time = 0;
        }
    }

    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        sum_tat += processes[i].turnaround_time;
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f\n", (float) sum_wt / n);
    printf("Average Turnaround Time: %f\n", (float) sum_tat / n);
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Enter PID of process %d: ", i + 1);
        scanf("%d", &processes[i].pid);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}