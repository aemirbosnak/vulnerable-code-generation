//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define a custom thread pool structure
typedef struct thread_pool {
    int num_threads;          // Number of threads in the pool
    pthread_t *threads;        // Array of thread IDs
    pthread_mutex_t mutex;     // Mutex to protect the queue
    pthread_cond_t cond;       // Condition variable to signal when a task is available
    int num_tasks;            // Number of tasks in the queue
    void **tasks;            // Array of task pointers
} thread_pool_t;

// Function to initialize a thread pool
thread_pool_t *thread_pool_init(int num_threads) {
    thread_pool_t *pool = malloc(sizeof(thread_pool_t));
    pool->num_threads = num_threads;
    pool->threads = malloc(sizeof(pthread_t) * num_threads);
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->cond, NULL);
    pool->num_tasks = 0;
    pool->tasks = NULL;
    return pool;
}

// Function to destroy a thread pool
void thread_pool_destroy(thread_pool_t *pool) {
    for (int i = 0; i < pool->num_threads; i++) {
        pthread_join(pool->threads[i], NULL);
    }
    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    free(pool->threads);
    free(pool->tasks);
    free(pool);
}

// Function to add a task to the thread pool
void thread_pool_add_task(thread_pool_t *pool, void *task) {
    pthread_mutex_lock(&pool->mutex);
    pool->tasks = realloc(pool->tasks, sizeof(void *) * (pool->num_tasks + 1));
    pool->tasks[pool->num_tasks++] = task;
    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->mutex);
}

// Function to get a task from the thread pool
void *thread_pool_get_task(thread_pool_t *pool) {
    pthread_mutex_lock(&pool->mutex);
    while (pool->num_tasks == 0) {
        pthread_cond_wait(&pool->cond, &pool->mutex);
    }
    void *task = pool->tasks[0];
    pool->num_tasks--;
    for (int i = 0; i < pool->num_tasks; i++) {
        pool->tasks[i] = pool->tasks[i + 1];
    }
    pthread_mutex_unlock(&pool->mutex);
    return task;
}

// Function to run a task in a thread
void *thread_pool_run_task(void *arg) {
    thread_pool_t *pool = (thread_pool_t *)arg;
    while (1) {
        void *task = thread_pool_get_task(pool);
        if (task == NULL) {
            break;
        }
        ((void (*)())task)();
    }
    return NULL;
}

// Main function
int main() {
    // Create a thread pool with 4 threads
    thread_pool_t *pool = thread_pool_init(4);

    // Add 10 tasks to the thread pool
    for (int i = 0; i < 10; i++) {
        void *task = malloc(sizeof(int));
        *(int *)task = i;
        thread_pool_add_task(pool, task);
    }

    // Wait for all tasks to complete
    for (int i = 0; i < 10; i++) {
        void *task = thread_pool_get_task(pool);
        printf("Task %d completed\n", *(int *)task);
        free(task);
    }

    // Destroy the thread pool
    thread_pool_destroy(pool);

    return 0;
}