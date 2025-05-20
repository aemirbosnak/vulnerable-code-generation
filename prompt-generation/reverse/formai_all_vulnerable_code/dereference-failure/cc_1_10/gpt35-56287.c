//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROCESS_COUNT 5

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

typedef struct PriorityQueue {
    int size;
    int capacity;
    Process* data;
} PriorityQueue;

PriorityQueue* create_priority_queue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (Process*) malloc(capacity * sizeof(Process));
    return pq;
}

void enqueue(PriorityQueue* pq, Process proc) {
    if (pq->size == pq->capacity) {
        printf("Priority queue full!\n");
        return;
    }
    int i = pq->size;
    while (i > 0 && pq->data[i-1].priority < proc.priority) {
        pq->data[i] = pq->data[i-1];
        i--;
    }
    pq->data[i] = proc;
    pq->size++;
}

Process dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue empty!\n");
        Process empty_proc = {-1, -1, -1, -1};
        return empty_proc;
    }
    Process proc = pq->data[0];
    pq->size--;
    for (int i = 0; i < pq->size; i++) {
        pq->data[i] = pq->data[i+1];
    }
    return proc;
}

void print_priority_queue(PriorityQueue* pq) {
    printf("Process Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("[PID: %d, Priority: %d]", pq->data[i].pid, pq->data[i].priority);
        if (i != pq->size-1) {
            printf(", ");
        }
    }
    printf("\n");
}

void print_gantt_chart(Process* processes, int* bt, int* ct, int n) {
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("+--");
        for (int j = 0; j < ct[i] - bt[i]; j++) {
            printf("-");
        }
        printf("|P%d", processes[i].pid);
        for (int j = 0; j < ct[i] - bt[i]; j++) {
            printf("-");
        }
    }
    printf("+\n");
}

void sjf_np(Process* processes, int n) {
    int wt[n];
    int bt[n], ct[n];
    PriorityQueue* pq = create_priority_queue(n);
    int total_time = 0;
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
    }
    while (current_time < total_time) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time == current_time) {
                enqueue(pq, processes[i]);
            }
        }
        if (pq->size == 0) {
            printf("CPU idle at time %d\n", current_time);
            current_time++;
            continue;
        }
        Process proc = dequeue(pq);
        printf("Process with PID %d started at time %d.\n", proc.pid, current_time);
        bt[proc.pid] = current_time;
        current_time += proc.burst_time;
        ct[proc.pid] = current_time;
        wt[proc.pid] = ct[proc.pid] - bt[proc.pid] - proc.burst_time;
        printf("Process with PID %d exited at time %d with %d waiting time.\n", proc.pid, current_time, wt[proc.pid]);
    }
    print_gantt_chart(processes, bt, ct, n);
}

int main() {
    Process processes[PROCESS_COUNT] = {
        {0, 0, 5, 2},
        {1, 1, 3, 1},
        {2, 2, 8, 0},
        {3, 3, 6, 3},
        {4, 4, 4, 4}
    };
    sjf_np(processes, PROCESS_COUNT);
    return 0;
}