//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void fcfs(struct process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;
        p[i].completion_time = time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        time = p[i].completion_time;
    }
}

void sjf(struct process p[], int n) {
    int time = 0, completed = 0, shortest;
    while (completed != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].completion_time < 0) {
                if (shortest == -1 || p[i].burst_time < p[shortest].burst_time) {
                    shortest = i;
                }
            }
        }
        if (shortest >= 0) {
            p[shortest].completion_time = time + p[shortest].burst_time;
            p[shortest].turnaround_time = p[shortest].completion_time - p[shortest].arrival_time;
            p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
            time = p[shortest].completion_time;
            completed++;
        } else {
            time++;
        }
    }
}

void rr(struct process p[], int n, int quantum) {
    int time = 0, remaining_burst[n];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = p[i].burst_time;
    }
    while (1) {
        int completed = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                completed = 0;
                if (remaining_burst[i] <= quantum) {
                    time += remaining_burst[i];
                    p[i].completion_time = time;
                    remaining_burst[i] = 0;
                } else {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                }
            }
        }
        if (completed) break;
    }
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

int main() {
    int n, quantum;
    struct process p[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Process %d:\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].completion_time = -1;
    }
    printf("Choose a scheduling algorithm:\n");
    printf("1. First Come First Serve\n");
    printf("2. Shortest Job First\n");
    printf("3. Round Robin\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            printf("Enter the time quantum: ");
            scanf("%d", &quantum);
            rr(p, n, quantum);
            break;
        default:
            printf("Invalid choice\n");
            exit(1);
    }
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    return 0;
}