//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

// Function to calculate average waiting and turnaround time
void calculate_average_time(process p[], int n) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;
    
    // Calculate waiting and turnaround time for each process
    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    
    // Calculate and print average waiting and turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);
}

// Function for first-come-first-serve (FCFS) scheduling algorithm
void fcfs(process p[], int n) {
    int i, total_waiting_time = 0;
    p[0].waiting_time = 0; // First process has zero waiting time
    
    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        total_waiting_time += p[i].waiting_time;
    }
    
    // Print waiting and turnaround time for each process
    printf("FCFS Scheduling Algorithm\n");
    for (i = 0; i < n; i++) {
        printf("Process %d - Waiting Time: %d Burst Time: %d Turnaround Time: %d\n", 
                p[i].pid, p[i].waiting_time, p[i].burst_time, p[i].turnaround_time);
    }
    // Calculate and print average waiting and turnaround time
    calculate_average_time(p, n);
}

// Function for shortest-job-first (SJF) scheduling algorithm
void sjf(process p[], int n) {
    int i, j, smallest;
    
    // Sort processes by burst time
    for (i = 0; i < n-1; i++) {
        smallest = i;
        for (j = i+1; j < n; j++) {
            if (p[j].burst_time < p[smallest].burst_time) {
                smallest = j;
            }
        }
        // Swap processes
        process temp = p[i];
        p[i] = p[smallest];
        p[smallest] = temp;
    }
    // Calculate waiting time for each process
    for (i = 0; i < n; i++) {
        p[i].waiting_time = 0;
        for (j = 0; j < i; j++) {
            p[i].waiting_time += p[j].burst_time;
        }
    }
    // Print waiting and turnaround time for each process
    printf("SJF Scheduling Algorithm\n");
    for (i = 0; i < n; i++) {
        printf("Process %d - Waiting Time: %d Burst Time: %d Turnaround Time: %d\n", 
                p[i].pid, p[i].waiting_time, p[i].burst_time, p[i].turnaround_time);
    }
    // Calculate and print average waiting and turnaround time
    calculate_average_time(p, n);
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n]; // Creating an array of process structures
    
    // Taking inputs of burst times for each process
    for (i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1; // Assigning process IDs
    }
    fcfs(p, n); // Running FCFS algorithm
    sjf(p, n); // Running SJF algorithm
    return 0;
}