//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PROCESSES 10
#define MAX_TIME_SLICE 10

// Process structure
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Scheduling algorithms
typedef enum {
    FCFS,
    SJF,
    RR
} SchedulingAlgorithm;

// Function prototypes
void run_simulation(SchedulingAlgorithm algorithm, Process processes[], int num_processes, int time_slice);
void print_results(Process processes[], int num_processes);

// Main function
int main() {
    // Initialize process data
    Process processes[] = {
        {1, 0, 5},
        {2, 2, 3},
        {3, 4, 2},
        {4, 6, 4},
        {5, 8, 1}
    };

    int num_processes = sizeof(processes) / sizeof(Process);

    // Run simulations for each scheduling algorithm
    for (SchedulingAlgorithm algorithm = FCFS; algorithm <= RR; algorithm++) {
        switch (algorithm) {
            case FCFS:
                printf("First-Come First-Served (FCFS)\n");
                break;
            case SJF:
                printf("Shortest Job First (SJF)\n");
                break;
            case RR:
                printf("Round Robin (RR)\n");
                break;
        }

        // Run simulation
        run_simulation(algorithm, processes, num_processes, MAX_TIME_SLICE);

        // Print results
        print_results(processes, num_processes);

        printf("\n");
    }

    return 0;
}

// Run simulation function
void run_simulation(SchedulingAlgorithm algorithm, Process processes[], int num_processes, int time_slice) {
    int current_time = 0;
    int completed_processes = 0;

    // Create a copy of the processes array to manipulate
    Process* processes_copy = malloc(sizeof(Process) * num_processes);
    memcpy(processes_copy, processes, sizeof(Process) * num_processes);

    // Repeat until all processes are completed
    while (completed_processes < num_processes) {
        // Get the next process to run
        Process* next_process = NULL;
        switch (algorithm) {
            case FCFS:
                // Select the process with the earliest arrival time
                for (int i = 0; i < num_processes; i++) {
                    if (processes_copy[i].arrival_time <= current_time && processes_copy[i].remaining_time > 0) {
                        if (next_process == NULL || processes_copy[i].arrival_time < next_process->arrival_time) {
                            next_process = &processes_copy[i];
                        }
                    }
                }
                break;
            case SJF:
                // Select the process with the shortest remaining time
                for (int i = 0; i < num_processes; i++) {
                    if (processes_copy[i].arrival_time <= current_time && processes_copy[i].remaining_time > 0) {
                        if (next_process == NULL || processes_copy[i].remaining_time < next_process->remaining_time) {
                            next_process = &processes_copy[i];
                        }
                    }
                }
                break;
            case RR:
                // Select the next process in the round robin queue
                for (int i = 0; i < num_processes; i++) {
                    if (processes_copy[i].arrival_time <= current_time && processes_copy[i].remaining_time > 0) {
                        next_process = &processes_copy[i];
                        break;
                    }
                }
                break;
        }

        // If there is a process to run, execute it
        if (next_process != NULL) {
            // Calculate the time the process will run for
            int time_to_run = time_slice;
            if (time_to_run > next_process->remaining_time) {
                time_to_run = next_process->remaining_time;
            }

            // Update process data
            next_process->remaining_time -= time_to_run;
            next_process->waiting_time += current_time - next_process->arrival_time - (next_process->burst_time - next_process->remaining_time);
            current_time += time_to_run;

            // If the process has finished, mark it as completed
            if (next_process->remaining_time == 0) {
                next_process->turnaround_time = current_time - next_process->arrival_time;
                completed_processes++;
            }
        } else {
            // If there are no processes to run, increment the current time
            current_time++;
        }
    }

    // Free the copy of the processes array
    free(processes_copy);
}

// Print results function
void print_results(Process processes[], int num_processes) {
    printf("Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("--------+--------------+-----------+-------------+----------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%7d | %13d | %9d | %12d | %15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}