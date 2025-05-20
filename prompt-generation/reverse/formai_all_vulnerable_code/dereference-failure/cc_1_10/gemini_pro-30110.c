//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    void (*func)(void *);
    void *arg;
} task_t;

typedef struct schedule {
    task_t tasks[MAX_TASKS];
    int num_tasks;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} schedule_t;

schedule_t schedule;

void schedule_init() {
    pthread_mutex_init(&schedule.lock, NULL);
    pthread_cond_init(&schedule.cond, NULL);
}

void schedule_destroy() {
    pthread_mutex_destroy(&schedule.lock);
    pthread_cond_destroy(&schedule.cond);
}

void schedule_add(void (*func)(void *), void *arg) {
    pthread_mutex_lock(&schedule.lock);
    if (schedule.num_tasks < MAX_TASKS) {
        schedule.tasks[schedule.num_tasks].func = func;
        schedule.tasks[schedule.num_tasks].arg = arg;
        schedule.num_tasks++;
    }
    pthread_mutex_unlock(&schedule.lock);
}

void *schedule_run(void *arg) {
    while (1) {
        pthread_mutex_lock(&schedule.lock);
        while (schedule.num_tasks == 0) {
            pthread_cond_wait(&schedule.cond, &schedule.lock);
        }
        task_t task = schedule.tasks[0];
        for (int i = 0; i < schedule.num_tasks - 1; i++) {
            schedule.tasks[i] = schedule.tasks[i + 1];
        }
        schedule.num_tasks--;
        pthread_mutex_unlock(&schedule.lock);
        task.func(task.arg);
    }
}

void thread_function(void *arg) {
    int *num = (int *)arg;
    printf("Thread %d started\n", *num);
    sleep(1);
    printf("Thread %d finished\n", *num);
}

int main() {
    schedule_init();
    pthread_t thread;
    pthread_create(&thread, NULL, schedule_run, NULL);
    for (int i = 0; i < 10; i++) {
        int *num = malloc(sizeof(int));
        *num = i;
        schedule_add(thread_function, num);
    }
    pthread_join(thread, NULL);
    schedule_destroy();
    return 0;
}