//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process proc[], int n, int quantum) {
    int rem_bt[n];  // Remaining burst time of processes
    for (int i = 0; i < n; i++)
        rem_bt[i] = proc[i].burst_time;

    int t = 0;  // Current time
    while (1) {
        int done = 1;  // Flag to check if all processes are done
        
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;  // There's a pending process
                
                if (rem_bt[i] > quantum) {
                    t += quantum;  // Increase current time by quantum
                    rem_bt[i] -= quantum;  // Reduce remaining burst time
                } else {
                    t = t + rem_bt[i];  // Increase current time by remaining time
                    proc[i].waiting_time = t - proc[i].burst_time - proc[i].arrival_time;  // Calculate waiting time
                    rem_bt[i] = 0;  // This process is done
                }
            }
        }
        
        if (done == 1) break;  // All processes are finished
    }
}

void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void displayProcessDetails(Process proc[], int n) {
    printf("\nProcess ID | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("    %2d     |     %2d     |      %2d      |      %2d      |       %2d\n", 
            proc[i].process_id, proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *proc = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        proc[i].process_id = i + 1;
        printf("Enter Burst Time for Process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].arrival_time);
        proc[i].waiting_time = 0; // Initialize waiting time
        proc[i].turnaround_time = 0; // Initialize turnaround time
    }

    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);

    // Display the process details
    displayProcessDetails(proc, n);

    // Clean up
    free(proc);
    return 0;
}