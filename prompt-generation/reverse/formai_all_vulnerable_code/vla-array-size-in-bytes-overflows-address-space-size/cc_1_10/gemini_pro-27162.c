//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdlib.h>
#include <stdio.h>

// Process structure
typedef struct {
    int pid;         // Process ID
    int arrival_time; // Arrival time
    int burst_time;  // Burst time
    int priority;    // Priority
} Process;

// Compare function for processes
int compare_processes(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to find the waiting time for a process
int waiting_time(Process *processes, int n, int pid) {
    int waiting = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].pid == pid) {
            for (int j = 0; j < i; j++) {
                if (processes[j].burst_time > 0) {
                    waiting += processes[j].burst_time;
                }
            }
            break;
        }
    }
    return waiting;
}

// Function to find the turnaround time for a process
int turnaround_time(Process *processes, int n, int pid) {
    return waiting_time(processes, n, pid) + processes[pid - 1].burst_time;
}

// Function to find the average waiting time for all processes
float average_waiting_time(Process *processes, int n) {
    float total_waiting = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += waiting_time(processes, n, processes[i].pid);
    }
    return total_waiting / n;
}

// Function to find the average turnaround time for all processes
float average_turnaround_time(Process *processes, int n) {
    float total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround += turnaround_time(processes, n, processes[i].pid);
    }
    return total_turnaround / n;
}

// Function to print the results
void print_results(Process *processes, int n) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority,
               waiting_time(processes, n, processes[i].pid), turnaround_time(processes, n, processes[i].pid));
    }
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time(processes, n));
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time(processes, n));
}

int main() {
    // Input the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    Process processes[n];

    // Input the details of each process
    for (int i = 0; i < n; i++) {
        printf("Enter the details of Process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    // Sort the processes according to their arrival times
    qsort(processes, n, sizeof(Process), compare_processes);

    // Print the results
    print_results(processes, n);

    return 0;
}