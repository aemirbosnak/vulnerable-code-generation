//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;         // Process id
    int burst_time;  // Burst time
    int arrival_time; // Arrival Time
} Process;

// Function to compare two processes based on arrival time (for FCFS)
int compare_arrival(const void *a, const void *b) {
    return ((Process *)a)->arrival_time - ((Process *)b)->arrival_time;
}

// Function to compare processes based on burst time (for SJF)
int compare_burst(const void *a, const void *b) {
    return ((Process *)a)->burst_time - ((Process *)b)->burst_time;
}

// First-Come, First-Served (FCFS) Scheduling
void fcfs(Process *processes, int n) {
    int wait_time[n], turnaround_time[n];
    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = processes[i - 1].burst_time + wait_time[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + wait_time[i];
    }

    printf("\nFCFS Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wait_time[i], turnaround_time[i]);
    }
}

// Shortest Job First (SJF) Scheduling
void sjf(Process *processes, int n) {
    qsort(processes, n, sizeof(Process), compare_burst);
    int wait_time[n], turnaround_time[n];
    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = processes[i - 1].burst_time + wait_time[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + wait_time[i];
    }

    printf("\nSJF Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wait_time[i], turnaround_time[i]);
    }
}

// Round Robin (RR) Scheduling
void round_robin(Process *processes, int n, int quantum) {
    int remaining_time[n], wait_time = 0;
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Process\tWaiting Time\n");

    int completed = 0, time = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    wait_time += (time - processes[i].burst_time - wait_time);
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].pid, wait_time);
    }
}

int main() {
    int n;
    printf("Welcome to the CPU Scheduling Simulation!\n");
    printf("How many processes do you want to schedule? ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n * sizeof(Process));

    printf("Enter details for each process (PID, Burst Time, Arrival Time):\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Setting PID for illustration
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    // Sort based on Arrival Time for FCFS and SJF
    qsort(processes, n, sizeof(Process), compare_arrival);

    // Scheduling Algorithms Call
    fcfs(processes, n);
    sjf(processes, n);

    int quantum;
    printf("Enter time Quantum for Round Robin: ");
    scanf("%d", &quantum);
    round_robin(processes, n, quantum);

    free(processes);
    return 0;
}