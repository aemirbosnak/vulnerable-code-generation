//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    void (*function)(void *args);
    void *args;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

pthread_t threads[MAX_TASKS];

sem_t mutex;

void init_mutex() {
    sem_init(&mutex, 0, 1);
}

void add_task(char *name, int priority, void (*function)(void *args), void *args) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].function = function;
    tasks[num_tasks].args = args;

    num_tasks++;
}

void run_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, (void *)tasks[i].function, tasks[i].args);
    }
}

void *task_wrapper(void *args) {
    task_t *task = (task_t *)args;

    printf("Starting task %s with priority %d...\n", task->name, task->priority);

    sem_wait(&mutex);

    task->function(task->args);

    sem_post(&mutex);

    printf("Task %s completed.\n", task->name);

    return NULL;
}

int main() {
    init_mutex();

    add_task("Task 1", 1, (void *)task_wrapper, NULL);
    add_task("Task 2", 2, (void *)task_wrapper, NULL);
    add_task("Task 3", 3, (void *)task_wrapper, NULL);

    run_tasks();

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}