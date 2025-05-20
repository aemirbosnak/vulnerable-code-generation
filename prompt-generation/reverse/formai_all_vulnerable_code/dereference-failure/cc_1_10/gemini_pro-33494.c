//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;            // Process ID
    int arrival_time;    // Arrival time
    int burst_time;     // Burst time
    int priority;       // Priority
    int remaining_time; // Remaining time
} Process;

// Queue structure
typedef struct Queue {
    Process *processes; // Array of processes
    int front, rear;    // Queue front and rear pointers
    int size;          // Queue size
} Queue;

// Function to create a new process
Process *create_process(int pid, int arrival_time, int burst_time, int priority) {
    Process *process = (Process *)malloc(sizeof(Process));
    process->pid = pid;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->priority = priority;
    process->remaining_time = burst_time;
    return process;
}

// Function to create a new queue
Queue *create_queue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->processes = (Process *)malloc(size * sizeof(Process));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to enqueue a process into the queue
void enqueue(Queue *queue, Process *process) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->processes[queue->rear] = *process;
}

// Function to dequeue a process from the queue
Process *dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }

    Process *process = &queue->processes[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return process;
}

// Function to compare two processes based on their priority
int compare_processes(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->priority - p2->priority;
}

// Function to simulate CPU scheduling using Priority Scheduling
void priority_scheduling(Process *processes, int n) {
    // Sort the processes based on their priority
    qsort(processes, n, sizeof(Process), compare_processes);

    // Create a queue to store the processes
    Queue *queue = create_queue(n);

    // Initialize the current time to 0
    int current_time = 0;

    // While there are processes to be scheduled
    while (queue->front != -1) {
        // Dequeue the next process from the queue
        Process *process = dequeue(queue);

        // Check if the process has arrived
        if (process->arrival_time > current_time) {
            // If the process has not arrived, put it back in the queue
            enqueue(queue, process);
        } else {
            // If the process has arrived, execute it
            printf("Executing process %d\n", process->pid);
            current_time += process->burst_time;

            // Check if the process has finished executing
            if (process->remaining_time == 0) {
                // If the process has finished executing, remove it from the queue
                free(process);
            } else {
                // If the process has not finished executing, put it back in the queue
                enqueue(queue, process);
            }
        }
    }
}

// Main function
int main() {
    // Create a set of processes
    Process processes[] = {
        create_process(1, 0, 5, 3),
        create_process(2, 1, 4, 2),
        create_process(3, 2, 6, 1),
        create_process(4, 3, 3, 4),
        create_process(5, 4, 2, 2),
    };

    // Number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Simulate CPU scheduling using Priority Scheduling
    priority_scheduling(processes, n);

    return 0;
}