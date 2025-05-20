//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int start_time;
    int finish_time;
    int turnaround_time;
    int waiting_time;
} process_t;

void fcfs(process_t *processes, int num_processes);
void sjf(process_t *processes, int num_processes);
void rr(process_t *processes, int num_processes);

int main(int argc, char *argv[]) {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    // Allocate memory for the array of processes
    process_t *processes = (process_t*)malloc(sizeof(process_t) * num_processes);
    // Input the details of each process
    for(int i=0; i<num_processes; i++) {
        printf("Process %d:\n", i+1);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        processes[i].pid = i+1;
    }
    // Invoke the required scheduling algorithm
    printf("\nSelect a scheduling algorithm:\n");
    printf("1. First Come, First Serve\n");
    printf("2. Shortest Job First\n");
    printf("3. Round Robin\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            fcfs(processes, num_processes);
            break;
        case 2:
            sjf(processes, num_processes);
            break;
        case 3:
            rr(processes, num_processes);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    // Print the details of each process
    printf("PID\tBurst Time\tArrival Time\tStart Time\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].start_time, processes[i].finish_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    // Free the memory allocated for the array of processes
    free(processes);
    return 0;
}

void fcfs(process_t *processes, int num_processes) {
    // Sort the processes by arrival time
    for(int i=0; i<num_processes-1; i++) {
        for(int j=0; j<num_processes-i-1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                process_t temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    // Calculate the start and finish times of each process
    int current_time = processes[0].arrival_time;
    for(int i=0; i<num_processes; i++) {
        processes[i].start_time = current_time;
        current_time += processes[i].burst_time;
        processes[i].finish_time = current_time;
        processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void sjf(process_t *processes, int num_processes) {
    // Sort the processes by burst time
    for(int i=0; i<num_processes-1; i++) {
        for(int j=0; j<num_processes-i-1; j++) {
            if(processes[j].burst_time > processes[j+1].burst_time) {
                process_t temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    // Calculate the start and finish times of each process
    int current_time = processes[0].arrival_time;
    for(int i=0; i<num_processes; i++) {
        processes[i].start_time = current_time;
        current_time += processes[i].burst_time;
        processes[i].finish_time = current_time;
        processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void rr(process_t *processes, int num_processes) {
    int quantum;
    printf("Enter Quantum: ");
    scanf("%d", &quantum);
    // Sort the processes by arrival time
    for(int i=0; i<num_processes-1; i++) {
        for(int j=0; j<num_processes-i-1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                process_t temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    // Assign the initial values to the remaining variables of each process
    for(int i=0; i<num_processes; i++) {
        processes[i].start_time = -1;
        processes[i].finish_time = -1;
        processes[i].turnaround_time = -1;
        processes[i].waiting_time = -1;
    }
    // Implement Round Robin
    int current_time = processes[0].arrival_time;
    int num_completed = 0;
    int *remaining_times = (int*)malloc(sizeof(int) * num_processes);
    memset(remaining_times, 0, sizeof(int) * num_processes);
    for(int i=0; i<num_processes; i++) {
        remaining_times[i] = processes[i].burst_time;
    }
    while(num_completed < num_processes) {
        for(int i=0; i<num_processes; i++) {
            if(processes[i].arrival_time <= current_time && remaining_times[i] > 0) {
                if(processes[i].start_time == -1) {
                    processes[i].start_time = current_time;
                }
                if(remaining_times[i] <= quantum) {
                    current_time += remaining_times[i];
                    processes[i].finish_time = current_time;
                    processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    remaining_times[i] = 0;
                    num_completed++;
                }
                else {
                    current_time += quantum;
                    remaining_times[i] -= quantum;
                }
            }
        }
    }
    free(remaining_times);
}