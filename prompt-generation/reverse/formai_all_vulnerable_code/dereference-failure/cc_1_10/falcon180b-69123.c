//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    void (*func)(void *arg);
    void *arg;
    struct task *next;
} Task;

Task *task_list = NULL;
pthread_mutex_t task_list_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_task(void (*func)(void *arg), void *arg) {
    Task *new_task = malloc(sizeof(Task));

    if (new_task == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    pthread_mutex_lock(&task_list_mutex);
    if (task_list == NULL) {
        task_list = new_task;
    } else {
        Task *curr_task = task_list;
        while (curr_task->next!= NULL) {
            curr_task = curr_task->next;
        }
        curr_task->next = new_task;
    }
    pthread_mutex_unlock(&task_list_mutex);
}

void *task_thread(void *arg) {
    Task *task = arg;

    task->func(task->arg);

    free(task);

    return NULL;
}

int main() {
    add_task(task_thread, NULL);

    for (int i = 0; i < MAX_TASKS; i++) {
        add_task(task_thread, (void *)i);
    }

    return 0;
}