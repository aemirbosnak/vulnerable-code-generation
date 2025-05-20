//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESS 10  // Maximum number of processes
#define MAX_BURST 20    // Maximum burst time
#define MIN_PRIORITY 1  // Minimum priority value
#define MAX_PRIORITY 5  // Maximum priority value

struct process {
    int pid;            // Process ID
    int burst_time;     // Burst time
    int priority;       // Priority value
};

struct node {
    struct process p;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

// Create a new node with the given process
struct node *create_node(struct process p) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->p = p;
    new_node->next = NULL;
    return new_node;
}

// Create an empty queue
struct queue *create_queue() {
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if the queue is empty
bool is_empty(struct queue *q) {
    return q->front == NULL;
}

// Enqueue a process to the queue
void enqueue(struct queue *q, struct process p) {
    struct node *new_node = create_node(p);
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue a process from the queue
void dequeue(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

// Get the front element of the queue
struct process front(struct queue *q) {
    return q->front->p;
}

// Get the process with the highest priority value in the queue
struct process highest_priority(struct queue *q) {
    struct node *temp = q->front;
    struct process hp = temp->p;
    while (temp != NULL) {
        if (temp->p.priority > hp.priority) {
            hp = temp->p;
        }
        temp = temp->next;
    }
    return hp;
}

// Simulate the FCFS scheduling algorithm
void fcfs(struct process processes[], int n) {
    printf("FCFS Schedule: ");
    int time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
        time += processes[i].burst_time;
    }
    printf("\nAverage waiting time: %d\n", time/n);
}

// Simulate the SJF scheduling algorithm
void sjf(struct process processes[], int n) {
    printf("SJF Schedule: ");
    int burst_times[MAX_PROCESS];
    for (int i = 0; i < n; i++) {
        burst_times[i] = processes[i].burst_time;
    }
    int time = 0, completed = 0;
    while (completed < n) {
        int shortest = MAX_BURST + 1, next_process = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].burst_time < shortest && processes[i].burst_time > 0) {
                shortest = processes[i].burst_time;
                next_process = i;
            }
        }
        if (next_process == -1) {
            time++;
            continue;
        }
        printf("P%d ", processes[next_process].pid);
        processes[next_process].burst_time--;
        time++;
        if (processes[next_process].burst_time == 0) {
            completed++;
        }
    }
    printf("\nAverage waiting time: %d\n", time/n);
}

// Simulate the Priority scheduling algorithm
void priority(struct process processes[], int n) {
    printf("Priority Schedule: ");
    struct queue *q = create_queue();
    int time = 0, completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].priority == MIN_PRIORITY && is_empty(q)) {
                printf("P%d ", processes[i].pid);
                processes[i].burst_time--;
                time++;
                if (processes[i].burst_time == 0) {
                    completed++;
                }
            }
            if (processes[i].burst_time > 0 && processes[i].priority > MIN_PRIORITY) {
                enqueue(q, processes[i]);
            }
        }
        if (!is_empty(q)) {
            struct process hp = highest_priority(q);
            printf("P%d ", hp.pid);
            hp.burst_time--;
            time++;
            if (hp.burst_time == 0) {
                completed++;
                dequeue(q);
            }
        }
    }
    printf("\nAverage waiting time: %d\n", time/n);
}

int main() {
    srand(time(NULL));
    struct process processes[MAX_PROCESS];
    int n = rand() % MAX_PROCESS + 1;
    printf("Number of processes: %d\n", n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        processes[i].burst_time = rand() % MAX_BURST + 1;
        processes[i].priority = rand() % (MAX_PRIORITY-MIN_PRIORITY+1) + MIN_PRIORITY;
        printf("P%d: burst time %d, priority value %d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
    }
    fcfs(processes, n);
    sjf(processes, n);
    priority(processes, n);
    return 0;
}