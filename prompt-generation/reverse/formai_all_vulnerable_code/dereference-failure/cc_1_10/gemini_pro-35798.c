//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Task structure
typedef struct task {
    void (*func)(void*); // Function pointer
    void *arg;          // Function argument
} task_t;

// Task queue
typedef struct queue {
    task_t *tasks;      // Array of tasks
    int head;           // Index of the first task in the queue
    int tail;           // Index of the last task in the queue
    int size;           // Size of the queue
} queue_t;

// Create a new task queue
queue_t *queue_create(int size) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->tasks = malloc(sizeof(task_t) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

// Destroy a task queue
void queue_destroy(queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

// Enqueue a task
void queue_enqueue(queue_t *queue, task_t task) {
    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue a task
task_t queue_dequeue(queue_t *queue) {
    task_t task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return task;
}

// Task scheduler
void *task_scheduler(void *arg) {
    queue_t *queue = (queue_t *)arg;

    while (1) {
        // Dequeue a task
        task_t task = queue_dequeue(queue);

        // Execute the task
        task.func(task.arg);
    }

    return NULL;
}

// Task function
void task_function(void *arg) {
    printf("Task %d executed\n", (int)arg);
}

// Main function
int main() {
    // Create a task queue
    queue_t *queue = queue_create(10);

    // Create a task scheduler thread
    pthread_t thread;
    pthread_create(&thread, NULL, task_scheduler, queue);

    // Enqueue tasks
    for (int i = 0; i < 10; i++) {
        task_t task;
        task.func = task_function;
        task.arg = (void *)i;
        queue_enqueue(queue, task);
    }

    // Join the task scheduler thread
    pthread_join(thread, NULL);

    // Destroy the task queue
    queue_destroy(queue);

    return 0;
}