//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining burst time
} Process;

// CPU Scheduling Algorithm
typedef enum Algorithm {
    FCFS,    // First-Come First-Served
    SJF,     // Shortest Job First
    SRTF,    // Shortest Remaining Time First
    RR       // Round-Robin
} Algorithm;

// CPU Scheduler
void schedule(Process *processes, int num_processes, Algorithm algorithm, int quantum) {
    // Initialize simulation parameters
    int time = 0;
    int completed = 0;
    int waiting_time = 0;
    int turnaround_time = 0;

    // Create a queue to store the processes
    Process *queue = malloc(num_processes * sizeof(Process));
    int front = 0;
    int rear = -1;

    // Copy the processes into the queue
    for (int i = 0; i < num_processes; i++) {
        queue[++rear] = processes[i];
    }

    // Run the CPU scheduler
    while (completed < num_processes) {
        // Get the next process from the queue
        Process *process = &queue[front++];
        if (front > rear) {
            front = rear = -1;
        }

        // Update the process's remaining time
        process->remaining -= quantum;

        // Check if the process has finished executing
        if (process->remaining <= 0) {
            // Calculate the process's waiting time and turnaround time
            waiting_time += time - process->arrival - process->burst;
            turnaround_time += time - process->arrival;

            // Increment the number of completed processes
            completed++;
        } else {
            // Put the process back into the queue
            queue[++rear] = *process;
        }

        // Increment the time
        time += quantum;
    }

    // Calculate the average waiting time and turnaround time
    float avg_waiting_time = (float) waiting_time / num_processes;
    float avg_turnaround_time = (float) turnaround_time / num_processes;

    // Print the results
    printf("CPU Scheduling Algorithm: %s\n", algorithm == FCFS ? "FCFS" : algorithm == SJF ? "SJF" : algorithm == SRTF ? "SRTF" : "RR");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    // Free the queue
    free(queue);
}

int main() {
    // Create a set of processes
    Process processes[] = {
        {1, 0, 4},
        {2, 2, 2},
        {3, 4, 3},
        {4, 6, 1}
    };
    int num_processes = sizeof(processes) / sizeof(Process);

    // Schedule the processes using different algorithms
    schedule(processes, num_processes, FCFS, 0);
    schedule(processes, num_processes, SJF, 0);
    schedule(processes, num_processes, SRTF, 0);
    schedule(processes, num_processes, RR, 2);

    return 0;
}