//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a process
struct Process {
    int id;              // Process ID
    int arrival_time;    // Arrival time of the process
    int burst_time;      // Burst time of the process
    int waiting_time;    // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
};

// Function to compare processes based on arrival time
int compareArrival(const void *a, const void *b) {
    return ((struct Process*)a)->arrival_time - ((struct Process*)b)->arrival_time;
}

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waiting_time = 0;  // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// Function to calculate average waiting and turnaround times
void calculateAverageTimes(struct Process processes[], int n) {
    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time,
               processes[i].turnaround_time);
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

// Main function to execute the CPU Scheduling simulation
int main() {
    int n; // Number of processes

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assigning process ID
        printf("\nEnter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Sort processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compareArrival);

    // Calculate waiting time
    calculateWaitingTime(processes, n);

    // Calculate turnaround time
    calculateTurnaroundTime(processes, n);

    // Display the average waiting and turnaround times
    calculateAverageTimes(processes, n);

    return 0;
}