//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int priority;        // Priority
    int waiting_time;    // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Function to compare processes by arrival time
int compare_by_arrival_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to compare processes by priority
int compare_by_priority(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->priority - p2->priority;
}

// Function to calculate waiting time
void calculate_waiting_time(Process *processes, int n) {
    int current_time = 0;  // Current time
    int total_waiting_time = 0;  // Total waiting time

    for (int i = 0; i < n; i++) {
        // Calculate waiting time for each process
        processes[i].waiting_time = current_time - processes[i].arrival_time;

        // Update total waiting time
        total_waiting_time += processes[i].waiting_time;

        // Update current time
        current_time += processes[i].burst_time;
    }

    // Calculate average waiting time
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
}

// Function to calculate turnaround time
void calculate_turnaround_time(Process *processes, int n) {
    int total_turnaround_time = 0;  // Total turnaround time

    for (int i = 0; i < n; i++) {
        // Calculate turnaround time for each process
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // Update total turnaround time
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Calculate average turnaround time
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}

// Function to print gantt chart
void print_gantt_chart(Process *processes, int n) {
    int current_time = 0;  // Current time

    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        // Print process ID and burst time
        printf("P%d: [%d, %d]\n", processes[i].pid, current_time, current_time + processes[i].burst_time);

        // Update current time
        current_time += processes[i].burst_time;
    }
}

// Main function
int main() {
    // Get number of processes
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Create array of processes
    Process processes[n];

    // Get process details
    for (int i = 0; i < n; i++) {
        printf("Enter process ID, arrival time, burst time, and priority: ");
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }

    // Sort processes by arrival time
    qsort(processes, n, sizeof(Process), compare_by_arrival_time);

    // Calculate waiting time
    calculate_waiting_time(processes, n);

    // Calculate turnaround time
    calculate_turnaround_time(processes, n);

    // Print gantt chart
    print_gantt_chart(processes, n);

    return 0;
}