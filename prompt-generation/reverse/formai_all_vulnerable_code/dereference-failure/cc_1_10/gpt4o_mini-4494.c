//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for first process is 0
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(Process proc[], int n) {
    int bt[n]; 
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
    }

    int wt[n], tat[n];
   
    findWaitingTime(proc, n, bt, wt);
    findTurnAroundTime(proc, n, bt, wt, tat);
    
    float total_wt = 0;
    float total_tat = 0;
  
    printf("\nProcesses  Burst Time  Waiting",
           " Time  Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("  %d\t\t%d\t\t%d\t\t%d\n",
               proc[i].id, proc[i].burst_time,
               wt[i], tat[i]);
    }
  
    printf("\nAverage waiting time = %.2f", total_wt / n);
    printf("\nAverage turn-around time = %.2f\n", total_tat / n);
}

void roundRobin(Process proc[], int n, int quantum) {
    int bt[n];
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
    }
  
    int time = 0; 
    int done;
    printf("\nProcess execution order:\n");
  
    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (bt[i] > 0) {
                done = 0; // Still has remaining burst time
                if (bt[i] > quantum) {
                    time += quantum;
                    bt[i] -= quantum;
                } else {
                    time += bt[i];
                    printf("P[%d] ", proc[i].id);
                    bt[i] = 0; // Process finished
                }
            }
        }
        if (done) {
            break;
        }
    }
    printf("\nTotal time taken: %d\n", time);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];
  
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        proc[i].id = i + 1;
        scanf("%d", &proc[i].burst_time);
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
    }
  
    // Scheduling
    printf("\nFirst Come First Serve (FCFS) Scheduling:\n");
    findavgTime(proc, n);
    
    int quantum;
    printf("\nEnter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);
    
    printf("\nRound Robin Scheduling:\n");
    roundRobin(proc, n, quantum);

    return 0;
}