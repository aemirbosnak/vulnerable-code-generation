//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>

#define MAX_PROCESSES 100

int processes[MAX_PROCESSES], burst_time[MAX_PROCESSES], arrival_time[MAX_PROCESSES], priority[MAX_PROCESSES];
int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES], completion_time[MAX_PROCESSES];
int total_waiting_time = 0, total_turnaround_time = 0, n;

void calculate_waiting_time(int quantum, int* remaining_time, int* waiting_time, int time) {
    int i, done = 1;
    while (done) {
        done = 0;
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i] - arrival_time[i];
                    remaining_time[i] = 0;
                    done = 1;
                }
            }
        }
    }
}

void fcfs_scheduling(int* arrival_time, int* burst_time, int n) {
    int i, time = 0;
    for (i = 0; i < n; i++) {
        if (arrival_time[i] > time)
            time = arrival_time[i];
        completion_time[i] = time + burst_time[i];
        waiting_time[i] = time - arrival_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        time = completion_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
}

void sjf_scheduling(int* arrival_time, int* burst_time, int n) {
    int i, shortest, time, remaining_time[MAX_PROCESSES];
    for (i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];
    time=0;
    while (1) {
        shortest = MAX_PROCESSES;
        for (i = 0; i < n; i++) {
            if ((arrival_time[i] <= time) && (remaining_time[i] < remaining_time[shortest]) && (remaining_time[i] > 0))
                shortest = i;
        }
        if (shortest == MAX_PROCESSES)
            break;
        completion_time[shortest] = time + remaining_time[shortest];
        waiting_time[shortest] = completion_time[shortest] - arrival_time[shortest] - burst_time[shortest];
        if (waiting_time[shortest] < 0)
            waiting_time[shortest] = 0;
        turnaround_time[shortest] = completion_time[shortest] - arrival_time[shortest];
        remaining_time[shortest] = 0;
        total_waiting_time += waiting_time[shortest];
        total_turnaround_time += turnaround_time[shortest];
        time += burst_time[shortest];        
    }
}

void priority_scheduling(int* arrival_time, int* burst_time, int* priority, int n) {
    int i, j, min, time, remaining_time[MAX_PROCESSES];
    for (i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];
    time=0;
    while (1) {
        min = MAX_PROCESSES;
        for (i = 0; i < n; i++) {
            if ((arrival_time[i] <= time) && (priority[i] < priority[min]) && (remaining_time[i] > 0))
                min = i;
        }
        if (min == MAX_PROCESSES)
            break;
        completion_time[min] = time + remaining_time[min];
        waiting_time[min] = completion_time[min] - arrival_time[min] - burst_time[min];
        if (waiting_time[min] < 0)
            waiting_time[min] = 0;
        turnaround_time[min] = completion_time[min] - arrival_time[min];
        remaining_time[min] = 0;
        total_waiting_time += waiting_time[min];
        total_turnaround_time += turnaround_time[min];
        time += burst_time[min];        
    }
}

void main() {
    int i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time, arrival time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &burst_time[i], &arrival_time[i], &priority[i]);
        processes[i] = i+1;
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    //FCFS Scheduling Algorithm
    printf("\nFCFS Scheduling Algorithm:\n");
    fcfs_scheduling(arrival_time, burst_time, n);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %d\n", total_waiting_time/n);
    printf("Average turnaround time: %d\n", total_turnaround_time/n);

    //SJF Scheduling Algorithm
    total_waiting_time = total_turnaround_time = 0;
    printf("\nSJF Scheduling Algorithm:\n");
    sjf_scheduling(arrival_time, burst_time, n);
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %d\n", total_waiting_time/n);
    printf("Average turnaround time: %d\n", total_turnaround_time/n);
    
    //Priority Scheduling Algorithm
    total_waiting_time = total_turnaround_time = 0;
    printf("\nPriority Scheduling Algorithm:\n");
    priority_scheduling(arrival_time, burst_time, priority, n);
    printf("Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %d\n", total_waiting_time/n);
    printf("Average turnaround time: %d\n", total_turnaround_time/n);
    
    //Round Robin Scheduling Algorithm
    total_waiting_time = total_turnaround_time = 0;
    printf("\nRound Robin Scheduling Algorithm:\n");
    int remaining_time[MAX_PROCESSES];
    for (i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];
    calculate_waiting_time(quantum, remaining_time, waiting_time, 0);
    for (i = 0; i < n; i++)
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average waiting time: %d\n", total_waiting_time/n);
    printf("Average turnaround time: %d\n", total_turnaround_time/n);
}