//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

// Define the process structure
typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    int status;
} Process;

// Define the queue structure
typedef struct Queue {
    Process **processes;
    int front;
    int rear;
    int size;
} Queue;

// Create a queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->processes = (Process **)malloc(size * sizeof(Process));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Insert a process into the queue
void insertProcess(Queue *queue, Process *process) {
    queue->processes[++queue->rear] = process;
}

// Round robin scheduling algorithm
void roundRobin(Queue *queue) {
    int i = 0;
    while (!queue->processes[i]->status) {
        queue->processes[i]->remaining_time--;
        if (queue->processes[i]->remaining_time == 0) {
            queue->processes[i]->status = 1;
            printf("Process %d completed.\n", queue->processes[i]->process_id);
        }
        i = (i + 1) % MAX_PROCESSES;
    }
}

int main() {
    // Create a queue
    Queue *queue = createQueue(MAX_QUEUE_SIZE);

    // Create processes
    Process process1 = {1, "Process A", 5, 5, 0};
    Process process2 = {2, "Process B", 3, 3, 0};
    Process process3 = {3, "Process C", 4, 4, 0};
    Process process4 = {4, "Process D", 2, 2, 0};
    Process process5 = {5, "Process E", 3, 3, 0};

    // Insert processes into the queue
    insertProcess(queue, &process1);
    insertProcess(queue, &process2);
    insertProcess(queue, &process3);
    insertProcess(queue, &process4);
    insertProcess(queue, &process5);

    // Round robin scheduling
    roundRobin(queue);

    return 0;
}