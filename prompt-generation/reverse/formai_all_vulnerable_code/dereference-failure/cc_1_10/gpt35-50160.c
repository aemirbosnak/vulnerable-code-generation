//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

int main() {

    int n, quantum_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *p = (struct process*) malloc(sizeof(struct process)*n);

    printf("Enter the arrival and burst time for each process:\n");
    for(int i=0; i<n; i++) {
        printf("Process %d:\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
        p[i].remaining_time = p[i].burst_time;
    }

    printf("Enter the time quantum for the Round Robin Scheduling algorithm: ");
    scanf("%d", &quantum_time);

    int time = 0; // Current time
    int completed = 0; // Number of completed processes
    int remaining = n; // Number of remaining processes
    int waiting_time_total = 0; // Total waiting time
    int turnaround_time_total = 0; // Total turnaround time

    // Execute processes in round-robin fashion
    while(remaining != 0) {
        for(int i=0; i<n; i++) {
            if(p[i].remaining_time > 0) {
                if(p[i].remaining_time > quantum_time) {
                    // Process executes for quantum_time
                    time += quantum_time;
                    p[i].remaining_time -= quantum_time;
                }
                else {
                    // Process completes execution
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    completed++;
                    remaining--;
                    // Calculate waiting time and turnaround time
                    p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    waiting_time_total += p[i].waiting_time;
                    turnaround_time_total += p[i].turnaround_time;
                }
            }
        }
    }

    // Calculate and print average waiting time and turnaround time
    float avg_waiting_time = (float)waiting_time_total / n;
    float avg_turnaround_time = (float)turnaround_time_total / n;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    return 0;
}