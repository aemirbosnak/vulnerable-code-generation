//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Task structure
typedef struct Task {
    char *name;
    int priority;
    int time_units;
    struct Task *next;
} Task;

// Queue structure
typedef struct Queue {
    Task *head;
    Task *tail;
} Queue;

// Create a new task
Task *create_task(char *name, int priority, int time_units) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->time_units = time_units;
    new_task->next = NULL;
    return new_task;
}

// Enqueue a task
void enqueue(Queue *queue, Task *task) {
    if (queue->head == NULL) {
        queue->head = task;
        queue->tail = task;
    } else {
        queue->tail->next = task;
        queue->tail = task;
    }
}

// Dequeue a task
Task *dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return NULL;
    } else {
        Task *task = queue->head;
        queue->head = queue->head->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        return task;
    }
}

// Print a task
void print_task(Task *task) {
    printf("%s (%d, %d)\n", task->name, task->priority, task->time_units);
}

// Print a queue
void print_queue(Queue *queue) {
    Task *task = queue->head;
    while (task != NULL) {
        print_task(task);
        task = task->next;
    }
}

// Main function
int main() {
    // Create a new queue
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    // Create some tasks
    Task *task1 = create_task("Task 1", 1, 10);
    Task *task2 = create_task("Task 2", 2, 5);
    Task *task3 = create_task("Task 3", 3, 15);

    // Enqueue the tasks
    enqueue(queue, task1);
    enqueue(queue, task2);
    enqueue(queue, task3);

    // Print the queue
    print_queue(queue);

    // Dequeue a task
    Task *task4 = dequeue(queue);

    // Print the dequeued task
    print_task(task4);

    // Free the task
    free(task4);

    // Free the queue
    free(queue);

    return 0;
}