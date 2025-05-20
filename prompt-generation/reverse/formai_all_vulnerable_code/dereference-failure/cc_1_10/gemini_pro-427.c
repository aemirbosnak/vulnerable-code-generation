//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    int id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    int priority;
} task;

// Queue structure
typedef struct queue {
    task *tasks;
    int front;
    int rear;
    int size;
} queue;

// Function to create a new task
task *create_task(int id, int arrival_time, int execution_time, int priority) {
    task *new_task = (task *)malloc(sizeof(task));
    new_task->id = id;
    new_task->arrival_time = arrival_time;
    new_task->execution_time = execution_time;
    new_task->remaining_time = execution_time;
    new_task->priority = priority;
    return new_task;
}

// Function to create a new queue
queue *create_queue(int size) {
    queue *new_queue = (queue *)malloc(sizeof(queue));
    new_queue->tasks = (task *)malloc(sizeof(task) * size);
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->size = size;
    return new_queue;
}

// Function to enqueue a task
void enqueue(queue *q, task *new_task) {
    if (q->rear == q->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->tasks[q->rear] = *new_task;
}

// Function to dequeue a task
task *dequeue(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return NULL;
    }
    task *dequeued_task = &q->tasks[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return dequeued_task;
}

// Function to sort the tasks in the queue based on priority
void sort_queue(queue *q) {
    for (int i = 0; i < q->rear; i++) {
        for (int j = i + 1; j <= q->rear; j++) {
            if (q->tasks[i].priority > q->tasks[j].priority) {
                task temp = q->tasks[i];
                q->tasks[i] = q->tasks[j];
                q->tasks[j] = temp;
            }
        }
    }
}

// Function to schedule the tasks using round-robin scheduling
void round_robin_scheduling(queue *q, int time_quantum) {
    int current_time = 0;
    while (q->front != -1) {
        task *current_task = dequeue(q);
        // Execute the task for the time quantum
        int executed_time = current_task->remaining_time > time_quantum ? time_quantum : current_task->remaining_time;
        current_task->remaining_time -= executed_time;
        current_time += executed_time;
        // Check if the task is completed
        if (current_task->remaining_time == 0) {
            printf("Task %d completed at time %d\n", current_task->id, current_time);
        } else {
            // Enqueue the task back to the queue
            enqueue(q, current_task);
        }
    }
}

// Main function
int main() {
    // Create a queue to store the tasks
    queue *q = create_queue(10);

    // Create tasks
    task *t1 = create_task(1, 0, 10, 5);
    task *t2 = create_task(2, 2, 5, 3);
    task *t3 = create_task(3, 4, 7, 1);
    task *t4 = create_task(4, 6, 3, 4);
    task *t5 = create_task(5, 8, 4, 2);

    // Enqueue the tasks into the queue
    enqueue(q, t1);
    enqueue(q, t2);
    enqueue(q, t3);
    enqueue(q, t4);
    enqueue(q, t5);

    // Sort the queue based on priority
    sort_queue(q);

    // Schedule the tasks using round-robin scheduling with a time quantum of 2
    round_robin_scheduling(q, 2);

    return 0;
}