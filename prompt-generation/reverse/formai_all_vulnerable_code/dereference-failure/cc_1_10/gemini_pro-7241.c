//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid; 
    int arrival_time; 
    int burst_time; 
    int waiting_time; 
    int turnaround_time;
    int completion_time;
    int response_time; 
    int priority; 
} process;

void swap(process *a, process *b) {
    process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_processes(process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculate_waiting_time(process *processes, int n) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculate_turnaround_time(process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_completion_time(process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = processes[i].turnaround_time + processes[i].arrival_time;
    }
}

void calculate_response_time(process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].response_time = processes[i].waiting_time;
    }
}

void calculate_average_waiting_time(process *processes, int n) {
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    printf("Average waiting time: %f\n", (float)total_waiting_time / n);
}

void calculate_average_turnaround_time(process *processes, int n) {
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
}

void calculate_average_completion_time(process *processes, int n) {
    int total_completion_time = 0;
    for (int i = 0; i < n; i++) {
        total_completion_time += processes[i].completion_time;
    }
    printf("Average completion time: %f\n", (float)total_completion_time / n);
}

void calculate_average_response_time(process *processes, int n) {
    int total_response_time = 0;
    for (int i = 0; i < n; i++) {
        total_response_time += processes[i].response_time;
    }
    printf("Average response time: %f\n", (float)total_response_time / n);
}

void print_processes(process *processes, int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\tResponse Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time, processes[i].response_time, processes[i].priority);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &processes[i].priority);
    }
    sort_processes(processes, n);
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    calculate_completion_time(processes, n);
    calculate_response_time(processes, n);
    calculate_average_waiting_time(processes, n);
    calculate_average_turnaround_time(processes, n);
    calculate_average_completion_time(processes, n);
    calculate_average_response_time(processes, n);
    print_processes(processes, n);
    return 0;
}