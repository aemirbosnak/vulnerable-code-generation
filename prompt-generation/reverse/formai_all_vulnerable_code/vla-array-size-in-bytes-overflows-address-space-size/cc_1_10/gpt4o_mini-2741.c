//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, burst_time, arrival_time, waiting_time, turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int bt[], int wt[]);
void calculateTurnaroundTime(Process processes[], int n);
void findavgTime(Process processes[], int n, int q);
void fcfs(Process processes[], int n);
void sjn(Process processes[], int n);
void roundRobin(Process processes[], int n, int quantum);
void printProcesses(Process processes[], int n);

int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    printf("\nChoose CPU Scheduling Algorithm:\n");
    printf("1. First-Come-First-Served (FCFS)\n");
    printf("2. Shortest Job Next (SJN)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nFirst-Come-First-Served Scheduling:\n");
            fcfs(processes, n);
            break;
        case 2:
            printf("\nShortest Job Next Scheduling:\n");
            sjn(processes, n);
            break;
        case 3:
            printf("\nRound Robin Scheduling:\n");
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            roundRobin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void fcfs(Process processes[], int n) {
    int waiting_time[n], turnaround_time[n];
    calculateWaitingTime(processes, n, processes->burst_time, waiting_time);
    calculateTurnaroundTime(processes, n);
    
    printProcesses(processes, n);
}

void sjn(Process processes[], int n) {
    // Sorting by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfs(processes, n);
}

void roundRobin(Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int t = 0; // current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // If a process is still remaining
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    calculateTurnaroundTime(processes, n);
    printProcesses(processes, n);
}

void calculateWaitingTime(Process processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // waiting time for first process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id,
               processes[i].burst_time, processes[i].arrival_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}