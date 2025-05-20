//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the task structure
typedef struct task {
    void (*func)(void *);  // Function to be executed
    void *arg;            // Argument to be passed to the function
} task_t;

// Define the task queue
typedef struct queue {
    task_t *tasks;        // Array of tasks
    int head;            // Index of the first task in the queue
    int tail;            // Index of the last task in the queue
    int size;            // Size of the queue
} queue_t;

// Initialize the task queue
void queue_init(queue_t *queue, int size) {
    queue->tasks = (task_t *)malloc(sizeof(task_t) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
}

// Destroy the task queue
void queue_destroy(queue_t *queue) {
    free(queue->tasks);
}

// Enqueue a task
void queue_enqueue(queue_t *queue, task_t task) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        // Queue is full
        return;
    }

    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue a task
task_t queue_dequeue(queue_t *queue) {
    if (queue->head == queue->tail) {
        // Queue is empty
        return (task_t){NULL, NULL};
    }

    task_t task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return task;
}

// Function to be executed by the thread
void *thread_func(void *arg) {
    queue_t *queue = (queue_t *)arg;

    while (1) {
        // Dequeue a task
        task_t task = queue_dequeue(queue);

        if (task.func == NULL) {
            // Queue is empty
            break;
        }

        // Execute the task
        task.func(task.arg);
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the task queue
    queue_t queue;
    queue_init(&queue, 10);

    // Create a thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, &queue);

    // Enqueue some tasks
    for (int i = 0; i < 10; i++) {
        task_t task = {
            .func = (void (*)(void *))printf,
            .arg = (void *)"Hello world!\n"
        };
        queue_enqueue(&queue, task);
    }

    // Join the thread
    pthread_join(thread, NULL);

    // Destroy the task queue
    queue_destroy(&queue);

    return 0;
}