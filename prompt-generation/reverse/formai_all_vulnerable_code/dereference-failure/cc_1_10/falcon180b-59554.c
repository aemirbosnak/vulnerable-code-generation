//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

typedef struct task {
    void (*func)(void *);
    void *arg;
    struct task *next;
} Task;

Task *task_list = NULL;
pthread_t thread_id[MAX_TASKS];
int task_count = 0;

void add_task(void (*func)(void *), void *arg) {
    Task *new_task = malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        Task *tmp = task_list;
        while (tmp->next!= NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_task;
    }

    task_count++;
}

void *thread_func(void *param) {
    Task *task = param;
    task->func(task->arg);
    free(task);
    return NULL;
}

int main() {
    add_task(printf, "Hello World!\n");
    add_task(printf, "Task Scheduler Example.\n");

    for (int i = 0; i < task_count; i++) {
        pthread_create(&thread_id[i], NULL, thread_func, task_list);
        task_list = task_list->next;
    }

    for (int i = 0; i < task_count; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}