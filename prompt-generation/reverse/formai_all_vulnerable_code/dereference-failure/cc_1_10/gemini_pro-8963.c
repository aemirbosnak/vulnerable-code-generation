//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 10
#define MAX_TASK_DURATION 10
#define MIN_TASK_DURATION 1

typedef struct task {
    int id;
    int duration;
} task;

typedef struct task_queue {
    task *tasks;
    int head;
    int tail;
    int size;
} task_queue;

task_queue *task_queue_create() {
    task_queue *queue = malloc(sizeof(task_queue));
    queue->tasks = malloc(sizeof(task) * NUM_TASKS);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    return queue;
}

void task_queue_destroy(task_queue *queue) {
    free(queue->tasks);
    free(queue);
}

int task_queue_is_empty(task_queue *queue) {
    return queue->size == 0;
}

int task_queue_is_full(task_queue *queue) {
    return queue->size == NUM_TASKS;
}

void task_queue_enqueue(task_queue *queue, task t) {
    if (task_queue_is_full(queue)) {
        printf("Error: task queue is full\n");
        return;
    }
    queue->tasks[queue->tail] = t;
    queue->tail = (queue->tail + 1) % NUM_TASKS;
    queue->size++;
}

task task_queue_dequeue(task_queue *queue) {
    if (task_queue_is_empty(queue)) {
        printf("Error: task queue is empty\n");
        return (task) {-1, -1};
    }
    task t = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % NUM_TASKS;
    queue->size--;
    return t;
}

void *task_thread(void *args) {
    task_queue *queue = (task_queue *) args;
    while (1) {
        task t = task_queue_dequeue(queue);
        if (t.id == -1) {
            break;
        }
        printf("Task %d started\n", t.id);
        sleep(t.duration);
        printf("Task %d completed\n", t.id);
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    task_queue *queue = task_queue_create();

    for (int i = 0; i < NUM_TASKS; i++) {
        task t = {i, rand() % (MAX_TASK_DURATION - MIN_TASK_DURATION + 1) + MIN_TASK_DURATION};
        task_queue_enqueue(queue, t);
    }

    pthread_t threads[NUM_TASKS];
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_thread, (void *) queue);
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    task_queue_destroy(queue);

    return 0;
}