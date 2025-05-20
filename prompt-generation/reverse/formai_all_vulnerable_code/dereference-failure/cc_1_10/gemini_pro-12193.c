//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

// Node structure for representing a process
typedef struct node {
    int id;             // Process ID
    int burst_time;     // CPU burst time
    int arrival_time;   // Time of arrival
    int remaining_time; // Remaining CPU burst time
    struct node *next;  // Pointer to the next node
} node;

// Queue structure for representing a ready queue
typedef struct queue {
    struct node *front; // Pointer to the front of the queue
    struct node *rear;  // Pointer to the rear of the queue
} queue;

// Function to create a new node
node *create_node(int id, int burst_time, int arrival_time) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->id = id;
    new_node->burst_time = burst_time;
    new_node->arrival_time = arrival_time;
    new_node->remaining_time = burst_time;
    new_node->next = NULL;
    return new_node;
}

// Function to enqueue a node in a queue
void enqueue(queue *q, node *new_node) {
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Function to dequeue a node from a queue
node *dequeue(queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

// Function to print a queue
void print_queue(queue *q) {
    node *temp = q->front;
    while (temp != NULL) {
        printf("Process ID: %d, Burst Time: %d, Arrival Time: %d, Remaining Time: %d\n",
               temp->id, temp->burst_time, temp->arrival_time, temp->remaining_time);
        temp = temp->next;
    }
}

// Function to simulate FCFS CPU scheduling algorithm
void fcfs(queue *q) {
    int time = 0;
    node *current_process;
    while (q->front != NULL) {
        current_process = dequeue(q);
        printf("Time %d: Process %d is running\n", time, current_process->id);
        time += current_process->burst_time;
        printf("Time %d: Process %d finished\n", time, current_process->id);
    }
}

// Function to simulate SJF (shortest job first) CPU scheduling algorithm
void sjf(queue *q) {
    int time = 0;
    node *current_process;
    while (q->front != NULL) {
        // Find the process with the shortest remaining time
        node *shortest_process = q->front;
        node *temp = q->front->next;
        while (temp != NULL) {
            if (temp->remaining_time < shortest_process->remaining_time) {
                shortest_process = temp;
            }
            temp = temp->next;
        }
        
        // Run the shortest process
        current_process = dequeue(q);
        printf("Time %d: Process %d is running\n", time, current_process->id);
        time += current_process->remaining_time;
        printf("Time %d: Process %d finished\n", time, current_process->id);
    }
}

// Function to simulate RR (round robin) CPU scheduling algorithm
void rr(queue *q, int time_quantum) {
    int time = 0;
    node *current_process;
    while (q->front != NULL) {
        current_process = dequeue(q);
        if (current_process->remaining_time > time_quantum) {
            current_process->remaining_time -= time_quantum;
            time += time_quantum;
            printf("Time %d: Process %d is running\n", time, current_process->id);
            enqueue(q, current_process);
        } else {
            time += current_process->remaining_time;
            printf("Time %d: Process %d finished\n", time, current_process->id);
        }
    }
}

// Main function
int main() {
    // Create a queue to store the processes
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;

    // Create 10 processes with random burst times and arrival times
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int burst_time = rand() % 10 + 1;
        int arrival_time = rand() % 10;
        node *new_node = create_node(i + 1, burst_time, arrival_time);
        enqueue(q, new_node);
    }

    // Print the initial queue
    printf("Initial Queue:\n");
    print_queue(q);

    // Simulate FCFS scheduling algorithm
    printf("\nFCFS Scheduling Algorithm:\n");
    fcfs(q);

    // Reset the queue
    q->front = NULL;
    q->rear = NULL;
    for (int i = 0; i < 10; i++) {
        node *new_node = create_node(i + 1, rand() % 10 + 1, rand() % 10);
        enqueue(q, new_node);
    }

    // Simulate SJF scheduling algorithm
    printf("\nSJF Scheduling Algorithm:\n");
    sjf(q);

    // Reset the queue
    q->front = NULL;
    q->rear = NULL;
    for (int i = 0; i < 10; i++) {
        node *new_node = create_node(i + 1, rand() % 10 + 1, rand() % 10);
        enqueue(q, new_node);
    }

    // Simulate RR scheduling algorithm
    printf("\nRR Scheduling Algorithm:\n");
    rr(q, 2);

    return 0;
}