//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a task structure
typedef struct task {
    int id;
    void (*routine)(void *);
    void *arg;
} task_t;

// Define a thread pool structure
typedef struct thread_pool {
    int num_threads;
    pthread_t *threads;
    task_t **tasks;
    int num_tasks;
    int tasks_idx;
    pthread_cond_t cond;
    pthread_mutex_t lock;
} thread_pool_t;

// Create a thread pool
thread_pool_t *create_thread_pool(int num_threads) {
    thread_pool_t *pool = malloc(sizeof(thread_pool_t));
    pool->num_threads = num_threads;
    pool->threads = malloc(sizeof(pthread_t) * num_threads);
    pool->tasks = malloc(sizeof(task_t *) * num_threads);
    pool->num_tasks = 0;
    pool->tasks_idx = 0;
    pthread_cond_init(&pool->cond, NULL);
    pthread_mutex_init(&pool->lock, NULL);
    return pool;
}

// Destroy a thread pool
void destroy_thread_pool(thread_pool_t *pool) {
    for (int i = 0; i < pool->num_threads; i++) {
        pthread_join(pool->threads[i], NULL);
    }
    pthread_cond_destroy(&pool->cond);
    pthread_mutex_destroy(&pool->lock);
    free(pool->threads);
    free(pool->tasks);
    free(pool);
}

// Add a task to the thread pool
void add_task(thread_pool_t *pool, int id, void (*routine)(void *), void *arg) {
    pthread_mutex_lock(&pool->lock);
    while (pool->num_tasks == pool->num_threads) {
        pthread_cond_wait(&pool->cond, &pool->lock);
    }
    pool->tasks[pool->tasks_idx] = malloc(sizeof(task_t));
    pool->tasks[pool->tasks_idx]->id = id;
    pool->tasks[pool->tasks_idx]->routine = routine;
    pool->tasks[pool->tasks_idx]->arg = arg;
    pool->num_tasks++;
    pool->tasks_idx = (pool->tasks_idx + 1) % pool->num_threads;
    pthread_mutex_unlock(&pool->lock);
    pthread_cond_signal(&pool->cond);
}

// Thread pool worker function
void *thread_pool_worker(void *arg) {
    thread_pool_t *pool = (thread_pool_t *)arg;
    while (1) {
        pthread_mutex_lock(&pool->lock);
        while (pool->num_tasks == 0) {
            pthread_cond_wait(&pool->cond, &pool->lock);
        }
        task_t *task = pool->tasks[pool->tasks_idx];
        pool->tasks[pool->tasks_idx] = NULL;
        pool->num_tasks--;
        pool->tasks_idx = (pool->tasks_idx + 1) % pool->num_threads;
        pthread_mutex_unlock(&pool->lock);
        task->routine(task->arg);
        free(task);
        pthread_cond_signal(&pool->cond);
    }
    return NULL;
}

// Example task routine
void task_routine(void *arg) {
    int id = *((int *)arg);
    printf("Task %d executed\n", id);
}

// Main function
int main() {
    // Create a thread pool with 4 threads
    thread_pool_t *pool = create_thread_pool(4);

    // Add 10 tasks to the thread pool
    for (int i = 0; i < 10; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        add_task(pool, i, task_routine, id);
    }

    // Destroy the thread pool
    destroy_thread_pool(pool);

    return 0;
}