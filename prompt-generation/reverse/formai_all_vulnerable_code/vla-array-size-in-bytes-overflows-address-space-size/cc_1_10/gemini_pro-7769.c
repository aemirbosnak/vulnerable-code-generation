//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int remaining_time;  // Remaining time
    int waiting_time;    // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Scheduling algorithms
enum SchedulingAlgorithm {
    FCFS,
    SJF,
    RR
};

// Comparison functions for sorting processes
int compare_arrival_time(const Process *a, const Process *b) {
    return a->arrival_time - b->arrival_time;
}

int compare_burst_time(const Process *a, const Process *b) {
    return a->burst_time - b->burst_time;
}

// Function to find the waiting time for each process
void calculate_waiting_time(Process *processes, int num_processes) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

// Function to find the turnaround time for each process
void calculate_turnaround_time(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to print the results
void print_results(Process *processes, int num_processes) {
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Main function
int main() {
    // Get the number of processes
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Create an array of processes
    Process processes[num_processes];

    // Get the details of each process
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);

        // Initialize the remaining time
        processes[i].remaining_time = processes[i].burst_time;

        // Initialize the waiting time and turnaround time
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Sort the processes by arrival time
    qsort(processes, num_processes, sizeof(Process), compare_arrival_time);

    // Get the scheduling algorithm
    int scheduling_algorithm;
    printf("Enter the scheduling algorithm (1: FCFS, 2: SJF, 3: RR): ");
    scanf("%d", &scheduling_algorithm);

    switch (scheduling_algorithm) {
        case FCFS:
            printf("First Come First Served (FCFS) Scheduling\n");
            calculate_waiting_time(processes, num_processes);
            calculate_turnaround_time(processes, num_processes);
            print_results(processes, num_processes);
            break;

        case SJF:
            printf("Shortest Job First (SJF) Scheduling\n");
            qsort(processes, num_processes, sizeof(Process), compare_burst_time);
            calculate_waiting_time(processes, num_processes);
            calculate_turnaround_time(processes, num_processes);
            print_results(processes, num_processes);
            break;

        case RR:
            printf("Round Robin (RR) Scheduling\n");
            int time_quantum;
            printf("Enter the time quantum: ");
            scanf("%d", &time_quantum);
            int current_time = 0;
            int completed = 0;
            while (completed != num_processes) {
                for (int i = 0; i < num_processes; i++) {
                    if (processes[i].remaining_time > 0) {
                        if (processes[i].remaining_time <= time_quantum) {
                            current_time += processes[i].remaining_time;
                            processes[i].remaining_time = 0;
                            processes[i].turnaround_time = current_time;
                            completed++;
                        } else {
                            current_time += time_quantum;
                            processes[i].remaining_time -= time_quantum;
                            processes[i].waiting_time += time_quantum;
                        }
                    }
                }
            }
            calculate_turnaround_time(processes, num_processes);
            print_results(processes, num_processes);
            break;

        default:
            printf("Invalid scheduling algorithm.");
    }

    return 0;
}