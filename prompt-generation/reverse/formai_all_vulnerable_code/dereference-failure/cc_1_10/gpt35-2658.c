//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// process structure
struct Process {
    int pid; // process id
    int burst_time; // amount of time the process requires to complete its execution
    int arrival_time; // time at which the process arrived in the ready queue
    int priority; // priority of the process
    int waiting_time; // time the process waited in the ready queue
    int turnaround_time; // time taken by the process from arrival to completion
    int completion_time; // time at which the process completed its execution
};

// function prototype for sorting an array of processes based on arrival time
void sort_by_arrival_time(struct Process *p, int n);

int main() {
    int num_processes; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    // dynamically allocate memory for the processes
    struct Process *processes = (struct Process *)malloc(num_processes * sizeof(struct Process));
    if(processes == NULL) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }
    
    // get process information
    printf("Enter the burst time and priority for each process.");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &(processes[i].burst_time));
        printf("Priority: ");
        scanf("%d", &(processes[i].priority));
        processes[i].pid = i+1;
    }
    
    // sort processes by arrival time
    sort_by_arrival_time(processes, num_processes);
    
    // initialize waiting time for the first process to 0
    processes[0].waiting_time = 0;
    
    // calculate waiting time and turnaround time for each process
    for(int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i-1].completion_time - processes[i].arrival_time;
        if(processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }
    }
    
    // calculate completion time and turnaround time for each process
    for(int i = 0; i < num_processes; i++) {
        processes[i].completion_time = processes[i].burst_time + processes[i].waiting_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
    
    // calculate average waiting time and turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i = 0; i < num_processes; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    
    // print process information and statistics
    printf("\nProcess Information:\n");
    printf("PID  BT  Priority  AT  WT  TAT  CT\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%2d   %2d   %2d       %2d  %2d  %2d   %2d\n", processes[i].pid, processes[i].burst_time,
               processes[i].priority, processes[i].arrival_time, processes[i].waiting_time,
               processes[i].turnaround_time, processes[i].completion_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    
    // free memory
    free(processes);
    
    return 0;
}

void sort_by_arrival_time(struct Process *p, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}