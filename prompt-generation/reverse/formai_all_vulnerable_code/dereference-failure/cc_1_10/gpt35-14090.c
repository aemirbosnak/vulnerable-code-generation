//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    void (*func)(void* arg);
    void* arg;
} task_t;

typedef struct scheduler {
    task_t* task_queue[MAX_TASKS];
    int num_tasks;
    pthread_t* threads;
    int num_threads;
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
    int quit;
} scheduler_t;

scheduler_t* scheduler_init(int num_threads);
void scheduler_destroy(scheduler_t* sched);
void scheduler_add_task(scheduler_t* sched, void (*func)(void* arg), void* arg);
void* scheduler_worker(void* arg);

scheduler_t* scheduler_init(int num_threads) {
    scheduler_t* sched = (scheduler_t*)malloc(sizeof(scheduler_t));
    sched->num_threads = num_threads;
    sched->num_tasks = 0;
    sched->quit = 0;
    pthread_mutex_init(&sched->mutex, NULL);
    pthread_cond_init(&sched->cond_var, NULL);
    sched->threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&sched->threads[i], NULL, scheduler_worker, (void*)sched);
    }
    return sched;
}

void scheduler_destroy(scheduler_t* sched) {
    pthread_mutex_lock(&sched->mutex);
    sched->quit = 1;
    pthread_cond_broadcast(&sched->cond_var);
    pthread_mutex_unlock(&sched->mutex);
    for (int i = 0; i < sched->num_threads; i++) {
        pthread_join(sched->threads[i], NULL);
    }
    pthread_mutex_destroy(&sched->mutex);
    pthread_cond_destroy(&sched->cond_var);
    free(sched->threads);
    free(sched);
}

void scheduler_add_task(scheduler_t* sched, void (*func)(void* arg), void* arg) {
    pthread_mutex_lock(&sched->mutex);
    if (sched->num_tasks == MAX_TASKS) {
        fprintf(stderr, "Error: Task queue is full\n");
        return;
    }
    task_t* task = (task_t*)malloc(sizeof(task_t));
    task->func = func;
    task->arg = arg;
    sched->task_queue[sched->num_tasks] = task;
    sched->num_tasks++;
    pthread_cond_signal(&sched->cond_var);
    pthread_mutex_unlock(&sched->mutex);
}

void* scheduler_worker(void* arg) {
    scheduler_t* sched = (scheduler_t*)arg;
    while (1) {
        pthread_mutex_lock(&sched->mutex);
        while (sched->num_tasks == 0 && !sched->quit) {
            pthread_cond_wait(&sched->cond_var, &sched->mutex);
        }
        if (sched->quit) {
            pthread_mutex_unlock(&sched->mutex);
            break;
        }
        task_t* task = sched->task_queue[0];
        for (int i = 0; i < sched->num_tasks-1; i++) {
            sched->task_queue[i] = sched->task_queue[i+1];
        }
        sched->num_tasks--;
        pthread_mutex_unlock(&sched->mutex);
        task->func(task->arg);
        free(task);
    }
    return NULL;
}

void task1(void* arg) {
    printf("Task 1: Hello, Scheduler! %s\n", (char*)arg);
}

void task2(void* arg) {
    printf("Task 2: Goodbye, Scheduler! %d\n", *(int*)arg);
}

int main() {
    scheduler_t* sched = scheduler_init(2);
    char* msg = "I am a task argument";
    int num = 42;
    scheduler_add_task(sched, task1, (void*)msg);
    scheduler_add_task(sched, task2, (void*)&num);
    scheduler_destroy(sched);
    return 0;
}