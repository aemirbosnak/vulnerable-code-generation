//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void fcfs(Process *processes, int n) {
    int i;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].completion_time = processes[i].burst_time;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        }

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("FCFS Scheduling:\n\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
                processes[i].pid, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %f\n", ((float)total_waiting_time / n));
    printf("Average Turnaround Time: %f\n", ((float)total_turnaround_time / n));
}

void sjf(Process *processes, int n) {
    int i, j;
    Process temp;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].completion_time = processes[i].burst_time;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        }

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("SJF Scheduling:\n\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
                processes[i].pid, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %f\n", ((float)total_waiting_time / n));
    printf("Average Turnaround Time: %f\n", ((float)total_turnaround_time / n));
}

void priority(Process *processes, int n) {
    int i, j;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int max_priority = i;

        for (j = i + 1; j < n; j++) {
            if (processes[j].arrival_time <= processes[max_priority].completion_time 
                    && processes[j].burst_time < processes[max_priority].burst_time) {
                max_priority = j;
            }
        }

        if (max_priority != i) {
            Process temp = processes[i];
            processes[i] = processes[max_priority];
            processes[max_priority] = temp;
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].completion_time = processes[i].burst_time;
        } else {
            processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        }

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Priority Scheduling:\n\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
                processes[i].pid, processes[i].arrival_time, processes[i].burst_time, 
                processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %f\n", ((float)total_waiting_time / n));
    printf("Average Turnaround Time: %f\n", ((float)total_turnaround_time / n));
}

int main() {
    int n;
    int i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;

        printf("Enter the arrival time and burst time of process %d: ", processes[i].pid);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    fcfs(processes, n);
    printf("\n");
    sjf(processes, n);
    printf("\n");
    priority(processes, n);

    free(processes);

    return 0;
}