//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct process {
    int pid;  // process id
    int arrival_time;  // arrival time of process
    int burst_time;  // execution time of process
    int waiting_time;  // waiting time of process
    int turn_around_time;  // turn around time of process
};

void fcfs(struct process p[], int n) {
    int wait_time = 0, turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = wait_time;
        p[i].turn_around_time = p[i].burst_time + wait_time;
        wait_time = p[i].turn_around_time;
        turnaround_time += p[i].turn_around_time;
    }
    printf("\nFCFS Scheduling:\n");
    printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time);
    }
    printf("\nAverage Turn Around Time: %f", (float)turnaround_time / n);
}

void sjf(struct process p[], int n) {
    int completed = 0, current_time = 0, min_burst_time = 99999, shortest_job_index;
    int wait_time = 0, turnaround_time = 0;
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].burst_time < min_burst_time && p[i].burst_time > 0) {
                min_burst_time = p[i].burst_time;
                shortest_job_index = i;
            }
        }
        p[shortest_job_index].burst_time--;
        min_burst_time = p[shortest_job_index].burst_time;
        if (min_burst_time == 0) {
            min_burst_time = 99999;
        }
        if (p[shortest_job_index].burst_time == 0) {
            completed++;
            int end_time = current_time + 1;
            p[shortest_job_index].turn_around_time = end_time - p[shortest_job_index].arrival_time;
            p[shortest_job_index].waiting_time = p[shortest_job_index].turn_around_time - p[shortest_job_index].burst_time - p[shortest_job_index].arrival_time;
            if (p[shortest_job_index].waiting_time < 0) {
                p[shortest_job_index].waiting_time = 0;
            }
            wait_time += p[shortest_job_index].waiting_time;
            turnaround_time += p[shortest_job_index].turn_around_time;
        }
        current_time++;
    }
    printf("\nSJF Scheduling:\n");
    printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time);
    }
    printf("\nAverage Turn Around Time: %f", (float)turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter information for process %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
    }
    fcfs(p, n);
    sjf(p, n);
    return 0;
}