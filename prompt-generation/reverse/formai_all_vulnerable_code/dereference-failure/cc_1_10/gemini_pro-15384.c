//GEMINI-pro DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a process
typedef struct {
    int pid;            // Process ID
    int priority;       // Priority
    int state;          // State (0 = new, 1 = running, 2 = waiting, 3 = terminated)
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int remaining_time; // Remaining time
    int waiting_time;   // Waiting time
    int turnaround_time;// Turnaround time
} process;

// Define a queue to store processes
typedef struct {
    process *processes; // Array of processes
    int front;          // Front of the queue
    int rear;           // Rear of the queue
    int size;           // Size of the queue
} queue;

// Initialize the queue
void initialize_queue(queue *q, int size) {
    q->processes = (process *)malloc(size * sizeof(process));
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

// Check if the queue is empty
int is_empty_queue(queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int is_full_queue(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// Add a process to the queue
void enqueue(queue *q, process p) {
    if (is_full_queue(q)) {
        printf("Error: Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->processes[q->rear] = p;
    }
}

// Remove a process from the queue
process dequeue(queue *q) {
    process p;
    if (is_empty_queue(q)) {
        printf("Error: Queue is empty!\n");
    } else {
        p = q->processes[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
    }
    return p;
}

// Sort the processes by their arrival time
void sort_processes_by_arrival_time(process *processes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Sort the processes by their priority
void sort_processes_by_priority(process *processes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (processes[i].priority < processes[j].priority) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Simulate the execution of the processes
void simulate_execution(process *processes, int size) {
    // Initialize the time
    int time = 0;

    // Create a queue to store the processes that are waiting to be executed
    queue waiting_queue;
    initialize_queue(&waiting_queue, size);

    // Create a queue to store the processes that are currently being executed
    queue running_queue;
    initialize_queue(&running_queue, size);

    // While there are still processes to be executed
    while (!is_empty_queue(&waiting_queue) || !is_empty_queue(&running_queue)) {
        // If there are processes waiting to be executed
        while (!is_empty_queue(&waiting_queue)) {
            // Get the next process from the waiting queue
            process p = dequeue(&waiting_queue);

            // If the process has arrived at the current time
            if (p.arrival_time <= time) {
                // Add the process to the running queue
                enqueue(&running_queue, p);
            } else {
                // Put the process back in the waiting queue
                enqueue(&waiting_queue, p);
            }
        }

        // If there are processes currently being executed
        if (!is_empty_queue(&running_queue)) {
            // Get the next process from the running queue
            process p = dequeue(&running_queue);

            // Execute the process for one time unit
            p.remaining_time--;

            // If the process has finished executing
            if (p.remaining_time == 0) {
                // Calculate the process's turnaround time
                p.turnaround_time = time - p.arrival_time;

                // Calculate the process's waiting time
                p.waiting_time = p.turnaround_time - p.burst_time;

                // Print the process's information
                printf("Process %d completed at time %d with a turnaround time of %d and a waiting time of %d\n",
                    p.pid, time, p.turnaround_time, p.waiting_time);
            } else {
                // Add the process back to the running queue
                enqueue(&running_queue, p);
            }
        }

        // Increment the time
        time++;
    }
}

int main() {
    // Initialize the processes
    process processes[] = {
        {1, 5, 0, 0, 10, 10, 0, 0},
        {2, 3, 0, 2, 6, 6, 0, 0},
        {3, 4, 0, 4, 8, 8, 0, 0}
    };

    // Sort the processes by their arrival time
    sort_processes_by_arrival_time(processes, sizeof(processes) / sizeof(process));

    // Sort the processes by their priority
    sort_processes_by_priority(processes, sizeof(processes) / sizeof(process));

    // Simulate the execution of the processes
    simulate_execution(processes, sizeof(processes) / sizeof(process));

    return 0;
}