//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Task structure
typedef struct task {
    void (*func)(void *arg); // Function pointer
    void *arg; // Argument to the function
    struct task *next; // Pointer to the next task
} task_t;

// Queue structure
typedef struct queue {
    task_t *head; // Pointer to the head of the queue
    task_t *tail; // Pointer to the tail of the queue
} queue_t;

// Create a new task
task_t *task_create(void (*func)(void *arg), void *arg) {
    task_t *task = malloc(sizeof(task_t));
    if (!task) {
        return NULL;
    }
    task->func = func;
    task->arg = arg;
    task->next = NULL;
    return task;
}

// Enqueue a task
void queue_enqueue(queue_t *queue, task_t *task) {
    if (!queue->head) {
        queue->head = task;
        queue->tail = task;
    } else {
        queue->tail->next = task;
        queue->tail = task;
    }
}

// Dequeue a task
task_t *queue_dequeue(queue_t *queue) {
    if (!queue->head) {
        return NULL;
    }
    task_t *task = queue->head;
    queue->head = task->next;
    if (!queue->head) {
        queue->tail = NULL;
    }
    return task;
}

// Task scheduler thread
void *task_scheduler(void *arg) {
    queue_t *queue = (queue_t *)arg;
    while (1) {
        task_t *task = queue_dequeue(queue);
        if (!task) {
            break;
        }
        task->func(task->arg);
        free(task);
    }
    return NULL;
}

// Example task function
void example_task(void *arg) {
    printf("Hello from task %d!\n", (int)arg);
}

int main() {
    // Create a queue
    queue_t queue;
    queue.head = NULL;
    queue.tail = NULL;

    // Create a thread pool
    pthread_t thread_pool[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&thread_pool[i], NULL, task_scheduler, &queue);
    }

    // Create tasks
    for (int i = 0; i < 10; i++) {
        task_t *task = task_create(example_task, (void *)i);
        queue_enqueue(&queue, task);
    }

    // Wait for tasks to complete
    for (int i = 0; i < 4; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    return 0;
}