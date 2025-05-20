//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define TASK_QUEUE_SIZE 10

typedef struct task {
    int pid;
    int status;
    char *name;
} task_t;

typedef struct queue {
    task_t tasks[TASK_QUEUE_SIZE];
    int head;
    int tail;
} queue_t;

queue_t *queue;

void init_queue(void) {
    queue = malloc(sizeof(queue_t));
    queue->head = 0;
    queue->tail = 0;
}

void enqueue(char *name) {
    task_t task;
    task.pid = getpid();
    task.status = 0;
    task.name = name;
    if (queue->head == TASK_QUEUE_SIZE) {
        printf("Queue is full, dropping task: %s\n", name);
        return;
    }
    queue->tasks[queue->tail] = task;
    queue->tail++;
}

void dequeue(void) {
    if (queue->head == queue->tail) {
        printf("Queue is empty\n");
        return;
    }
    task_t task = queue->tasks[queue->head];
    queue->head++;
    printf("Dequeued task: %s (%d)\n", task.name, task.pid);
}

void run_task(int pid) {
    if (pid == getpid()) {
        printf("Can't run task with same PID\n");
        return;
    }
    char *name = malloc(100);
    snprintf(name, 100, "task%d", pid);
    enqueue(name);
}

int main(void) {
    init_queue();

    for (int i = 0; i < 5; i++) {
        run_task(i);
    }

    while (1) {
        dequeue();
    }

    return 0;
}