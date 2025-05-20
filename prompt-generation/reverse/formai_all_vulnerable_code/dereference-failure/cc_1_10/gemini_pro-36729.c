//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the process structure
typedef struct process {
    int pid;         // Process ID
    int arrivalTime; // Arrival time
    int burstTime;    // Burst time
    int priority;    // Priority
    int remainingTime;// Remaining time
    int waitingTime; // Waiting time
    int turnaroundTime;// Turnaround time
} process;

// Function to find the waiting time for each process
void findWaitingTime(process processes[], int n) {
    // Initialize the waiting time of all processes to 0
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = 0;
    }

    // Calculate the waiting time for each process
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

// Function to find the turnaround time for each process
void findTurnaroundTime(process processes[], int n) {
    // Calculate the turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to find the average waiting time and average turnaround time
void findAvgTime(process processes[], int n) {
    // Initialize the average waiting time and average turnaround time to 0
    float avgWaitingTime = 0.0;
    float avgTurnaroundTime = 0.0;

    // Calculate the average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Print the average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", avgWaitingTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

// Function to print the Gantt chart
void printGanttChart(process processes[], int n) {
    // Initialize the Gantt chart
    char ganttChart[100] = "";

    // Add the processes to the Gantt chart
    for (int i = 0; i < n; i++) {
        char processName[10];
        sprintf(processName, "P%d", processes[i].pid);
        strcat(ganttChart, processName);
        strcat(ganttChart, "|");
    }

    // Print the Gantt chart
    printf("Gantt chart: %s\n", ganttChart);
}

// Main function
int main() {
    // Initialize the processes
    process processes[] = {
        {1, 0, 5, 1},
        {2, 2, 3, 2},
        {3, 4, 4, 3},
        {4, 6, 2, 4},
        {5, 8, 1, 5},
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort the processes according to their arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Find the waiting time for each process
    findWaitingTime(processes, n);

    // Find the turnaround time for each process
    findTurnaroundTime(processes, n);

    // Find the average waiting time and average turnaround time
    findAvgTime(processes, n);

    // Print the Gantt chart
    printGanttChart(processes, n);

    return 0;
}