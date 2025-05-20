//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to calculate waiting time of processes
void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }
    
    int t = 0;  // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;  // There is a pending process
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
}

// Function to calculate turnaround time of processes
void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// Function to find the average time
void findavgTime(Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

// Function to print the process details
void printProcessDetails(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-12d\t%-10d\t%-12d\t%-12d\t%-15d\n",
               processes[i].id,
               processes[i].burst_time,
               processes[i].arrival_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter Time Quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    findavgTime(processes, n, quantum);
    printProcessDetails(processes, n);

    free(processes);
    return 0;
}