//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void findWaitingTime(Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
    }
}

void findTurnaroundTime(Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void findavgTime(Process processes[], int n) {
    int waiting_time[n], turnaround_time[n];

    findWaitingTime(processes, n, waiting_time);
    findTurnaroundTime(processes, n, waiting_time, turnaround_time);

    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int compareArrivalTime(const void *a, const void *b) {
    return ((Process*)a)->arrival_time - ((Process*)b)->arrival_time;
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process *processes = malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }
    
    // Sort processes based on arrival time
    qsort(processes, n, sizeof(Process), compareArrivalTime);

    findavgTime(processes, n);
    
    free(processes);
    return 0;
}