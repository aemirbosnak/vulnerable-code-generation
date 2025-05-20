//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int priority;   // Priority
    int remaining;  // Remaining time
} Process;

// Queue structure
typedef struct Queue {
    Process *processes;  // Array of processes
    int front;           // Front of the queue
    int rear;            // Rear of the queue
    int size;            // Size of the queue
} Queue;

// Function to create a new process
Process *create_process(int pid, int arrival, int burst, int priority) {
    Process *process = (Process *)malloc(sizeof(Process));
    process->pid = pid;
    process->arrival = arrival;
    process->burst = burst;
    process->priority = priority;
    process->remaining = burst;
    return process;
}

// Function to create a new queue
Queue *create_queue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->processes = (Process *)malloc(sizeof(Process) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to enqueue a process
void enqueue(Queue *queue, Process *process) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->processes[queue->rear] = *process;
}

// Function to dequeue a process
Process *dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return NULL;
    }

    Process *process = &queue->processes[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return process;
}

// Function to sort the queue by arrival time
void sort_queue_by_arrival(Queue *queue) {
    for (int i = 0; i < queue->size; i++) {
        for (int j = i + 1; j < queue->size; j++) {
            if (queue->processes[i].arrival > queue->processes[j].arrival) {
                Process temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            }
        }
    }
}

// Function to sort the queue by priority
void sort_queue_by_priority(Queue *queue) {
    for (int i = 0; i < queue->size; i++) {
        for (int j = i + 1; j < queue->size; j++) {
            if (queue->processes[i].priority > queue->processes[j].priority) {
                Process temp = queue->processes[i];
                queue->processes[i] = queue->processes[j];
                queue->processes[j] = temp;
            }
        }
    }
}

// Function to simulate the CPU Scheduling Algorithms
void cpu_scheduling(Queue *queue, int algorithm) {
    int time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (queue->front != -1) {
        Process *process = dequeue(queue);
        printf("Process %d is running at time %d\n", process->pid, time);

        process->remaining -= 1;
        time += 1;

        if (process->remaining == 0) {
            total_waiting_time += time - process->arrival - process->burst;
            total_turnaround_time += time - process->arrival;
        } else {
            enqueue(queue, process);
        }

        // Sort the queue by arrival time or priority after each process execution
        if (algorithm == 1) {
            sort_queue_by_arrival(queue);
        } else if (algorithm == 2) {
            sort_queue_by_priority(queue);
        }
    }

    printf("Average waiting time: %f\n", (float)total_waiting_time / queue->size);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / queue->size);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Queue *queue = create_queue(n);

    for (int i = 0; i < n; i++) {
        int pid, arrival, burst, priority;
        printf("Enter the process ID, arrival time, burst time, and priority: ");
        scanf("%d %d %d %d", &pid, &arrival, &burst, &priority);
        Process *process = create_process(pid, arrival, burst, priority);
        enqueue(queue, process);
    }

    int algorithm;
    printf("Enter the CPU Scheduling Algorithms (1 for FCFS, 2 for SJF): ");
    scanf("%d", &algorithm);

    cpu_scheduling(queue, algorithm);

    return 0;
}