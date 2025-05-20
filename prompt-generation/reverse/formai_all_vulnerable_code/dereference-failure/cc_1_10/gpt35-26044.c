//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10
#define TIME_QUANTUM 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

struct queue {
    int front, rear, size;
    struct process* processes[MAX_PROCESS];
};

struct queue* create_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->size = 0;
    q->rear = MAX_PROCESS - 1;
    return q;
}

void enqueue(struct queue* q, struct process* p) {
    if (q->size == MAX_PROCESS) {
        printf("Queue is full.\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % MAX_PROCESS;
    q->processes[q->rear] = p;
    q->size++;
}

struct process* dequeue(struct queue* q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    struct process* p = q->processes[q->front];
    q->front = (q->front + 1) % MAX_PROCESS;
    q->size--;
    return p;
}

void fcfs(struct process* processes, int n) {
    int total_time = 0;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        struct process* p = &processes[i];
        p->completion_time = total_time + p->burst_time;
        p->turnaround_time = p->completion_time;
        p->waiting_time = total_time;
        total_time = p->completion_time;
        avg_waiting_time += p->waiting_time;
        avg_turnaround_time += p->turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("FCFS CPU Scheduling:\n");
    printf("PID     Burst Time     Waiting Time     Turnaround Time     Completion Time\n");
    for (int i = 0; i < n; i++) {
        struct process* p = &processes[i];
        printf("%-7d%-15d%-18d%-22d%-15d\n", p->pid, p->burst_time, p->waiting_time, p->turnaround_time, p->completion_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n\n", avg_turnaround_time);
}

void sjf(struct process* processes, int n) {
    int total_time = 0;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        struct process* p = &processes[i];
        p->completion_time = total_time + p->burst_time;
        p->turnaround_time = p->completion_time;
        p->waiting_time = total_time;
        total_time = p->completion_time;
        avg_waiting_time += p->waiting_time;
        avg_turnaround_time += p->turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("SJF CPU Scheduling:\n");
    printf("PID     Burst Time     Waiting Time     Turnaround Time     Completion Time\n");
    for (int i = 0; i < n; i++) {
        struct process* p = &processes[i];
        printf("%-7d%-15d%-18d%-22d%-15d\n", p->pid, p->burst_time, p->waiting_time, p->turnaround_time, p->completion_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n\n", avg_turnaround_time);
}

void rr(struct process* processes, int n) {
    struct queue* q = create_queue();
    int total_time = 0, time_quantum = TIME_QUANTUM;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        enqueue(q, &processes[i]);
    }
    while (q->size > 0) {
        struct process* p = dequeue(q);
        if (p->burst_time <= time_quantum) {
            total_time += p->burst_time;
            p->burst_time = 0;
            p->completion_time = total_time;
            p->turnaround_time = p->completion_time;
            p->waiting_time = total_time - time_quantum;
            avg_waiting_time += p->waiting_time;
            avg_turnaround_time += p->turnaround_time;
            printf("Process %d completed at time %d.\n", p->pid, total_time);
        } else {
            total_time += time_quantum;
            p->burst_time -= time_quantum;
            enqueue(q, p);
        }
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("RR CPU Scheduling:\n");
    printf("PID     Burst Time     Waiting Time     Turnaround Time     Completion Time\n");
    for (int i = 0; i < n; i++) {
        struct process* p = &processes[i];
        printf("%-7d%-15d%-18d%-22d%-15d\n", p->pid, p->burst_time, p->waiting_time, p->turnaround_time, p->completion_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n\n", avg_turnaround_time);
}

int main() {
    struct process processes[] = {
        {0, 10},
        {1, 5},
        {2, 15},
        {3, 7},
        {4, 20}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    fcfs(processes, n);
    sjf(processes, n);
    rr(processes, n);
    return 0;
}