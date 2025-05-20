//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
} Process;

int main() {
    int n, quantum_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &quantum_time);

    Process* processes = (Process*)malloc(n * sizeof(Process));
    for(int i=0; i<n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }

    int current_time = 0, total_waiting_time = 0, completed_processes = 0;
    while(completed_processes < n) {
        for(int i=0; i<n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if(processes[i].remaining_time <= quantum_time) {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    completed_processes++;
                } else {
                    current_time += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                }
            }
        }
    }

    double average_waiting_time = (double)total_waiting_time / (double)n;
    printf("\nTotal waiting time: %d", total_waiting_time);
    printf("\nAverage waiting time: %lf", average_waiting_time);

    return 0;
}