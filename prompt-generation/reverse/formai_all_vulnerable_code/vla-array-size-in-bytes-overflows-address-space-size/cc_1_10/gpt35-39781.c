//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    bool is_completed;
};

void shortest_job_first(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    int minimum_burst_time = 999999;
    int shortest_job_index = 0;
    
    while(completed != n) {
        for(int i=0; i<n; i++) {
            if(processes[i].arrival_time <= current_time && 
            processes[i].burst_time < minimum_burst_time && 
            processes[i].is_completed == false) {
                minimum_burst_time = processes[i].burst_time;
                shortest_job_index = i;
            }
        }
        
        processes[shortest_job_index].completion_time = current_time + processes[shortest_job_index].burst_time;
        processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;
        processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;
        processes[shortest_job_index].is_completed = true;
        minimum_burst_time = 999999;
        completed++;
        current_time = processes[shortest_job_index].completion_time;
    }
    
    printf("\n");
    printf("%-10s %-15s %-15s %-15s %-15s %-15s\n", "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time");
    printf("-------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("%-10d %-15d %-15d %-15d %-15d %-15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for(int i=0; i<n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].is_completed = false;
    }
    
    shortest_job_first(processes, n);
}