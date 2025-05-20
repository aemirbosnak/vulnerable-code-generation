//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    pthread_t thread;
    void (*func)(void *);
    void *arg;
    int priority;
    int count;
} Task;

void *task_thread(void *arg) {
    Task *task = (Task *)arg;
    for (int i = 0; i < task->count; i++) {
        task->func(task->arg);
        usleep(task->priority);
    }
    pthread_exit(NULL);
}

void *task_func(void *arg) {
    printf("Task %d started\n", *(int *)arg);
    sleep(2);
    printf("Task %d completed\n", *(int *)arg);
    return NULL;
}

int main() {
    srand(time(NULL));
    int num_tasks = 5;
    int num_threads = 2;
    int task_priority[] = {50, 100, 200, 300, 400};
    int task_count[] = {1, 2, 3, 4, 5};
    int *task_arg = malloc(num_tasks * sizeof(int));
    for (int i = 0; i < num_tasks; i++) {
        task_arg[i] = i;
    }
    Task *tasks = malloc(num_tasks * sizeof(Task));
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].thread = 0;
        tasks[i].func = task_func;
        tasks[i].arg = (void *)task_arg[i];
        tasks[i].priority = task_priority[i];
        tasks[i].count = task_count[i];
    }
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, task_thread, (void *)&tasks[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(task_arg);
    free(tasks);
    return 0;
}