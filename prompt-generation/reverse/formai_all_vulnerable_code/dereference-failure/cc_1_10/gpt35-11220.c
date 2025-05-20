//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
} Process;

void FCFS(Process *proc, int n) {
    int waitingTime = 0, turnaroundTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        waitingTime += proc[i].burstTime;
        turnaroundTime += waitingTime;
        totalWaitingTime += waitingTime - proc[i].arrivalTime;
        totalTurnaroundTime += turnaroundTime - proc[i].arrivalTime;

    }
    printf("Average waiting time: %f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time: %f\n", (float)totalTurnaroundTime / n);
}

void SJF(Process *proc, int n) {
    int time = 0, totalWaitingTime = 0, totalTurnaroundTime = 0, completed = 0;
    while (completed != n) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (time >= proc[i].arrivalTime && proc[i].remainingTime != 0 && (shortest == -1 || proc[i].remainingTime < proc[shortest].remainingTime)) {
                shortest = i;
            }
        }
        if (shortest == -1) {
            printf("Idle at time %d\n", time);
            time++;
        } else {
            printf("Executing process %d at time %d\n", proc[shortest].pid, time);
            proc[shortest].remainingTime--;
            if (proc[shortest].remainingTime == 0) {
                int waitingTime = time - proc[shortest].arrivalTime - proc[shortest].burstTime + 1;
                int turnaroundTime = time - proc[shortest].arrivalTime;
                totalWaitingTime += waitingTime;
                totalTurnaroundTime += turnaroundTime;
                completed++;
                printf("Process %d completed at time %d. Waiting time: %d, Turnaround time: %d\n", proc[shortest].pid, time, waitingTime, turnaroundTime);
            }
            time++;
        }
    }
    printf("Average waiting time: %f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time: %f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process *proc = malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        printf("Process %d:\nEnter arrival time: ", i);
        scanf("%d", &proc[i].arrivalTime);
        printf("Enter burst time: ");
        scanf("%d", &proc[i].burstTime);
        proc[i].remainingTime = proc[i].burstTime;
        proc[i].pid = i;
    }

    printf("FCFS:\n");
    FCFS(proc, n);
    printf("\n");

    printf("SJF:\n");
    SJF(proc, n);

    return 0;
}