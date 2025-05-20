//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    void (*func)(void *arg);
    void *arg;
    time_t time;
} task_t;

typedef struct {
    task_t *tasks;
    int capacity;
    int size;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} task_queue_t;

task_queue_t *task_queue_create(int capacity) {
    task_queue_t *queue = malloc(sizeof(task_queue_t));
    queue->tasks = malloc(sizeof(task_t) * capacity);
    queue->capacity = capacity;
    queue->size = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
    return queue;
}

void task_queue_destroy(task_queue_t *queue) {
    free(queue->tasks);
    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->cond);
    free(queue);
}

void task_queue_push(task_queue_t *queue, task_t task) {
    pthread_mutex_lock(&queue->mutex);
    while (queue->size == queue->capacity) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    queue->tasks[queue->size++] = task;
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
}

task_t task_queue_pop(task_queue_t *queue) {
    pthread_mutex_lock(&queue->mutex);
    while (queue->size == 0) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    task_t task = queue->tasks[--queue->size];
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
    return task;
}

void task_func(void *arg) {
    printf("Task %d executed\n", (int) arg);
}

int main() {
    task_queue_t *queue = task_queue_create(10);

    for (int i = 0; i < 10; i++) {
        task_t task = { .func = task_func, .arg = (void *) i, .time = time(NULL) + i };
        task_queue_push(queue, task);
    }

    while (queue->size > 0) {
        task_t task = task_queue_pop(queue);
        task.func(task.arg);
    }

    task_queue_destroy(queue);
    return 0;
}