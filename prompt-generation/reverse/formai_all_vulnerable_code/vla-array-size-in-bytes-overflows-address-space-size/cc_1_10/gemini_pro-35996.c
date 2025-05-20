//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// A process with its arrival time, burst time, and priority
typedef struct Process {
    int arrival_time;
    int burst_time;
    int priority;
} Process;

// A queue of processes
typedef struct Queue {
    Process *arr;
    int front;
    int rear;
    int size;
} Queue;

// Initialize a queue
void init_queue(Queue *q, int size) {
    q->arr = (Process *)malloc(sizeof(Process) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->front == -1;
}

// Enqueue
void enqueue(Queue *q, Process p) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = p;
}

// Dequeue
Process dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return (Process){-1, -1, -1};
    }
    Process p = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return p;
}

// Compare processes based on priority
int compare_priority(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->priority - p2->priority;
}

// CPU Scheduling Algorithms
void fcfs(Process *p, int n) {
    int time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        waiting_time += time - p[i].arrival_time;
        time += p[i].burst_time;
        turnaround_time += time - p[i].arrival_time;
    }
    printf("FCFS: Average waiting time = %.2f\n", (float)waiting_time / n);
    printf("FCFS: Average turnaround time = %.2f\n", (float)turnaround_time / n);
}

void sjf(Process *p, int n) {
    // Sort the processes based on burst time
    qsort(p, n, sizeof(Process), compare_priority);

    int time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        waiting_time += time - p[i].arrival_time;
        time += p[i].burst_time;
        turnaround_time += time - p[i].arrival_time;
    }
    printf("SJF: Average waiting time = %.2f\n", (float)waiting_time / n);
    printf("SJF: Average turnaround time = %.2f\n", (float)turnaround_time / n);
}

void priority(Process *p, int n) {
    // Sort the processes based on priority
    qsort(p, n, sizeof(Process), compare_priority);

    int time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        waiting_time += time - p[i].arrival_time;
        time += p[i].burst_time;
        turnaround_time += time - p[i].arrival_time;
    }
    printf("Priority: Average waiting time = %.2f\n", (float)waiting_time / n);
    printf("Priority: Average turnaround time = %.2f\n", (float)turnaround_time / n);
}

// Main
int main() {
    // Input
    int n;
    scanf("%d", &n);
    Process p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
    }

    // FCFS
    fcfs(p, n);

    // Shortest Job First (SJF)
    sjf(p, n);

    // Priority
    priority(p, n);

    return 0;
}