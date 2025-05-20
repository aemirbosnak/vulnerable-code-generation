//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct Task {
    int id;
    char *name;
    void (*func)(void *);
    void *args;
    struct timeval start_time;
    struct timeval end_time;
    int status; // 0: not started, 1: running, 2: finished
} Task;

typedef struct TaskQueue {
    Task *tasks[100];
    int head;
    int tail;
    int size;
} TaskQueue;

TaskQueue *task_queue_create(void) {
    TaskQueue *queue = malloc(sizeof(TaskQueue));
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    return queue;
}

void task_queue_enqueue(TaskQueue *queue, Task *task) {
    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % 100;
    queue->size++;
}

Task *task_queue_dequeue(TaskQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    Task *task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % 100;
    queue->size--;
    return task;
}

void task_schedule(TaskQueue *queue) {
    while (queue->size > 0) {
        Task *task = task_queue_dequeue(queue);
        task->status = 1;
        task->func(task->args);
        task->status = 2;
        gettimeofday(&task->end_time, NULL);
        printf("Task %d (%s) finished.\n", task->id, task->name);
    }
}

void task1(void *args) {
    printf("Task 1 started.\n");
    sleep(1);
    printf("Task 1 finished.\n");
}

void task2(void *args) {
    printf("Task 2 started.\n");
    sleep(2);
    printf("Task 2 finished.\n");
}

int main(void) {
    TaskQueue *queue = task_queue_create();

    Task *task1 = malloc(sizeof(Task));
    task1->id = 1;
    task1->name = "Task 1";
    task1->func = task1;
    task1->args = NULL;
    gettimeofday(&task1->start_time, NULL);

    Task *task2 = malloc(sizeof(Task));
    task2->id = 2;
    task2->name = "Task 2";
    task2->func = task2;
    task2->args = NULL;
    gettimeofday(&task2->start_time, NULL);

    task_queue_enqueue(queue, task1);
    task_queue_enqueue(queue, task2);

    task_schedule(queue);

    return 0;
}