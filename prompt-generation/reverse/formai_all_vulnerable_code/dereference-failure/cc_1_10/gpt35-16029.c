//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Process structure containing process id, burst time, arrival time and waiting time
struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
};

// Queue structure containing array of processes and size of queue
struct Queue {
    struct Process *arr;
    int size;
};

// Function to calculate waiting time and turn around time for First Come First Serve scheduling algorithm
void fcfs(struct Process *p, int n) {
    int total_time = 0;
    int i, j;
    // Calculate waiting time for each process
    for (i = 0; i < n; i++) {
        p[i].waiting_time = total_time - p[i].arrival_time;
        total_time += p[i].burst_time;
    }
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    // Calculate average waiting time and turn around time
    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].waiting_time + p[i].burst_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("FCFS scheduling algorithm:\n");
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].waiting_time + p[i].burst_time);
    }
    printf("Average Waiting Time: %f\nAverage Turn Around Time: %f\n\n", avg_waiting_time, avg_turnaround_time);
}

// Function to sort processes by burst time for Shortest Job First scheduling algorithm
void sjf_sort(struct Process *p, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].burst_time > p[j+1].burst_time) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turn around time for Shortest Job First scheduling algorithm
void sjf(struct Process *p, int n) {
    int i, j;
    sjf_sort(p, n);
    int total_time = 0;
    // Calculate waiting time for each process
    for (i = 0; i < n; i++) {
        p[i].waiting_time = total_time - p[i].arrival_time;
        total_time += p[i].burst_time;
    }
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    // Calculate average waiting time and turn around time
    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].waiting_time + p[i].burst_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Shortest Job First scheduling algorithm:\n");
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].waiting_time + p[i].burst_time);
    }
    printf("Average Waiting Time: %f\nAverage Turn Around Time: %f\n\n", avg_waiting_time, avg_turnaround_time);
}

// Function to sort processes by burst time for Priority scheduling algorithm
void priority_sort(struct Process *p, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].burst_time > p[j+1].burst_time) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turn around time for Priority scheduling algorithm
void priority(struct Process *p, int n) {
    int i, j;
    priority_sort(p, n);
    int total_time = 0;
    // Calculate waiting time for each process
    for (i = 0; i < n; i++) {
        p[i].waiting_time = total_time - p[i].arrival_time;
        total_time += p[i].burst_time;
    }
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    // Calculate average waiting time and turn around time
    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].waiting_time + p[i].burst_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Priority scheduling algorithm:\n");
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].waiting_time + p[i].burst_time);
    }
    printf("Average Waiting Time: %f\nAverage Turn Around Time: %f\n\n", avg_waiting_time, avg_turnaround_time);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    // Create array of processes
    struct Process *p = (struct Process*)malloc(n * sizeof(struct Process));
    int i;
    // Get process details from user
    for (i = 0; i < n; i++) {
        printf("Details of Process %d:\n", i+1);
        p[i].pid = i+1;
        printf("Enter burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival_time);
    }
    fcfs(p, n);
    sjf(p, n);
    priority(p, n);
    free(p);
    return 0;
}