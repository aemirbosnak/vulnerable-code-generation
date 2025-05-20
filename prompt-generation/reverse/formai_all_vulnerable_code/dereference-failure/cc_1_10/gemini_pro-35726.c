//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Process structure
typedef struct Process {
    int pid;        // Process ID
    int arrival_time;  // Arrival time
    int burst_time;   // Burst time
    int priority;     // Priority
    int remaining_time; // Remaining time
    int response_time; // Response time
    int waiting_time;  // Waiting time
    int turnaround_time;// Turnaround time
} Process;

// Function to compare processes by arrival time
int compare_arrival_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to compare processes by burst time
int compare_burst_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->burst_time - p2->burst_time;
}

// Function to compare processes by priority
int compare_priority(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->priority - p2->priority;
}

// Function to find the waiting time for each process
void find_waiting_time(Process *processes, int n) {
    // Initialize the waiting time of the first process to 0
    processes[0].waiting_time = 0;
    
    // Calculate the waiting time of the remaining processes
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

// Function to find the turnaround time for each process
void find_turnaround_time(Process *processes, int n) {
    // Calculate the turnaround time of each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to find the average waiting time and turnaround time
void find_average_times(Process *processes, int n) {
    // Initialize the average waiting time and turnaround time to 0
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    
    // Calculate the average waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Print the average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Function to print the Gantt chart
void print_gantt_chart(Process *processes, int n) {
    // Create a string to store the Gantt chart
    char gantt_chart[1000];
    
    // Initialize the Gantt chart to empty
    memset(gantt_chart, ' ', sizeof(gantt_chart));
    
    // Add the processes to the Gantt chart
    for (int i = 0; i < n; i++) {
        for (int j = processes[i].arrival_time; j < processes[i].arrival_time + processes[i].burst_time; j++) {
            gantt_chart[j] = processes[i].pid + '0';
        }
    }
    
    // Print the Gantt chart
    printf("Gantt chart:\n%s\n", gantt_chart);
}

// Function to print the table of processes
void print_table(Process *processes, int n) {
    // Print the header of the table
    printf("%-5s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "PID", "Arrival Time", "Burst Time", "Priority", "Waiting Time", "Response Time", "Turnaround Time", "Completion Time");
    
    // Print the data for each process
    for (int i = 0; i < n; i++) {
        printf("%-5d %-10d %-10d %-10d %-10d %-10d %-10d %-10d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].response_time, processes[i].turnaround_time, processes[i].arrival_time + processes[i].burst_time);
    }
}

// Main function
int main() {
    // Get the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Get the details of each process
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("\n");
    }
    
    // Sort the processes by arrival time
    qsort(processes, n, sizeof(Process), compare_arrival_time);
    
    // Find the waiting time for each process
    find_waiting_time(processes, n);
    
    // Find the turnaround time for each process
    find_turnaround_time(processes, n);
    
    // Find the average waiting time and turnaround time
    find_average_times(processes, n);
    
    // Print the Gantt chart
    print_gantt_chart(processes, n);
    
    // Print the table of processes
    print_table(processes, n);
    
    return 0;
}