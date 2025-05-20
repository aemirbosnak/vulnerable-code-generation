//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;  // process id
    int burst_time;  // time required for executing the process
    int arrival_time;  // time at which the process arrives
    int waiting_time;  // time spent by the process in waiting queue
    int turnaround_time;  // time taken by the process for completion
};

// function to implement FCFS algorithm
void fcfs(struct Process processes[], int n) {
    int i, time = 0;  // initial time is 0
    float total_wait_time = 0, total_tat = 0;  // initialize total wait time and total turnaround time
    
    printf("\nFCFS Scheduling Algorithm:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (i = 0; i < n; i++) {
        if (processes[i].arrival_time > time) {
            // move time to the arrival time of the process
            time = processes[i].arrival_time;
        }
        processes[i].waiting_time = time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        time += processes[i].burst_time;
        total_wait_time += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time %f\n", total_wait_time / n);
    printf("Average Turnaround Time %f\n", total_tat / n);
}

// function to implement SJF algorithm
void sjf(struct Process processes[], int n) {
    int i, time = 0, shortest, count = 0;
    float total_wait_time = 0, total_tat = 0;
    int is_executed[n];

    for (i = 0; i < n; i++) {
        is_executed[i] = 0;  // mark all processes as not executed
    }

    printf("\nSJF Scheduling Algorithm:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (count < n) {
        shortest = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && !is_executed[i]) {
                if (shortest == -1 || processes[i].burst_time < processes[shortest].burst_time) {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {  // no process is ready to execute
            time++;  // increase time by 1
        } else {
            processes[shortest].waiting_time = time - processes[shortest].arrival_time;
            processes[shortest].turnaround_time = processes[shortest].burst_time + processes[shortest].waiting_time;
            time += processes[shortest].burst_time;
            total_wait_time += processes[shortest].waiting_time;
            total_tat += processes[shortest].turnaround_time;
            is_executed[shortest] = 1;  // mark the process as executed
            count++;
            printf("%d\t\t%d\t\t%d\t\t%d\n", processes[shortest].pid, processes[shortest].burst_time, processes[shortest].waiting_time, processes[shortest].turnaround_time);
        }
    }
    printf("Average Waiting Time %f\n", total_wait_time / n);
    printf("Average Turnaround Time %f\n", total_tat / n);
}

// function to implement Round Robin algorithm
void round_robin(struct Process processes[], int n, int time_quantum) {
    int i, time = 0, remaining_burst_time[n];
    int completed = 0;  // number of processes completed execution
    float total_wait_time = 0, total_tat = 0;
    
    // initialize remaining burst time for all processes
    for (i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    printf("\nRound Robin Scheduling Algorithm with time quantum=%d:\n", time_quantum);
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    // continue until all processes complete execution
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                // if process still has remaining burst time
                if (remaining_burst_time[i] > time_quantum) {
                    // if time quantum is less than remaining burst time
                    time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                    // if remaining burst time is less than or equal to time quantum
                    time += remaining_burst_time[i];
                    processes[i].waiting_time = time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    total_wait_time += processes[i].waiting_time;
                    total_tat += processes[i].turnaround_time;
                    remaining_burst_time[i] = 0;
                    completed++;
                    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
                }
            }
        }
    }
    printf("Average Waiting Time %f\n", total_wait_time / n);
    printf("Average Turnaround Time %f\n", total_tat / n);
}

int main() {
    int i, n, time_quantum;
    struct Process processes[100];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum for Round Robin Algorithm: ");
    scanf("%d", &time_quantum);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Burst Time and Arrival Time for Process %d: ", i+1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].burst_time, &processes[i].arrival_time);
    }

    // sort processes based on arrival time
    for (i = 0; i < n; i++) {
        int j;
        struct Process temp;
        for (j = i+1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    fcfs(processes, n);
    sjf(processes, n);
    round_robin(processes, n, time_quantum);

    return 0;
}