//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process structure
typedef struct {
    int pid; // Process ID
    int arrival_time; // Arrival time of the process
    int burst_time; // Burst time of the process
    int priority; // Priority of the process
    int remaining_time; // Remaining burst time of the process
} process;

// Execution queue structure
typedef struct {
    process* processes; // Array of processes
    int size; // Size of the queue
    int front; // Front of the queue
} queue;

// Function to create a new process
process* create_process(int pid, int arrival_time, int burst_time, int priority) {
    process* p = malloc(sizeof(process));
    p->pid = pid;
    p->arrival_time = arrival_time;
    p->burst_time = burst_time;
    p->priority = priority;
    p->remaining_time = burst_time;
    return p;
}

// Function to create a new queue
queue* create_queue(int size) {
    queue* q = malloc(sizeof(queue));
    q->processes = malloc(sizeof(process) * size);
    q->size = size;
    q->front = 0;
    return q;
}

// Function to add a process to the queue
void enqueue(queue* q, process* p) {
    q->processes[(q->front + q->size) % q->size] = *p;
    q->front = (q->front + 1) % q->size;
}

// Function to remove a process from the queue
process* dequeue(queue* q) {
    process* p = &q->processes[(q->front + q->size - q->size) % q->size];
    q->front = (q->front + q->size - 1) % q->size;
    return p;
}

// Function to get the process at the front of the queue
process* front(queue* q) {
    return &q->processes[(q->front + q->size - 1) % q->size];
}

// Function to check if the queue is empty
bool is_empty(queue* q) {
    return q->front == 0;
}

// Function to check if the queue is full
bool is_full(queue* q) {
    return q->front == q->size;
}

// Function to print a process
void print_process(process* p) {
    printf("P%d: Arrival Time=%d, Burst Time=%d, Priority=%d\n",
           p->pid, p->arrival_time, p->burst_time, p->priority);
}

// Function to print the queue
void print_queue(queue* q) {
    printf("Queue: ");
    int i;
    for (i = 0; i < q->size; i++) {
        if (q->front == i) {
            printf("| ");
        }
        if (is_empty(q)) {
            printf("- ");
        } else {
            process* p = &q->processes[i];
            printf("P%d ", p->pid);
        }
    }
    printf("|\n");
}

// Function to implement the Round Robin scheduling algorithm
void round_robin(queue* q, int quantum) {
    int time = 0;
    int total_time = 0;
    int wait_time = 0;
    while (!is_empty(q)) {
        process* p = dequeue(q);
        if (p->remaining_time > quantum) {
            total_time += quantum;
            p->remaining_time -= quantum;
            printf("Time=%d: ", time);
            print_process(p);
            enqueue(q, p);
        } else {
            total_time += p->remaining_time;
            wait_time += total_time - p->arrival_time - p->burst_time;
            time += p->remaining_time;
            p->remaining_time = 0;
            printf("Time=%d: ", time);
            print_process(p);
        }
    }
    printf("Total Time=%d, Wait Time=%d, Average Wait Time=%.2f\n",
           total_time, wait_time, (float) wait_time / (float) (q->size));
}

// Function to implement the Priority scheduling algorithm
void priority(queue* q) {
    int time = 0;
    int total_time = 0;
    int wait_time = 0;
    while (!is_empty(q)) {
        int i, max_index = -1, max_priority = -1;
        for (i = 0; i < q->size; i++) {
            process* p = &q->processes[i];
            if (p->arrival_time <= time && p->priority > max_priority) {
                max_priority = p->priority;
                max_index = i;
            }
        }
        if (max_index == -1) {
            time++;
            continue;
        }
        process* p = &q->processes[max_index];
        total_time += p->burst_time;
        wait_time += total_time - p->arrival_time - p->burst_time;
        time += p->burst_time;
        p->remaining_time = 0;
        printf("Time=%d: ", time);
        print_process(p);
        q->front = max_index;
        int j;
        for (j = max_index + 1; j < q->size; j++) {
            q->processes[j - 1] = q->processes[j];
        }
        q->front = (q->front + q->size - 1) % q->size;
    }
    printf("Total Time=%d, Wait Time=%d, Average Wait Time=%.2f\n",
           total_time, wait_time, (float) wait_time / (float) (q->size));
}

int main() {
    queue* q = create_queue(5);
    enqueue(q, create_process(1, 0, 10, 2));
    enqueue(q, create_process(2, 0, 5, 1));
    enqueue(q, create_process(3, 0, 2, 3));
    enqueue(q, create_process(4, 0, 3, 1));
    enqueue(q, create_process(5, 0, 4, 4));

    printf("Round Robin\n");
    round_robin(q, 3);

    printf("Priority\n");
    priority(q);

    return 0;
}