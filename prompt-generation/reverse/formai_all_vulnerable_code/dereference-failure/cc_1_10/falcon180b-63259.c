//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void (*func)(void *);
    void *arg;
    struct task *next;
};

struct task *head = NULL;

void add_task(char *name, int priority, void (*func)(void *), void *arg) {
    struct task *new_task = (struct task *)malloc(sizeof(struct task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        struct task *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
}

void execute_tasks() {
    pthread_t threads[MAX_TASKS];
    int i = 0;

    struct task *current_task = head;
    while (current_task!= NULL) {
        pthread_create(&threads[i], NULL, (void *)current_task->func, current_task->arg);
        current_task = current_task->next;
        i++;
    }

    for (int j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }
}

void *task_runner(void *arg) {
    struct task *current_task = (struct task *)arg;
    current_task->func(current_task->arg);
    return NULL;
}

int main() {
    add_task("Task 1", 1, task_runner, NULL);
    add_task("Task 2", 2, task_runner, NULL);
    add_task("Task 3", 3, task_runner, NULL);

    execute_tasks();

    return 0;
}