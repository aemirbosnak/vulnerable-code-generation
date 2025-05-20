//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: genius
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char *name;
    int priority;
    int execution_time;
    int arrival_time;
} task;

typedef struct task_queue {
    task *tasks[MAX_TASKS];
    int head;
    int tail;
    int size;
} task_queue;

task_queue *create_task_queue() {
    task_queue *queue = malloc(sizeof(task_queue));
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    return queue;
}

void destroy_task_queue(task_queue *queue) {
    for (int i = 0; i < queue->size; i++) {
        free(queue->tasks[i]->name);
        free(queue->tasks[i]);
    }
    free(queue);
}

int is_empty(task_queue *queue) {
    return queue->size == 0;
}

int is_full(task_queue *queue) {
    return queue->size == MAX_TASKS;
}

void enqueue(task_queue *queue, task *task) {
    if (is_full(queue)) {
        return;
    }
    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % MAX_TASKS;
    queue->size++;
}

task *dequeue(task_queue *queue) {
    if (is_empty(queue)) {
        return NULL;
    }
    task *task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % MAX_TASKS;
    queue->size--;
    return task;
}

int main() {
    task_queue *queue = create_task_queue();

    // Add some tasks to the queue.
    task task1 = {"Task 1", 1, 10, 0};
    task task2 = {"Task 2", 2, 5, 2};
    task task3 = {"Task 3", 3, 8, 4};
    enqueue(queue, &task1);
    enqueue(queue, &task2);
    enqueue(queue, &task3);

    // Print the tasks in the queue.
    printf("Tasks in the queue:\n");
    task *task;
    while ((task = dequeue(queue)) != NULL) {
        printf("%s\n", task->name);
    }

    // Destroy the queue.
    destroy_task_queue(queue);

    return 0;
}