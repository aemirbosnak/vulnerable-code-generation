//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    void (*func)(void *);
    void *arg;
    unsigned int delay;
    unsigned int period;
    unsigned int num_executions;
    unsigned int executions_left;
    struct task *next;
} task_t;

task_t *head = NULL;
task_t *tail = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void add_task(void (*func)(void *), void *arg, unsigned int delay, unsigned int period, unsigned int num_executions) {
    task_t *new_task = malloc(sizeof(task_t));
    new_task->func = func;
    new_task->arg = arg;
    new_task->delay = delay;
    new_task->period = period;
    new_task->num_executions = num_executions;
    new_task->executions_left = num_executions;
    new_task->next = NULL;

    pthread_mutex_lock(&mutex);
    if (head == NULL) {
        head = new_task;
        tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void *task_scheduler(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (head == NULL) {
            pthread_cond_wait(&cond, &mutex);
        }

        task_t *current_task = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        pthread_mutex_unlock(&mutex);

        if (current_task->executions_left == 0) {
            free(current_task);
            continue;
        }

        current_task->executions_left--;

        usleep(current_task->delay * 1000);
        current_task->func(current_task->arg);

        if (current_task->period > 0) {
            add_task(current_task->func, current_task->arg, current_task->period, current_task->period, current_task->num_executions);
        } else {
            free(current_task);
        }
    }

    return NULL;
}

void task1(void *arg) {
    printf("Task 1 executing\n");
}

void task2(void *arg) {
    printf("Task 2 executing\n");
}

void task3(void *arg) {
    printf("Task 3 executing\n");
}

int main() {
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);

    add_task(task1, NULL, 0, 1000, 5);
    add_task(task2, NULL, 2000, 2000, 10);
    add_task(task3, NULL, 3000, 3000, 0);

    pthread_join(scheduler_thread, NULL);

    return 0;
}