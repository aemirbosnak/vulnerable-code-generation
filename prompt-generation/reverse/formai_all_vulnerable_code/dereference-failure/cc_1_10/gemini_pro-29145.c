//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process structure
typedef struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int priority;   // Priority
    int remaining;  // Remaining burst time
} Process;

// Queue structure
typedef struct Queue {
    int front;
    int rear;
    int size;
    Process* arr;
} Queue;

// Initialize queue
void initQueue(Queue* q, int size) {
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (Process*)malloc(size * sizeof(Process));
}

// Check if queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1 || q->rear == -1;
}

// Check if queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % q->size == q->front;
}

// Enqueue a process
void enqueue(Queue* q, Process p) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->rear == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = p;
}

// Dequeue a process
Process dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return (Process){-1, -1, -1, -1, -1};
    }
    Process p = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return p;
}

// FCFS scheduling algorithm
void fcfs(Process* processes, int n) {
    printf("FCFS scheduling algorithm:\n");
    
    // Create a queue to store the processes
    Queue q;
    initQueue(&q, n);

    // Enqueue the processes in the order of arrival
    for (int i = 0; i < n; i++) {
        enqueue(&q, processes[i]);
    }

    // Dequeue the processes and execute them in the order of arrival
    while (!isEmpty(&q)) {
        Process p = dequeue(&q);
        printf("Executing process %d\n", p.pid);
    }
}

// SJF scheduling algorithm
void sjf(Process* processes, int n) {
    printf("SJF scheduling algorithm:\n");
    
    // Sort the processes in the order of burst time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst > processes[j].burst) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Create a queue to store the processes
    Queue q;
    initQueue(&q, n);

    // Enqueue the processes in the order of burst time
    for (int i = 0; i < n; i++) {
        enqueue(&q, processes[i]);
    }

    // Dequeue the processes and execute them in the order of burst time
    while (!isEmpty(&q)) {
        Process p = dequeue(&q);
        printf("Executing process %d\n", p.pid);
    }
}

// Priority scheduling algorithm
void priority(Process* processes, int n) {
    printf("Priority scheduling algorithm:\n");
    
    // Sort the processes in the order of priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Create a queue to store the processes
    Queue q;
    initQueue(&q, n);

    // Enqueue the processes in the order of priority
    for (int i = 0; i < n; i++) {
        enqueue(&q, processes[i]);
    }

    // Dequeue the processes and execute them in the order of priority
    while (!isEmpty(&q)) {
        Process p = dequeue(&q);
        printf("Executing process %d\n", p.pid);
    }
}

// Round robin scheduling algorithm
void roundRobin(Process* processes, int n, int quantum) {
    printf("Round robin scheduling algorithm:\n");
    
    // Create a queue to store the processes
    Queue q;
    initQueue(&q, n);

    // Initialize the remaining burst times of the processes
    for (int i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }

    // Enqueue the processes in the order of arrival
    for (int i = 0; i < n; i++) {
        enqueue(&q, processes[i]);
    }

    int time = 0;
    while (!isEmpty(&q)) {
        Process p = dequeue(&q);
        if (p.remaining <= quantum) {
            // Execute the process
            time += p.remaining;
            printf("Executing process %d for %d units\n", p.pid, p.remaining);
            p.remaining = 0;
        } else {
            // Execute the process for the remaining time quantum
            time += quantum;
            printf("Executing process %d for %d units\n", p.pid, quantum);
            p.remaining -= quantum;
        }
        if (p.remaining > 0) {
            // Re-enqueue the process
            enqueue(&q, p);
        }
    }
}

// Main function
int main() {
    // Create an array of processes
    Process processes[] = {
        {1, 0, 5, 2, 5},
        {2, 1, 3, 1, 3},
        {3, 2, 4, 3, 4},
        {4, 3, 7, 0, 7},
        {5, 4, 8, 4, 8}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Execute FCFS scheduling algorithm
    fcfs(processes, n);

    // Execute SJF scheduling algorithm
    sjf(processes, n);

    // Execute priority scheduling algorithm
    priority(processes, n);

    // Execute round robin scheduling algorithm
    roundRobin(processes, n, 3);

    return 0;
}