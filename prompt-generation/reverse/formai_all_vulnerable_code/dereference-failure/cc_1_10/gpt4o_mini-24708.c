//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].burst_time + proc[i - 1].waiting_time;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void findavgTimeFCFS(struct Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

void sortByBurstTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void findavgTimeSJF(struct Process proc[], int n) {
    sortByBurstTime(proc, n); // Sort processes according to burst time
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    printf("\nSJF Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process *proc = (struct Process *)malloc(n * sizeof(struct Process));
    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        proc[i].id = i + 1; // Assign Process ID
        scanf("%d", &(proc[i].burst_time));
    }

    findavgTimeFCFS(proc, n);
    findavgTimeSJF(proc, n);
    
    free(proc);
    return 0;
}