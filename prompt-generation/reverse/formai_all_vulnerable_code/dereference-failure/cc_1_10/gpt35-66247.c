//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Struct for each process
typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} process_t;

// Function for executing FCFS Scheduling Algorithm
void execute_fcfs(int n, process_t processes[]) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // If the process has not arrived yet, wait for it to arrive
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

// Function for executing SJF Scheduling Algorithm
void execute_sjf(int n, process_t processes[]) {
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        int shortest_index = -1;
        int shortest_time = 100000000;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time < shortest_time && processes[i].completion_time == -1) {
                shortest_index = i;
                shortest_time = processes[i].burst_time;
            }
        }
        if (shortest_index == -1) {
            current_time++;
            continue;
        }
        processes[shortest_index].completion_time = current_time + processes[shortest_index].burst_time;
        processes[shortest_index].turnaround_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
        processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
        current_time = processes[shortest_index].completion_time;
        completed_processes++;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of processes
    process_t* processes = (process_t*) malloc(n * sizeof(process_t));

    // Get user input for each process' arrival time and burst time
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process #%d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].completion_time = -1;
    }

    // Execute FCFS Algorithm and output results
    execute_fcfs(n, processes);
    printf("\nFCFS Scheduling Algorithm Results:\n");
    printf("PID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    // Reset processes array to run SJF Algorithm
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = -1;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    // Execute SJF Algorithm and output results
    execute_sjf(n, processes);
    printf("\nSJF Scheduling Algorithm Results:\n");
    printf("PID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    // Free dynamically allocated memory
    free(processes);

    // Exit program
    return 0;
}