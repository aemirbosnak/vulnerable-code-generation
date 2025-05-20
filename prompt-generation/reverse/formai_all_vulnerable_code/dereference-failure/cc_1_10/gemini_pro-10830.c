//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a process
typedef struct process {
    int pid;         // Process ID
    int arrival_time; // Arrival time
    int burst_time;  // Burst time
} process;

// Function to compare processes based on arrival time
int compare_arrival_time(const void *a, const void *b) {
    process *p1 = (process *)a;
    process *p2 = (process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to implement FCFS scheduling algorithm
void fcfs(process *processes, int n) {
    // Sort processes based on arrival time
    qsort(processes, n, sizeof(process), compare_arrival_time);

    // Initialize variables to keep track of time and waiting time
    int current_time = 0;
    int total_waiting_time = 0;

    // Iterate over processes
    for (int i = 0; i < n; i++) {
        // Calculate waiting time for the current process
        int waiting_time = current_time - processes[i].arrival_time;

        // Update total waiting time
        total_waiting_time += waiting_time;

        // Update current time
        current_time += processes[i].burst_time;

        // Print details of the current process
        printf("Process %d:\n", processes[i].pid);
        printf("Arrival time: %d\n", processes[i].arrival_time);
        printf("Burst time: %d\n", processes[i].burst_time);
        printf("Waiting time: %d\n\n", waiting_time);
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)total_waiting_time / n;

    // Print average waiting time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

// Function to implement SJF scheduling algorithm
void sjf(process *processes, int n) {
    // Create a copy of the original array of processes
    process *processes_copy = malloc(n * sizeof(process));
    for (int i = 0; i < n; i++) {
        processes_copy[i] = processes[i];
    }

    // Sort processes based on burst time
    qsort(processes_copy, n, sizeof(process), compare_arrival_time);

    // Initialize variables to keep track of time and waiting time
    int current_time = 0;
    int total_waiting_time = 0;

    // Iterate over processes
    for (int i = 0; i < n; i++) {
        // Calculate waiting time for the current process
        int waiting_time = current_time - processes_copy[i].arrival_time;

        // Update total waiting time
        total_waiting_time += waiting_time;

        // Update current time
        current_time += processes_copy[i].burst_time;

        // Print details of the current process
        printf("Process %d:\n", processes_copy[i].pid);
        printf("Arrival time: %d\n", processes_copy[i].arrival_time);
        printf("Burst time: %d\n", processes_copy[i].burst_time);
        printf("Waiting time: %d\n\n", waiting_time);
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)total_waiting_time / n;

    // Print average waiting time
    printf("Average waiting time: %.2f\n", avg_waiting_time);

    // Free the allocated memory
    free(processes_copy);
}

// Function to implement RR scheduling algorithm
void rr(process *processes, int n, int quantum) {
    // Create an array to store the remaining burst time of each process
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // Initialize variables to keep track of time and waiting time
    int current_time = 0;
    int total_waiting_time = 0;

    // Iterate until all processes have completed execution
    while (1) {
        int completed_count = 0;

        // Iterate over processes
        for (int i = 0; i < n; i++) {
            // If the remaining burst time of the current process is greater than 0, execute the process for the specified quantum
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > quantum) {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    current_time += remaining_burst_time[i];
                    total_waiting_time += (current_time - processes[i].arrival_time - processes[i].burst_time);
                    remaining_burst_time[i] = 0;
                    completed_count++;
                }
            }
        }

        // If all processes have completed execution, break out of the loop
        if (completed_count == n) {
            break;
        }
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)total_waiting_time / n;

    // Print average waiting time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

// Main function
int main() {
    // Create an array of processes
    process processes[] = {
        {1, 0, 5},
        {2, 1, 4},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 1},
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Execute FCFS scheduling algorithm
    printf("FCFS Scheduling Algorithm:\n");
    fcfs(processes, n);

    // Execute SJF scheduling algorithm
    printf("\nSJF Scheduling Algorithm:\n");
    sjf(processes, n);

    // Execute RR scheduling algorithm
    printf("\nRR Scheduling Algorithm:\n");
    rr(processes, n, 2);

    return 0;
}