//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_THREADS 5
#define MAX_QUEUE 10

typedef struct {
    void (*function)(void *);
    void *arg;
} task_t;

typedef struct {
    pthread_mutex_t mutex;
    sem_t semaphore;
    task_t task_queue[MAX_QUEUE];
    int head, tail, count;
    int stop;
} thread_pool_t;

void *thread_worker(void *pool);

thread_pool_t *thread_pool_create(int num_threads) {
    thread_pool_t *pool = (thread_pool_t *)malloc(sizeof(thread_pool_t));
    pool->head = pool->tail = pool->count = 0;
    pool->stop = 0;
    pthread_mutex_init(&pool->mutex, NULL);
    sem_init(&pool->semaphore, 0, 0);
    
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, thread_worker, pool);
    }
    
    return pool;
}

void thread_pool_destroy(thread_pool_t *pool) {
    pthread_mutex_lock(&pool->mutex);
    pool->stop = 1;
    pthread_mutex_unlock(&pool->mutex);
    for (int i = 0; i < MAX_THREADS; ++i) {
        sem_post(&pool->semaphore); // Wake up all threads to exit
    }
    free(pool);
}

void thread_pool_add_task(thread_pool_t *pool, void (*function)(void *), void *arg) {
    pthread_mutex_lock(&pool->mutex);
    
    if (pool->count < MAX_QUEUE) {
        pool->task_queue[pool->tail].function = function;
        pool->task_queue[pool->tail].arg = arg;
        pool->tail = (pool->tail + 1) % MAX_QUEUE;
        pool->count++;
        sem_post(&pool->semaphore); // Notify one thread
    }
    
    pthread_mutex_unlock(&pool->mutex);
}

void *thread_worker(void *pool) {
    thread_pool_t *tpool = (thread_pool_t *)pool;
    
    while (1) {
        sem_wait(&tpool->semaphore);
        
        pthread_mutex_lock(&tpool->mutex);
        if (tpool->stop) {
            pthread_mutex_unlock(&tpool->mutex);
            break;
        }
        
        task_t task = tpool->task_queue[tpool->head];
        tpool->head = (tpool->head + 1) % MAX_QUEUE;
        tpool->count--;
        pthread_mutex_unlock(&tpool->mutex);
        
        task.function(task.arg);
    }
    
    return NULL;
}

void sample_task(void *arg) {
    int *num = (int *)arg;
    printf("Task executing with ID: %d\n", *num);
    sleep(1); // Simulate workload
}

int main() {
    thread_pool_t *pool = thread_pool_create(MAX_THREADS);
    
    for (int i = 0; i < 20; i++) {
        int *task_id = malloc(sizeof(*task_id));
        *task_id = i;
        thread_pool_add_task(pool, sample_task, task_id);
    }
    
    sleep(5); // Wait for tasks to finish
    thread_pool_destroy(pool);
    
    return 0;
}