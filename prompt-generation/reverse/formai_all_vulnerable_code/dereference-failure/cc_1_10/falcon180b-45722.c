//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_TASKS 100
#define STACK_SIZE 1024

struct task {
    void (*func)(void *);
    void *arg;
    struct task *next;
};

void *task_thread(void *param) {
    struct task *task = (struct task *) param;
    task->func(task->arg);
    free(task);
    return NULL;
}

int task_queue_push(struct task **head, void (*func)(void *), void *arg) {
    struct task *task = malloc(sizeof(struct task));
    if (task == NULL) {
        return -1;
    }
    task->func = func;
    task->arg = arg;
    task->next = *head;
    *head = task;
    return 0;
}

int task_queue_pop(struct task **head) {
    struct task *task = *head;
    if (task == NULL) {
        return -1;
    }
    *head = task->next;
    free(task);
    return 0;
}

int task_queue_empty(struct task *head) {
    return head == NULL;
}

int main() {
    struct task *head = NULL;
    int i;

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        int delay = rand() % 5;
        printf("Task %d will be executed after %d seconds\n", i+1, delay);
        task_queue_push(&head, task_thread, malloc(sizeof(int)));
        *(int *)((char *)head->arg - sizeof(int)) = delay;
    }

    while (!task_queue_empty(head)) {
        sleep(1);
    }

    return 0;
}