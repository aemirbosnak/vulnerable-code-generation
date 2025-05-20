//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // Process ID
    int burst;     // Burst Time
    int arrival;   // Arrival Time
    int waiting;   // Waiting Time
    int turnaround; // Turnaround Time
} Process;

// Function to calculate waiting and turnaround times for FCFS
void calculateFCFS(Process *processes, int n) {
    processes[0].waiting = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }
}

// Function to calculate waiting and turnaround times for SJF
void calculateSJF(Process *processes, int n) {
    // Sort processes according to burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst > processes[j].burst) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    processes[0].waiting = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }
}

// Function to calculate waiting and turnaround times for Round Robin
void calculateRR(Process *processes, int n, int quantum) {
    int remainingBurst[n];
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = processes[i].burst;
    }

    int time = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                if (remainingBurst[i] > quantum) {
                    time += quantum;
                    remainingBurst[i] -= quantum;
                } else {
                    time += remainingBurst[i];
                    processes[i].waiting = time - processes[i].burst - processes[i].arrival;
                    remainingBurst[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }
}

// Function to display process information
void displayProcesses(Process *processes, int n) {
    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("    %d      |     %d     |      %d      |       %d\n", 
               processes[i].id, processes[i].burst,
               processes[i].waiting, processes[i].turnaround);
    }
}

int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process IDs start from 1
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst);
        processes[i].arrival = 0; // For simplicity, set arrival time to 0
    }

    printf("Choose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            calculateFCFS(processes, n);
            break;
        case 2:
            calculateSJF(processes, n);
            break;
        case 3:
            printf("Enter quantum time for Round Robin: ");
            scanf("%d", &quantum);
            calculateRR(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            free(processes);
            return 1;
    }

    displayProcesses(processes, n);

    free(processes);
    return 0;
}