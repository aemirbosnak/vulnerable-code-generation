//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shape-shifting variable declaration
typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

// First Come, First Served (FCFS) Scheduling Algorithm
void fcfs(Process* process_list, int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_execution_time = 0;

    for(int i = 0; i < num_processes; i++) {
        total_waiting_time += total_execution_time - process_list[i].arrival_time;
        total_turnaround_time += total_execution_time + process_list[i].burst_time - process_list[i].arrival_time;
        total_execution_time += process_list[i].burst_time;
    }

    printf("FCFS Scheduling Algorithm Results:\n");
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / num_processes);
}

// Round Robin (RR) Scheduling Algorithm
void rr(Process* process_list, int num_processes, int time_slice) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_execution_time = 0;
    int* remaining_burst_times = (int*)malloc(num_processes * sizeof(int));

    for(int i = 0; i < num_processes; i++) {
        remaining_burst_times[i] = process_list[i].burst_time;
    }

    while(1) {
        int all_processes_completed = 1;

        for(int i = 0; i < num_processes; i++) {
            if(remaining_burst_times[i] > 0) {
                all_processes_completed = 0;

                if(remaining_burst_times[i] > time_slice) {
                    total_execution_time += time_slice;
                    remaining_burst_times[i] -= time_slice;
                } else {
                    total_execution_time += remaining_burst_times[i];
                    total_turnaround_time += total_execution_time - process_list[i].arrival_time;
                    total_waiting_time += total_execution_time - process_list[i].burst_time - process_list[i].arrival_time;
                    remaining_burst_times[i] = 0;
                }
            }
        }

        if(all_processes_completed == 1) {
            break;
        }
    }

    printf("Round Robin Scheduling Algorithm Results:\n");
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / num_processes);
}

// Preemptive Priority Scheduling Algorithm
void priority(Process* process_list, int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_execution_time = 0;
    int* remaining_burst_times = (int*)malloc(num_processes * sizeof(int));
    int* priority_order = (int*)malloc(num_processes * sizeof(int));

    for(int i = 0; i < num_processes; i++) {
        remaining_burst_times[i] = process_list[i].burst_time;
        priority_order[i] = i;
    }

    for(int i = 0; i < num_processes; i++) {
        for(int j = i+1; j < num_processes; j++) {
            if(process_list[priority_order[i]].priority > process_list[priority_order[j]].priority) {
                int temp = priority_order[i];
                priority_order[i] = priority_order[j];
                priority_order[j] = temp;
            }
        }
    }

    while(1) {
        int all_processes_completed = 1;

        for(int i = 0; i < num_processes; i++) {
            int current_process = priority_order[i];

            if(remaining_burst_times[current_process] > 0) {
                all_processes_completed = 0;

                if(remaining_burst_times[current_process] == process_list[current_process].burst_time) {
                    total_waiting_time += total_execution_time - process_list[current_process].arrival_time;
                }

                remaining_burst_times[current_process] = remaining_burst_times[current_process] - 1;
                total_execution_time++;

                if(remaining_burst_times[current_process] == 0) {
                    total_turnaround_time += total_execution_time - process_list[current_process].arrival_time;
                }
            }
        }

        if(all_processes_completed == 1) {
            break;
        }
    }

    printf("Preemptive Priority Scheduling Algorithm Results:\n");
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / num_processes);
}

int main() {
    int num_processes = 3;
    Process* process_list = (Process*)malloc(num_processes * sizeof(Process));

    process_list[0].pid = 0;
    process_list[0].arrival_time = 0;
    process_list[0].burst_time = 8;
    process_list[0].priority = 3;

    process_list[1].pid = 1;
    process_list[1].arrival_time = 1;
    process_list[1].burst_time = 4;
    process_list[1].priority = 1;

    process_list[2].pid = 2;
    process_list[2].arrival_time = 2;
    process_list[2].burst_time = 9;
    process_list[2].priority = 2;

    fcfs(process_list, num_processes);
    rr(process_list, num_processes, 3);
    priority(process_list, num_processes);

    free(process_list);

    return 0;
}