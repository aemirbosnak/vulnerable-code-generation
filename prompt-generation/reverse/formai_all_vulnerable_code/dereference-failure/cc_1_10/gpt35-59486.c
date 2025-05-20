//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process structure to hold information about each process
typedef struct {
    int pid;    // process ID
    int arrival_time;   // time when the process arrives
    int burst_time; // CPU burst time required by the process
    int priority;   // priority of the process
} Process;

// Function to implement First Come First Served (FCFS) scheduling algorithm
void fcfs(Process* processes, int n) {
    int time = 0;   // current time
    int turnaround_time = 0;    // total turnaround time of all processes
    int wait_time = 0;  // total wait time of all processes
    
    // Loop through all processes in the order of their arrival time
    for (int i = 0; i < n; i++) {
        // Update the current time based on the arrival time of the process
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        
        // Calculate the wait time and turnaround time for this process
        int process_wait_time = time - processes[i].arrival_time;
        int process_turnaround_time = process_wait_time + processes[i].burst_time;
        
        // Add the wait time and turnaround time to the totals
        wait_time += process_wait_time;
        turnaround_time += process_turnaround_time;
        
        // Update the current time
        time += processes[i].burst_time;
        
        // Print the process details
        printf("Process %d - Arrival Time: %d, Burst Time: %d, Wait Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, process_wait_time, process_turnaround_time);
    }
    
    // Print the average wait time and turnaround time
    printf("Average Wait Time: %f, Average Turnaround Time: %f\n", (float) wait_time / n, (float) turnaround_time / n);
}

// Function to implement Shortest Job First (SJF) scheduling algorithm
void sjf(Process* processes, int n) {
    int time = 0;   // current time
    int turnaround_time = 0;    // total turnaround time of all processes
    int wait_time = 0;  // total wait time of all processes
    bool* completed = (bool*) malloc(sizeof(bool) * n);   // array to keep track of completed processes
    
    // Initialize all processes as not completed
    for (int i = 0; i < n; i++) {
        completed[i] = false;
    }
    
    // Loop until all processes are completed
    while (true) {
        int shortest_job = -1;  // index of the shortest job
        
        // Find the next shortest job
        for (int i = 0; i < n; i++) {
            if (!completed[i] && (shortest_job == -1 || processes[i].burst_time < processes[shortest_job].burst_time)) {
                shortest_job = i;
            }
        }
        
        // If there are no more incomplete processes, break out of the loop
        if (shortest_job == -1) {
            break;
        }
        
        // Update the time based on the burst time of the current process
        time += processes[shortest_job].burst_time;
        
        // Calculate the wait time and turnaround time for this process
        int process_wait_time = time - processes[shortest_job].arrival_time - processes[shortest_job].burst_time;
        int process_turnaround_time = process_wait_time + processes[shortest_job].burst_time;
        
        // Add the wait time and turnaround time to the totals
        wait_time += process_wait_time;
        turnaround_time += process_turnaround_time;
        
        // Mark the current process as completed
        completed[shortest_job] = true;
        
        // Print the process details
        printf("Process %d - Arrival Time: %d, Burst Time: %d, Wait Time: %d, Turnaround Time: %d\n", processes[shortest_job].pid, processes[shortest_job].arrival_time, processes[shortest_job].burst_time, process_wait_time, process_turnaround_time);
    }
    
    // Print the average wait time and turnaround time
    printf("Average Wait Time: %f, Average Turnaround Time: %f\n", (float) wait_time / n, (float) turnaround_time / n);
    
    // Free the memory allocated to the completed array
    free(completed);
}

// Function to implement Priority scheduling algorithm
void priority(Process* processes, int n) {
    int time = 0;   // current time
    int turnaround_time = 0;    // total turnaround time of all processes
    int wait_time = 0;  // total wait time of all processes
    bool* completed = (bool*) malloc(sizeof(bool) * n);   // array to keep track of completed processes
    
    // Initialize all processes as not completed
    for (int i = 0; i < n; i++) {
        completed[i] = false;
    }
    
    // Loop until all processes are completed
    while (true) {
        int highest_priority = -1;  // index of the process with the highest priority
        
        // Find the next process with the highest priority
        for (int i = 0; i < n; i++) {
            if (!completed[i] && (highest_priority == -1 || processes[i].priority > processes[highest_priority].priority)) {
                highest_priority = i;
            }
        }
        
        // If there are no more incomplete processes, break out of the loop
        if (highest_priority == -1) {
            break;
        }
        
        // Update the time based on the burst time of the current process
        time += processes[highest_priority].burst_time;
        
        // Calculate the wait time and turnaround time for this process
        int process_wait_time = time - processes[highest_priority].arrival_time - processes[highest_priority].burst_time;
        int process_turnaround_time = process_wait_time + processes[highest_priority].burst_time;
        
        // Add the wait time and turnaround time to the totals
        wait_time += process_wait_time;
        turnaround_time += process_turnaround_time;
        
        // Mark the current process as completed
        completed[highest_priority] = true;
        
        // Print the process details
        printf("Process %d - Arrival Time: %d, Burst Time: %d, Priority: %d, Wait Time: %d, Turnaround Time: %d\n", processes[highest_priority].pid, processes[highest_priority].arrival_time, processes[highest_priority].burst_time, processes[highest_priority].priority, process_wait_time, process_turnaround_time);
    }
    
    // Print the average wait time and turnaround time
    printf("Average Wait Time: %f, Average Turnaround Time: %f\n", (float) wait_time / n, (float) turnaround_time / n);
    
    // Free the memory allocated to the completed array
    free(completed);
}

int main() {
    // Example data for three processes
    Process processes[3] = {
        {1, 0, 5, 3},
        {2, 1, 3, 2},
        {3, 2, 8, 1}
    };
    
    printf("First Come First Served:\n");
    fcfs(processes, 3);
    
    printf("\nShortest Job First:\n");
    sjf(processes, 3);
    
    printf("\nPriority Scheduling:\n");
    priority(processes, 3);
    
    return 0;
}