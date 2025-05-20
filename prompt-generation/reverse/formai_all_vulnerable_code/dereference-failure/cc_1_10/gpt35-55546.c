//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Process struct
typedef struct {
    int id;
    int burst_time;
    int priority;
    int executed_time;
} Process;

// Priority Queue struct
typedef struct {
    Process** data;
    int front;
    int rear;
} PriorityQueue;

// Function declarations
PriorityQueue* create_priority_queue(int size);
void enqueue(Process* process, PriorityQueue* queue);
Process* dequeue(PriorityQueue* queue);
void sort_priority_queue(PriorityQueue* queue);
void execute(Process* process);
void display_process(Process* process);

// Main function
int main() {

    // Initialize Processes
    Process* process1 = (Process*) malloc(sizeof(Process));
    process1->id = 1;
    process1->burst_time = 5;
    process1->priority = 2;
    process1->executed_time = 0;

    Process* process2 = (Process*) malloc(sizeof(Process));
    process2->id = 2;
    process2->burst_time = 3;
    process2->priority = 3;
    process2->executed_time = 0;

    Process* process3 = (Process*) malloc(sizeof(Process));
    process3->id = 3;
    process3->burst_time = 6;
    process3->priority = 1;
    process3->executed_time = 0;

    // Initialize Priority Queue
    PriorityQueue* queue = create_priority_queue(3);

    // Add processes to Priority Queue
    enqueue(process1, queue);
    enqueue(process2, queue);
    enqueue(process3, queue);

    // Execute processes in order of highest priority first
    Process* current_process = NULL;
    while (queue->front != -1) {
        current_process = dequeue(queue);
        execute(current_process);
        display_process(current_process);
    }

    // Free memory
    free(process1);
    free(process2);
    free(process3);
    free(queue->data);
    free(queue);
    return 0;
}

// Creates a new Priority Queue with given size
PriorityQueue* create_priority_queue(int size) {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->data = (Process**) malloc(sizeof(Process*) * size);
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Enqueues a process to Priority Queue based on priority
void enqueue(Process* process, PriorityQueue* queue) {
    if (queue->front == -1) {
        queue->front++;
    }
    queue->rear++;
    queue->data[queue->rear] = process;
    sort_priority_queue(queue);
}

// Removes and returns process with highest priority
Process* dequeue(PriorityQueue* queue) {
    if (queue->front == -1) {
        return NULL;
    }
    Process* temp = queue->data[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return temp;
}

// Sorts Priority Queue based on priority
void sort_priority_queue(PriorityQueue* queue) {
    int i, j;
    Process* temp;
    for (i = 0; i <= queue->rear; i++) {
        for (j = i + 1; j <= queue->rear; j++) {
            if (queue->data[i]->priority > queue->data[j]->priority) {
                temp = queue->data[i];
                queue->data[i] = queue->data[j];
                queue->data[j] = temp;
            }
        }
    }
}

// Executes given Process by incrementing executed time
void execute(Process* process) {
    printf("Process %d executing...\n", process->id);
    process->executed_time++;
}

// Displays details of given Process
void display_process(Process* process) {
    printf("Process ID: %d, Burst Time: %d, Priority: %d, Executed Time: %d\n", process->id, process->burst_time, process->priority, process->executed_time);
}