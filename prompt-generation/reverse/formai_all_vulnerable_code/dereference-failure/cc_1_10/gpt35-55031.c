//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold process information
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
    int remaining_time; // Remaining time for the process
};

// Function to swap two process pointers
void swap(struct Process *p1, struct Process *p2)
{
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to implement the 'First-Come, First-Served (FCFS)' scheduling algorithm
void FCFS(struct Process *processes, int n)
{
    int current_time = processes[0].arrival_time; // Current time is set to the arrival time of the first process
    
    // Loop through each process
    for (int i = 0; i < n; i++) {
        // If the current time is less than the arrival time of the process, update the current time to the arrival time of the process
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        // Update the process completion time, turnaround time, and waiting time
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        // Update the current time to the completion time of the process
        current_time = processes[i].completion_time;
    }
}

// Function to implement the 'Shortest-Job-First (SJF)' scheduling algorithm
void SJF(struct Process *processes, int n)
{
    int current_time = processes[0].arrival_time; // Current time is set to the arrival time of the first process
    
    // Loop through each process
    for (int i = 0; i < n; i++) {
        // Find the process with the shortest remaining time
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].remaining_time < processes[min_index].remaining_time) {
                min_index = j;
            }
        }
        
        // Swap the shortest remaining time process with the current process
        swap(&processes[i], &processes[min_index]);
        
        // Update the process completion time, turnaround time, and waiting time
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        // Update the current time to the completion time of the process
        current_time = processes[i].completion_time;
    }
}

// Function to implement the 'Round-Robin (RR)' scheduling algorithm
void RR(struct Process *processes, int n, int time_quantum)
{
    int current_time = processes[0].arrival_time; // Current time is set to the arrival time of the first process
    
    // Loop until all processes are completed
    while (1) {
        int done = 1; // Flag to indicate if all processes are completed
        
        // Loop through each process
        for (int i = 0; i < n; i++) {
            // If the process has remaining time
            if (processes[i].remaining_time > 0) {
                done = 0; // Set the flag to indicate that a process is not completed
                
                // If the remaining time of the process is less than or equal to the time quantum
                if (processes[i].remaining_time <= time_quantum) {
                    // Update the process completion time, turnaround time, and waiting time
                    current_time += processes[i].remaining_time;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    
                    // Set the remaining time of the process to 0
                    processes[i].remaining_time = 0;
                }
                // If the remaining time of the process is greater than the time quantum
                else {
                    // Update the process remaining time
                    processes[i].remaining_time -= time_quantum;
                    
                    // Update the current time with the time quantum
                    current_time += time_quantum;
                }
            }
        }
        
        // If all processes are completed, break the loop
        if (done == 1) {
            break;
        }
    }
}

// Function to print the process scheduling information
void print_schedule(struct Process *processes, int n)
{
    printf("Process ID  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-11d  %-12d  %-10d  %-15d  %-15d  %-12d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

// Main function
int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    int n = 5; // Number of processes
    
    // Allocate memory for the array of processes
    struct Process *processes = (struct Process*)malloc(n * sizeof(struct Process));
    
    // Generate random arrival and burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].remaining_time = processes[i].burst_time; // Set the remaining time to the burst time
    }
    
    printf("Processes before scheduling:\n");
    print_schedule(processes, n);
    
    FCFS(processes, n); // Call the FCFS scheduling algorithm
    printf("\nProcesses after FCFS scheduling:\n");
    print_schedule(processes, n);
    
    SJF(processes, n); // Call the SJF scheduling algorithm
    printf("\nProcesses after SJF scheduling:\n");
    print_schedule(processes, n);
    
    RR(processes, n, 2); // Call the RR scheduling algorithm with a time quantum of 2
    printf("\nProcesses after RR scheduling:\n");
    print_schedule(processes, n);
    
    free(processes); // Free the memory allocated for the array of processes
    
    return 0; // Return 0 to indicate successful execution of the program
}