//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_THREADS 4
#define MAX_QUEUE_SIZE 10

typedef struct Task {
    void (*function)(void*);
    void *arg;
} Task;

typedef struct ThreadPool {
    pthread_t threads[MAX_THREADS];
    Task *taskQueue[MAX_QUEUE_SIZE];
    int queueSize;
    int head;
    int tail;
    bool stop;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} ThreadPool;

void* threadFunction(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    
    while (true) {
        pthread_mutex_lock(&pool->mutex);

        while (pool->queueSize == 0 && !pool->stop) {
            pthread_cond_wait(&pool->cond, &pool->mutex);
        }

        if (pool->stop) {
            pthread_mutex_unlock(&pool->mutex);
            break;
        }
        
        Task *task = pool->taskQueue[pool->head];
        pool->head = (pool->head + 1) % MAX_QUEUE_SIZE;
        pool->queueSize--;

        pthread_mutex_unlock(&pool->mutex);

        task->function(task->arg);
        free(task);
    }

    return NULL;
}

ThreadPool* createThreadPool() {
    ThreadPool *pool = malloc(sizeof(ThreadPool));
    pool->queueSize = 0;
    pool->head = 0;
    pool->tail = 0;
    pool->stop = false;
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->cond, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&pool->threads[i], NULL, threadFunction, pool);
    }
    
    return pool;
}

void addTask(ThreadPool *pool, void (*function)(void*), void *arg) {
    pthread_mutex_lock(&pool->mutex);
    
    if (pool->queueSize < MAX_QUEUE_SIZE) {
        Task *task = malloc(sizeof(Task));
        task->function = function;
        task->arg = arg;
        
        pool->taskQueue[pool->tail] = task;
        pool->tail = (pool->tail + 1) % MAX_QUEUE_SIZE;
        pool->queueSize++;
        
        pthread_cond_signal(&pool->cond);
    } else {
        fprintf(stderr, "Task queue is full!\n");
    }
    
    pthread_mutex_unlock(&pool->mutex);
}

void destroyThreadPool(ThreadPool *pool) {
    pthread_mutex_lock(&pool->mutex);
    pool->stop = true;
    pthread_cond_broadcast(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(pool->threads[i], NULL);
    }

    for (int i = 0; i < pool->queueSize; i++) {
        free(pool->taskQueue[i]);
    }

    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    free(pool);
}

void sampleTask(void *arg) {
    int *num = (int *)arg;
    printf("Task %d is running on thread %ld\n", *num, pthread_self());
    sleep(1); // Simulating work
}

int main() {
    ThreadPool *pool = createThreadPool();

    for (int i = 1; i <= 15; i++) {
        int *num = malloc(sizeof(int));
        *num = i;
        addTask(pool, sampleTask, num);
    }

    sleep(5); // Let workers finish processing
    destroyThreadPool(pool);
    
    return 0;
}