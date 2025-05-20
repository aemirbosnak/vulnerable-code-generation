//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Task struct
typedef struct task {
    void (*function)(void *);
    void *args;
} task_t;

// Queue struct
typedef struct queue {
    task_t *tasks;
    int head, tail, size, capacity;
} queue_t;

// Queue operations
queue_t *queue_create(int capacity) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->tasks = (task_t *)malloc(sizeof(task_t) * capacity);
    queue->head = queue->tail = queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void queue_push(queue_t *queue, task_t task) {
    if (queue->size == queue->capacity) {
        printf("Queue is full!\n");
        return;
    }
    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
}

task_t queue_pop(queue_t *queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        exit(1);
    }
    task_t task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    return task;
}

// Thread function
void *thread_function(void *args) {
    queue_t *queue = (queue_t *)args;
    while (1) {
        // Get next task from queue
        task_t task = queue_pop(queue);

        // Execute task
        task.function(task.args);
    }
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Create task queue
    int queue_capacity = 10;
    queue_t *queue = queue_create(queue_capacity);

    // Create tasks
    int num_tasks = 10;
    for (int i = 0; i < num_tasks; i++) {
        task_t task;
        task.function = &printf;
        task.args = (void *)"Hello from task %d!\n";
        queue_push(queue, task);
    }

    // Create threads
    int num_threads = 4;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, queue);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy queue
    free(queue->tasks);
    free(queue);

    return 0;
}