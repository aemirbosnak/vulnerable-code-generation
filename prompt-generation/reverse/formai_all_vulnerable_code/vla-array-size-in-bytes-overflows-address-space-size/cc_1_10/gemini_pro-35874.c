//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;         // Process ID
    int arrivalTime; // Arrival time
    int burstTime;   // Burst time
    int waitingTime; // Waiting time
    int turnaroundTime;// Turnaround time
    int completionTime;// Completion time
} Process;

// Comparator function for sorting processes by arrival time
int compareArrivalTime(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->arrivalTime - p2->arrivalTime;
}

// Comparator function for sorting processes by burst time
int compareBurstTime(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->burstTime - p2->burstTime;
}

// Function to calculate the waiting time of processes
void calculateWaitingTime(Process processes[], int n) {
    processes[0].waitingTime = 0;  // Waiting time of the first process is always 0

    // Calculate the waiting time of the remaining processes
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

// Function to calculate the turnaround time of processes
void calculateTurnaroundTime(Process processes[], int n) {
    // Calculate the turnaround time of each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to calculate the average waiting time and turnaround time
void calculateAverageTime(Process processes[], int n) {
    // Calculate the average waiting time
    float avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
    }
    avgWaitingTime /= n;

    // Calculate the average turnaround time
    float avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgTurnaroundTime /= n;

    // Print the average waiting time and turnaround time
    printf("Average waiting time: %.2f\n", avgWaitingTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

// Function to print the Gantt chart
void printGanttChart(Process processes[], int n) {
    // Calculate the completion time of each process
    for (int i = 0; i < n; i++) {
        processes[i].completionTime = processes[i].arrivalTime + processes[i].burstTime;
    }

    // Print the Gantt chart
    printf("Gantt chart:\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d [%d-%d] ", processes[i].pid, processes[i].arrivalTime, processes[i].completionTime);
    }
    printf("|\n");
    printf("------------------------------------------------------\n");
}

// Main function
int main() {
    // Get the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get the process details
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the process ID, arrival time, and burst time for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrivalTime, &processes[i].burstTime);
    }

    // Sort the processes by arrival time
    qsort(processes, n, sizeof(Process), compareArrivalTime);

    // Calculate the waiting time and turnaround time of the processes
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    // Print the Gantt chart
    printGanttChart(processes, n);

    // Calculate the average waiting time and turnaround time
    calculateAverageTime(processes, n);

    return 0;
}