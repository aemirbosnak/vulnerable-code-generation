//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void findWaitingTime(Process proc[], int n, int burst[], int quantum) {
    int remBurst[n];
    for (int i = 0; i < n; i++) {
        remBurst[i] = burst[i];
    }

    int t = 0; // Current time
    while (1) {
        int done = 1; // To check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remBurst[i] > 0) {
                done = 0; // Still processes remain

                if (remBurst[i] > quantum) {
                    t += quantum;
                    remBurst[i] -= quantum;
                } else {
                    t = t + remBurst[i];
                    proc[i].waitingTime = t - proc[i].burstTime - proc[i].arrivalTime;
                    remBurst[i] = 0;
                }
            }
        }
        if (done == 1) {
            break; // Exit when all processes are done
        }
    }
}

void findTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].waitingTime + proc[i].burstTime;
    }
}

void calculateAverageTimes(Process proc[], int n) {
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnaroundTime += proc[i].turnaroundTime;
    }

    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

void printProcesses(Process proc[], int n) {
    printf("ProcessID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
           proc[i].processID, 
           proc[i].burstTime, 
           proc[i].arrivalTime, 
           proc[i].waitingTime, 
           proc[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *proc = (Process *)malloc(n * sizeof(Process));
    int burst[n];
    int quantum;

    for (int i = 0; i < n; i++) {
        proc[i].processID = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].burstTime, &proc[i].arrivalTime);
        burst[i] = proc[i].burstTime; // Store burst time in temp array
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    findWaitingTime(proc, n, burst, quantum);
    findTurnaroundTime(proc, n);
    calculateAverageTimes(proc, n);
    printProcesses(proc, n);

    free(proc); 
    return 0;
}