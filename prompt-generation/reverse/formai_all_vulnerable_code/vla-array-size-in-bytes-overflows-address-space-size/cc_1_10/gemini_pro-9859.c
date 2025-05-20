//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} process;

int compare_arrival_time(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;
    return p1->arrival_time - p2->arrival_time;
}

int compare_priority(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;
    return p1->priority - p2->priority;
}

void fcfs(process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("FCFS\n");
    printf("Average waiting time: %.2f\n", (double)total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n\n", (double)total_turnaround_time / num_processes);
}

void sjf(process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    while (num_processes > 0) {
        int shortest_remaining_time = -1;
        int shortest_remaining_time_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && (shortest_remaining_time == -1 || processes[i].remaining_time < shortest_remaining_time)) {
                shortest_remaining_time = processes[i].remaining_time;
                shortest_remaining_time_index = i;
            }
        }
        processes[shortest_remaining_time_index].remaining_time -= 1;
        current_time += 1;
        if (processes[shortest_remaining_time_index].remaining_time == 0) {
            processes[shortest_remaining_time_index].turnaround_time = current_time - processes[shortest_remaining_time_index].arrival_time;
            total_turnaround_time += processes[shortest_remaining_time_index].turnaround_time;
            num_processes -= 1;
        }
    }
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }
    printf("SJF\n");
    printf("Average waiting time: %.2f\n", (double)total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n\n", (double)total_turnaround_time / num_processes);
}

void priority(process processes[], int num_processes) {
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    while (num_processes > 0) {
        int highest_priority = -1;
        int highest_priority_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && (highest_priority == -1 || processes[i].priority > highest_priority)) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }
        processes[highest_priority_index].remaining_time -= 1;
        current_time += 1;
        if (processes[highest_priority_index].remaining_time == 0) {
            processes[highest_priority_index].turnaround_time = current_time - processes[highest_priority_index].arrival_time;
            total_turnaround_time += processes[highest_priority_index].turnaround_time;
            num_processes -= 1;
        }
    }
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }
    printf("Priority\n");
    printf("Average waiting time: %.2f\n", (double)total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n\n", (double)total_turnaround_time / num_processes);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
    qsort(processes, num_processes, sizeof(process), compare_arrival_time);
    fcfs(processes, num_processes);
    qsort(processes, num_processes, sizeof(process), compare_arrival_time);
    sjf(processes, num_processes);
    qsort(processes, num_processes, sizeof(process), compare_priority);
    priority(processes, num_processes);
    return 0;
}