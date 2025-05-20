//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct process* p, int n) {
    int i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    p[0].waiting_time = 0;
    for (i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
    printf("Pid\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i=0; i<n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

void sjf(struct process* p, int n) {
    int i, j, t;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (p[j].burst_time < p[i].burst_time) {
                t = p[i].burst_time;
                p[i].burst_time = p[j].burst_time;
                p[j].burst_time = t;
                t = p[i].arrival_time;
                p[i].arrival_time = p[j].arrival_time;
                p[j].arrival_time = t;
                t = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = t;
            }
        }
    }
    p[0].waiting_time = 0;
    for (i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
    printf("Pid\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i=0; i<n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int i, n, choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process* p = (struct process*)malloc(n * sizeof(struct process));
    printf("Enter the process details:\n");
    for (i=0; i<n; i++) {
        printf("Process %d\n", i+1);
        printf("PID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
    }

    printf("Select CPU Scheduling Algorithm\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    free(p);
    return 0;
}