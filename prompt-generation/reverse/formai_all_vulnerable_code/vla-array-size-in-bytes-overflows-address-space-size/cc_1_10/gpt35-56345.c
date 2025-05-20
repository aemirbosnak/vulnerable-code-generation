//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void fcfs(struct Process processes[], int n);
void sjf(struct Process processes[], int n);
void round_robin(struct Process processes[], int n, int quantum);

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Maximum number of processes exceeded.\n");
        exit(1);
    }
    printf("Enter the arrival time and burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }
    printf("\nWhich CPU Scheduling algorithm do you want to use?\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            printf("Enter the time quantum: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }
    return 0;
}

void fcfs(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_completion_time = 0;
    printf("\nExecution order: ");
    for (int i = 0; i < n; i++) {
        total_waiting_time += total_completion_time - processes[i].arrival_time;
        processes[i].waiting_time = total_completion_time - processes[i].arrival_time;
        total_completion_time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d ", processes[i].id);
    }
    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %f\n", (float) total_turnaround_time / n);
}

void sjf(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_completion_time = 0;
    printf("\nExecution order: ");
    for (int i = 0; i < n; i++) {
        // Find the shortest job that has arrived, but not completed yet
        int shortest_job_index = -1;
        int shortest_job_burst_time = -1;
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival_time <= total_completion_time && processes[j].completion_time == 0) {
                if (shortest_job_index == -1 || processes[j].burst_time < shortest_job_burst_time) {
                    shortest_job_index = j;
                    shortest_job_burst_time = processes[j].burst_time;
                }
            }
        }
        total_completion_time += processes[shortest_job_index].burst_time;
        processes[shortest_job_index].completion_time = total_completion_time;
        processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;
        total_turnaround_time += processes[shortest_job_index].turnaround_time;
        processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
        total_waiting_time += processes[shortest_job_index].waiting_time;
        printf("%d ", processes[shortest_job_index].id);
    }
    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %f\n", (float) total_turnaround_time / n);
}

void round_robin(struct Process processes[], int n, int quantum) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_completion_time = 0;
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }
    int time = 0;
    printf("\nExecution order: ");
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0;
                if (remaining_burst_time[i] <= quantum) {
                    time += remaining_burst_time[i];
                    remaining_burst_time[i] = 0;
                    processes[i].completion_time = time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    printf("%d ", processes[i].id);
                } else {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                    printf("%d ", processes[i].id);
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %f\n", (float) total_turnaround_time / n);
}