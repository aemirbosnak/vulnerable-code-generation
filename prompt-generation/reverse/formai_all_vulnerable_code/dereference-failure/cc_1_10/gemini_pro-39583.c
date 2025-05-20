//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// The types of CPU scheduling algorithms.
typedef enum {
    FIRST_COME_FIRST_SERVE,
    SHORTEST_JOB_FIRST,
    PRIORITY_SCHEDULING,
    ROUND_ROBIN
} scheduling_algorithm;

// The struct for a process.
typedef struct {
    int arrival_time;
    int burst_time;
    int priority;
} process;

// The struct for a CPU scheduling algorithm.
typedef struct {
    scheduling_algorithm algorithm;
    process *processes;
    int num_processes;
    int current_time;
    int current_process;
} cpu_scheduling;

// Function to create a new CPU scheduling algorithm.
cpu_scheduling *create_cpu_scheduling(scheduling_algorithm algorithm, process *processes, int num_processes) {
    cpu_scheduling *cpu_scheduling = malloc(sizeof(cpu_scheduling));
    cpu_scheduling->algorithm = algorithm;
    cpu_scheduling->processes = processes;
    cpu_scheduling->num_processes = num_processes;
    cpu_scheduling->current_time = 0;
    cpu_scheduling->current_process = -1;
    return cpu_scheduling;
}

// Function to execute a CPU scheduling algorithm.
void execute_cpu_scheduling(cpu_scheduling *cpu_scheduling) {
    while (cpu_scheduling->current_process != -1 || cpu_scheduling->current_time < cpu_scheduling->processes[cpu_scheduling->num_processes - 1].arrival_time) {
        // Get the next process to run.
        int next_process = -1;
        switch (cpu_scheduling->algorithm) {
            case FIRST_COME_FIRST_SERVE:
                for (int i = 0; i < cpu_scheduling->num_processes; i++) {
                    if (cpu_scheduling->processes[i].arrival_time <= cpu_scheduling->current_time && (next_process == -1 || cpu_scheduling->processes[i].arrival_time < cpu_scheduling->processes[next_process].arrival_time)) {
                        next_process = i;
                    }
                }
                break;
            case SHORTEST_JOB_FIRST:
                for (int i = 0; i < cpu_scheduling->num_processes; i++) {
                    if (cpu_scheduling->processes[i].arrival_time <= cpu_scheduling->current_time && (next_process == -1 || cpu_scheduling->processes[i].burst_time < cpu_scheduling->processes[next_process].burst_time)) {
                        next_process = i;
                    }
                }
                break;
            case PRIORITY_SCHEDULING:
                for (int i = 0; i < cpu_scheduling->num_processes; i++) {
                    if (cpu_scheduling->processes[i].arrival_time <= cpu_scheduling->current_time && (next_process == -1 || cpu_scheduling->processes[i].priority < cpu_scheduling->processes[next_process].priority)) {
                        next_process = i;
                    }
                }
                break;
            case ROUND_ROBIN:
                for (int i = 0; i < cpu_scheduling->num_processes; i++) {
                    if (cpu_scheduling->processes[i].arrival_time <= cpu_scheduling->current_time && (next_process == -1 || cpu_scheduling->processes[i].burst_time > 0)) {
                        next_process = i;
                    }
                }
                break;
        }

        // If there is a next process to run, run it.
        if (next_process != -1) {
            cpu_scheduling->current_process = next_process;
            cpu_scheduling->processes[cpu_scheduling->current_process].burst_time--;
            cpu_scheduling->current_time++;

            // If the current process has finished running, remove it from the list of processes.
            if (cpu_scheduling->processes[cpu_scheduling->current_process].burst_time == 0) {
                for (int i = cpu_scheduling->current_process; i < cpu_scheduling->num_processes - 1; i++) {
                    cpu_scheduling->processes[i] = cpu_scheduling->processes[i + 1];
                }
                cpu_scheduling->num_processes--;
                cpu_scheduling->current_process = -1;
            }
        } else {
            // If there is no next process to run, increment the current time.
            cpu_scheduling->current_time++;
        }
    }
}

// Function to print the results of a CPU scheduling algorithm.
void print_results(cpu_scheduling *cpu_scheduling) {
    printf("The results of the CPU scheduling algorithm are as follows:\n");
    for (int i = 0; i < cpu_scheduling->num_processes; i++) {
        printf("Process %d: %d %d %d\n", i, cpu_scheduling->processes[i].arrival_time, cpu_scheduling->processes[i].burst_time, cpu_scheduling->processes[i].priority);
    }
}

// Main function.
int main() {
    // Create a set of processes.
    process processes[] = {
        {0, 5, 0},
        {1, 2, 1},
        {2, 3, 2},
        {3, 1, 3}
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    // Create a CPU scheduling algorithm.
    cpu_scheduling *cpu_scheduling = create_cpu_scheduling(ROUND_ROBIN, processes, num_processes);

    // Execute the CPU scheduling algorithm.
    execute_cpu_scheduling(cpu_scheduling);

    // Print the results of the CPU scheduling algorithm.
    print_results(cpu_scheduling);

    // Free the memory used by the CPU scheduling algorithm.
    free(cpu_scheduling);

    return 0;
}