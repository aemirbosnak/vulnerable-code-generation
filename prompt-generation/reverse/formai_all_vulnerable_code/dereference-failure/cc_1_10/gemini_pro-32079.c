//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct task {
    char *name;
    int priority;
    int arrival_time;
    int execution_time;
    int remaining_time;
} task_t;

typedef struct task_queue {
    task_t *tasks;
    int size;
    int capacity;
} task_queue_t;

task_queue_t *create_task_queue(int capacity) {
    task_queue_t *queue = malloc(sizeof(task_queue_t));
    queue->tasks = malloc(sizeof(task_t) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void destroy_task_queue(task_queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

void enqueue_task(task_queue_t *queue, task_t *task) {
    if (queue->size == queue->capacity) {
        fprintf(stderr, "Task queue is full\n");
        return;
    }
    queue->tasks[queue->size++] = *task;
}

task_t *dequeue_task(task_queue_t *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    task_t *task = &queue->tasks[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->tasks[i] = queue->tasks[i + 1];
    }
    queue->size--;
    return task;
}

int main() {
    int num_tasks = 10;
    int max_priority = 5;
    int max_execution_time = 10;
    int quantum = 2;

    srand(time(NULL));

    task_queue_t *queue = create_task_queue(num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        task_t task;
        task.name = malloc(10);
        sprintf(task.name, "Task %d", i);
        task.priority = rand() % max_priority + 1;
        task.arrival_time = rand() % num_tasks;
        task.execution_time = rand() % max_execution_time + 1;
        task.remaining_time = task.execution_time;
        enqueue_task(queue, &task);
    }

    int time = 0;

    while (queue->size > 0) {
        task_t *task = dequeue_task(queue);
        while (task->remaining_time > 0) {
            printf("Time: %d, running task: %s, remaining time: %d\n", time, task->name, task->remaining_time);
            time++;
            task->remaining_time -= quantum;
            if (task->remaining_time <= 0) {
                printf("Time: %d, task %s finished\n", time, task->name);
                free(task->name);
            } else {
                enqueue_task(queue, task);
            }
        }
    }

    destroy_task_queue(queue);

    return 0;
}