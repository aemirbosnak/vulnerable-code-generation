//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct Task {
    char* message;
} Task;

typedef struct ThreadPool {
    int num_threads;
    int head;
    int tail;
    pthread_t* threads;
    Task* tasks;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} ThreadPool;

void* thread_func(void* arg) {
    ThreadPool* pool = (ThreadPool*) arg;
    while (1) {
        pthread_mutex_lock(&(pool->lock));

        while (pool->head == pool->tail) {
            pthread_cond_wait(&(pool->not_empty), &(pool->lock));
        }

        Task task = pool->tasks[pool->head];
        pool->head = (pool->head + 1) % NUM_THREADS;

        pthread_mutex_unlock(&(pool->lock));
        pthread_cond_signal(&(pool->not_full));

        printf("Thread %ld: %s\n", pthread_self(), task.message);
    }
}

ThreadPool* create_thread_pool(int num_threads) {
    ThreadPool* pool = (ThreadPool*) malloc(sizeof(ThreadPool));
    pool->num_threads = num_threads;
    pool->head = 0;
    pool->tail = 0;
    pool->threads = (pthread_t*) malloc(num_threads * sizeof(pthread_t));
    pool->tasks = (Task*) malloc(NUM_THREADS * sizeof(Task));
    pthread_mutex_init(&(pool->lock), NULL);
    pthread_cond_init(&(pool->not_empty), NULL);
    pthread_cond_init(&(pool->not_full), NULL);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&(pool->threads[i]), NULL, thread_func, (void*) pool);
    }

    return pool;
}

void add_task(ThreadPool* pool, Task task) {
    pthread_mutex_lock(&(pool->lock));

    while ((pool->tail + 1) % NUM_THREADS == pool->head) {
        pthread_cond_wait(&(pool->not_full), &(pool->lock));
    }

    pool->tasks[pool->tail] = task;
    pool->tail = (pool->tail + 1) % NUM_THREADS;

    pthread_mutex_unlock(&(pool->lock));
    pthread_cond_signal(&(pool->not_empty));
}

int main() {
    ThreadPool* pool = create_thread_pool(NUM_THREADS);

    Task tasks[NUM_THREADS] = {
        {"Task 1"},
        {"Task 2"},
        {"Task 3"},
        {"Task 4"},
        {"Task 5"},
    };

    for (int i = 0; i < NUM_THREADS; i++) {
        add_task(pool, tasks[i]);
    }

    while (1) {

    }

    return 0;
}