//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnAroundTime = 0;
    }

    int complete = 0, time = 0;

    while (complete != n) {
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0 && processes[i].arrivalTime <= time) {
                if (remainingBurstTime[i] > quantum) {
                    time += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    time += remainingBurstTime[i];
                    processes[i].waitingTime = time - processes[i].arrivalTime - processes[i].burstTime;
                    remainingBurstTime[i] = 0;
                    complete++;
                    processes[i].turnAroundTime = time - processes[i].arrivalTime;
                }
            }
        }
    }
}

void displayProcesses(Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processID,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].waitingTime,
               processes[i].turnAroundTime);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n * sizeof(Process));

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, and Burst Time for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].processID, &processes[i].arrivalTime, &processes[i].burstTime);
    }

    calculateWaitingTime(processes, n, quantum);
    displayProcesses(processes, n);

    free(processes); // Free allocated memory
    return 0;
}