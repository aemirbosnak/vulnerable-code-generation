//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;         // Process ID
    int burst_time; // CPU Burst Time
    int remaining_time; // Remaining Time
};

// Function to calculate waiting time
void calculateWaitingTime(struct Process processes[], int n, int burst_time[], int waiting_time[], int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    int t = 0; // Current time
    while (1) {
        int done = 1; // Flag to check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is a process still remaining
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }
}

// Function to calculate turnaround time
void calculateTurnaroundTime(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++)
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
}

// Function to find average time
void findavgTime(struct Process processes[], int n, int quantum) {
    int waiting_time[n], turnaround_time[n];

    calculateWaitingTime(processes, n, processes->burst_time, waiting_time, quantum);
    calculateTurnaroundTime(processes, n, waiting_time, turnaround_time);

    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign Process ID
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findavgTime(processes, n, quantum);

    return 0;
}