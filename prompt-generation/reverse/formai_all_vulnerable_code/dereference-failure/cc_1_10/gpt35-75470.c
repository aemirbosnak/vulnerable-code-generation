//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Process struct */
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
};

/* Function to swap two processes */
void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to sort processes based on arrival time */
void sort_arrival_time(struct process *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j+1].arrival_time) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

/* Function to sort processes based on priority */
void sort_priority(struct process *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j+1].priority) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

/* Function to display the processes */
void display(struct process *p, int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority);
    }
}

/* Function for First-Come-First-Serve (FCFS) */
void fcfs(struct process *p, int n) {
    printf("\n\n---First-Come-First-Serve (FCFS)---\n\n");
    int total_waiting_time = 0;
    double average_waiting_time = 0.0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            total_waiting_time = p[i].arrival_time;
        }
        else {
            if (p[i].arrival_time > total_waiting_time) {
                total_waiting_time += p[i].arrival_time - total_waiting_time;
            }
        }
        total_waiting_time += p[i].burst_time;
    }
    average_waiting_time = (double)total_waiting_time / n;
    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Average Waiting Time: %.2lf\n", average_waiting_time);
}

/* Function for Shortest Job First (SJF) */
void sjf(struct process *p, int n) {
    printf("\n\n---Shortest Job First (SJF)---\n\n");
    sort_arrival_time(p, n);
    int waiting_time[n];
    int total_waiting_time = 0;
    double average_waiting_time = 0.0;
    int completed_time[n];
    int t = p[0].arrival_time;
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (p[j].arrival_time <= t && p[j].burst_time < p[min_index].burst_time) {
                min_index = j;
            }
        }
        swap(&p[min_index], &p[i]);
        t += p[i].burst_time;
        completed_time[i] = t;
    }
    for (int i = 0; i < n; i++) {
        waiting_time[i] = completed_time[i] - p[i].arrival_time - p[i].burst_time;
        total_waiting_time += waiting_time[i];
    }
    average_waiting_time = (double)total_waiting_time / n;
    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Average Waiting Time: %.2lf\n", average_waiting_time);
}

/* Function for Priority Scheduling (PS) */
void ps(struct process *p, int n) {
    printf("\n\n---Priority Scheduling (PS)---\n\n");
    sort_arrival_time(p, n);
    int waiting_time[n];
    int total_waiting_time = 0;
    double average_waiting_time = 0.0;
    int completed_time[n];
    int t = p[0].arrival_time;
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (p[j].arrival_time <= t && p[j].priority < p[min_index].priority) {
                min_index = j;
            }
        }
        swap(&p[min_index], &p[i]);
        t += p[i].burst_time;
        completed_time[i] = t;
    }
    for (int i = 0; i < n; i++) {
        waiting_time[i] = completed_time[i] - p[i].arrival_time - p[i].burst_time;
        total_waiting_time += waiting_time[i];
    }
    average_waiting_time = (double)total_waiting_time / n;
    printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Average Waiting Time: %.2lf\n", average_waiting_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter Priority: ");
        scanf("%d", &p[i].priority);
    }
    display(p, n);
    fcfs(p, n);
    sjf(p, n);
    ps(p, n);
    return 0;
}