//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculate_waiting_times(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void fcfs(Process *processes, int n) {
    int current_time = 0;
    printf("\nFCFS Scheduling:\n");
    
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        
        printf("Process %d: Completion Time = %d, Turnaround Time = %d, Waiting Time = %d\n",
               processes[i].process_id, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }
    
    calculate_waiting_times(processes, n);
}

void sjn(Process *processes, int n) {
    // Sort processes by burst time, then by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time || 
               (processes[i].burst_time == processes[j].burst_time && processes[i].arrival_time > processes[j].arrival_time)) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    fcfs(processes, n); // Reuse FCFS for simplicity in calculating times
    printf("\nSJN Scheduling:\n");
}

void round_robin(Process *processes, int n, int quantum) {
    printf("\nRound Robin Scheduling:\n");
    int remaining_burst[n], current_time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        remaining_burst[i] = processes[i].burst_time;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0 && processes[i].arrival_time <= current_time) {
                if (remaining_burst[i] > quantum) {
                    current_time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    current_time += remaining_burst[i];
                    processes[i].completion_time = current_time;
                    remaining_burst[i] = 0;
                    completed++;
                }
            }
        }
    }
    
    calculate_waiting_times(processes, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: Completion Time = %d, Turnaround Time = %d, Waiting Time = %d\n",
               processes[i].process_id, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n, i, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Process %d:\n", i + 1);
        processes[i].process_id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].completion_time = 0; // initialize
    }

    printf("\nEnter quantum time for Round Robin: ");
    scanf("%d", &quantum);

    fcfs(processes, n);
    sjn(processes, n);
    round_robin(processes, n, quantum);

    free(processes);
    return 0;
}