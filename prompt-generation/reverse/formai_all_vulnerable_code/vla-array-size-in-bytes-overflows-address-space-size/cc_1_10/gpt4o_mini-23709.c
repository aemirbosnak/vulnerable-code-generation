//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void findWaitingTimeFCFS(Process processes[], int n) {
    processes[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void findTurnaroundTimeFCFS(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void findWaitingTimeRR(Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }
}

void findTurnaroundTimeRR(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%11d | %12d | %10d | %12d | %16d\n", processes[i].id,
               processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // FCFS Execution
    findWaitingTimeFCFS(processes, n);
    findTurnaroundTimeFCFS(processes, n);

    printf("\nFCFS Scheduling Results:\n");
    printProcesses(processes, n);

    // Reset waiting and turnaround times for RR
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\nEnter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    findWaitingTimeRR(processes, n, quantum);
    findTurnaroundTimeRR(processes, n);

    printf("\nRound Robin Scheduling Results:\n");
    printProcesses(processes, n);

    return 0;
}