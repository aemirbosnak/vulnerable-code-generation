//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;            // Process ID
    int burst_time;     // Burst time of the process
    int remaining_time; // Remaining time of the process
    int waiting_time;   // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
} Process;

void find_waiting_time(Process proc[], int n, int quantum) {
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    time += proc[i].remaining_time;
                    proc[i].waiting_time += (time - proc[i].burst_time);
                    proc[i].remaining_time = 0;
                    proc[i].turnaround_time = time;
                    remaining_processes--;
                }
            }
        }
    }
}

void find_turnaround_time(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void calculate_average_times(Process proc[], int n) {
    float total_waiting_time = 0.0;
    float total_turnaround_time = 0.0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void display_processes(Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].pid, 
               proc[i].burst_time, 
               proc[i].waiting_time, 
               proc[i].turnaround_time);
    }
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process *proc = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1; // Process ID starts from 1
        printf("Enter burst time for Process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    find_waiting_time(proc, n, quantum);
    find_turnaround_time(proc, n);
    display_processes(proc, n);
    calculate_average_times(proc, n);

    free(proc);
    return 0;
}