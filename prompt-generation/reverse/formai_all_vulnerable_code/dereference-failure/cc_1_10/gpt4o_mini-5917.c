//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int processID;       // Loving heart's identifier
    int arrivalTime;     // The moment love arrived
    int burstTime;       // Duration love took to blossom
    int waitingTime;     // Moments spent waiting to be cherished
    int turnaroundTime;  // The total time love spent from arrival to goodbye
} Process;

void sortProcessesByArrival(Process *proc, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrivalTime > proc[j + 1].arrivalTime) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculateWaitingAndTurnaroundTimes(Process *proc, int n) {
    proc[0].waitingTime = 0; // The first heart waits for nothing
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void displayProcessInfo(Process *proc, int n) {
    printf("Heart's Journey:\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].processID, proc[i].arrivalTime, proc[i].burstTime, proc[i].waitingTime, proc[i].turnaroundTime);
    }
}

int main() {
    printf("In a world where hearts beat in rhythm...\n\n");

    int n;
    printf("Enter the number of love stories (processes): ");
    scanf("%d", &n);

    Process *proc = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        proc[i].processID = i + 1; // Assigning a unique ID to each heart
        printf("\nEnter arrival time for Process %d: ", proc[i].processID);
        scanf("%d", &proc[i].arrivalTime);
        printf("Enter burst time for Process %d: ", proc[i].processID);
        scanf("%d", &proc[i].burstTime);
    }

    printf("\nSorting the love stories by their arrival time...\n");
    sortProcessesByArrival(proc, n);

    printf("Calculating waiting and turnaround times...\n");
    calculateWaitingAndTurnaroundTimes(proc, n);

    displayProcessInfo(proc, n);

    printf("\nLove's enchanting dance has ended...\n");
    printf("Each heart has found its time and space.\n");

    free(proc);
    return 0;
}