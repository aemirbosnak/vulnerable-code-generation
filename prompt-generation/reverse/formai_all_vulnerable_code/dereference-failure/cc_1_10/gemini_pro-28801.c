//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Structure to store process information
typedef struct Process {
    int pid;       // Process ID
    int arrival;  // Arrival time
    int burst;    // Burst time
    int priority; // Priority
    int remaining; // Remaining burst time
} Process;

// Function to compare processes by arrival time
int compare_arrival(const void *a, const void *b) {
    const Process *pa = (const Process *)a;
    const Process *pb = (const Process *)b;
    return pa->arrival - pb->arrival;
}

// Function to compare processes by burst time
int compare_burst(const void *a, const void *b) {
    const Process *pa = (const Process *)a;
    const Process *pb = (const Process *)b;
    return pa->burst - pb->burst;
}

// Function to compare processes by priority
int compare_priority(const void *a, const void *b) {
    const Process *pa = (const Process *)a;
    const Process *pb = (const Process *)b;
    return pa->priority - pb->priority;
}

// Function to implement FCFS (First Come First Serve) scheduling algorithm
void fcfs(Process *processes, int n) {
    int total_time = 0; // Total time taken to complete all processes
    int waiting_time = 0; // Total waiting time of all processes

    // Sort processes by arrival time
    qsort(processes, n, sizeof(Process), compare_arrival);

    // Iterate through processes
    for (int i = 0; i < n; i++) {
        // Calculate waiting time
        waiting_time += total_time - processes[i].arrival;

        // Update total time
        total_time += processes[i].burst;
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)waiting_time / n;

    // Print results
    printf("FCFS Scheduling Algorithm\n");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

// Function to implement SJF (Shortest Job First) scheduling algorithm
void sjf(Process *processes, int n) {
    int total_time = 0;
    int waiting_time = 0;

    // Sort processes by burst time
    qsort(processes, n, sizeof(Process), compare_burst);

    // Iterate through processes
    for (int i = 0; i < n; i++) {
        // Calculate waiting time
        waiting_time += total_time - processes[i].arrival;

        // Update total time
        total_time += processes[i].burst;
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)waiting_time / n;

    // Print results
    printf("SJF Scheduling Algorithm\n");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

// Function to implement priority scheduling algorithm
void priority(Process *processes, int n) {
    int total_time = 0;
    int waiting_time = 0;

    // Sort processes by priority
    qsort(processes, n, sizeof(Process), compare_priority);

    // Iterate through processes
    for (int i = 0; i < n; i++) {
        // Calculate waiting time
        waiting_time += total_time - processes[i].arrival;

        // Update total time
        total_time += processes[i].burst;
    }

    // Calculate average waiting time
    float avg_waiting_time = (float)waiting_time / n;

    // Print results
    printf("Priority Scheduling Algorithm\n");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

// Function to generate a random set of processes
Process *generate_processes(int n) {
    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival = rand() % 10;
        processes[i].burst = rand() % 10 + 1;
        processes[i].priority = rand() % 10 + 1;
        processes[i].remaining = processes[i].burst;
    }

    return processes;
}

// Function to print a list of processes
void print_processes(Process *processes, int n) {
    printf("Process List:\n");
    printf("PID\tArrival\tBurst\tPriority\tRemaining\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival,
               processes[i].burst,
               processes[i].priority,
               processes[i].remaining);
    }
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate a set of 10 random processes
    int n = 10;
    Process *processes = generate_processes(n);

    // Print the list of processes
    print_processes(processes, n);

    // Implement FCFS scheduling algorithm
    fcfs(processes, n);

    // Implement SJF scheduling algorithm
    sjf(processes, n);

    // Implement priority scheduling algorithm
    priority(processes, n);

    // Free the allocated memory
    free(processes);

    return 0;
}