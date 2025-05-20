//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define THREAD_POOL_SIZE 4
#define MAX_TASKS 10

typedef struct {
    void (*function)(void *);
    void *argument;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    bool stop;
} ThreadPool;

pthread_t threads[THREAD_POOL_SIZE];

void *worker(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    
    while (true) {
        pthread_mutex_lock(&pool->lock);
        
        while (pool->task_count == 0 && !pool->stop) {
            pthread_cond_wait(&pool->cond, &pool->lock);
        }

        if (pool->stop && pool->task_count == 0) {
            pthread_mutex_unlock(&pool->lock);
            break;
        }

        Task task = pool->tasks[--pool->task_count];
        pthread_mutex_unlock(&pool->lock);
        
        // Execute the task function
        task.function(task.argument);
    }
    
    return NULL;
}

ThreadPool *create_thread_pool() {
    ThreadPool *pool = malloc(sizeof(ThreadPool));
    pool->task_count = 0;
    pool->stop = false;
    pthread_mutex_init(&pool->lock, NULL);
    pthread_cond_init(&pool->cond, NULL);
    
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&threads[i], NULL, worker, pool);
    }
    
    return pool;
}

void submit_task(ThreadPool *pool, void (*function)(void *), void *argument) {
    pthread_mutex_lock(&pool->lock);
    
    if (pool->task_count < MAX_TASKS) {
        pool->tasks[pool->task_count].function = function;
        pool->tasks[pool->task_count].argument = argument;
        pool->task_count++;
        pthread_cond_signal(&pool->cond);
    } else {
        printf("Task queue full\n");
    }
    
    pthread_mutex_unlock(&pool->lock);
}

void destroy_thread_pool(ThreadPool *pool) {
    pthread_mutex_lock(&pool->lock);
    pool->stop = true;
    pthread_cond_broadcast(&pool->cond);
    pthread_mutex_unlock(&pool->lock);
    
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&pool->lock);
    pthread_cond_destroy(&pool->cond);
    free(pool);
}

void example_task(void *arg) {
    int id = *(int *)arg;
    printf("Task %d is being executed by thread %lu\n", id, pthread_self());
    sleep(1); // Simulating work by sleeping
}

int main() {
    ThreadPool *pool = create_thread_pool();
    
    for (int i = 0; i < 10; i++) {
        int *task_id = malloc(sizeof(int));
        *task_id = i;
        submit_task(pool, example_task, task_id);
    }

    sleep(5); // Let tasks run for a while
    destroy_thread_pool(pool);
    
    return 0;
}