//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Task structure
typedef struct task_t {
    void (*func)(void *arg); // Task function
    void *arg;                // Task argument
} task_t;

// Task queue
typedef struct queue_t {
    task_t *tasks;       // Array of tasks
    int head;            // Head of the queue
    int tail;            // Tail of the queue
    int size;            // Size of the queue
} queue_t;

// Create a new task queue
queue_t *create_queue(int size) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->tasks = malloc(sizeof(task_t) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Destroy a task queue
void destroy_queue(queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

// Push a task onto the queue
void push_task(queue_t *queue, task_t task) {
    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Pop a task from the queue
task_t pop_task(queue_t *queue) {
    task_t task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return task;
}

// Task function
void task_function(void *arg) {
    printf("Task function: %d\n", (int)arg);
}

// Main function
int main() {
    // Create a task queue
    queue_t *queue = create_queue(10);

    // Push tasks onto the queue
    for (int i = 0; i < 10; i++) {
        task_t task;
        task.func = task_function;
        task.arg = (void *)i;
        push_task(queue, task);
    }

    // Create threads to process tasks
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, (void *(*)(void *))pop_task, queue);
    }

    // Join threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the task queue
    destroy_queue(queue);

    return 0;
}