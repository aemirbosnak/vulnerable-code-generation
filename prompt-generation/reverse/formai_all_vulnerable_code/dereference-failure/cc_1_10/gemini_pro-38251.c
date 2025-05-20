//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Task structure
typedef struct task {
    void (*func)(void *);  // Function pointer
    void *arg;             // Argument to pass to the function
    struct task *next;      // Pointer to the next task in the queue
} task_t;

// Queue of tasks
task_t *queue = NULL;

// Mutex to protect the queue
pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when a task is added to the queue
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

// Thread function
void *thread_func(void *arg) {
    while (1) {
        // Lock the queue
        pthread_mutex_lock(&queue_lock);

        // Wait until a task is added to the queue
        while (queue == NULL) {
            pthread_cond_wait(&queue_cond, &queue_lock);
        }

        // Get the next task from the queue
        task_t *task = queue;
        queue = queue->next;

        // Unlock the queue
        pthread_mutex_unlock(&queue_lock);

        // Execute the task
        task->func(task->arg);

        // Free the task
        free(task);
    }

    return NULL;
}

// Add a task to the queue
void add_task(void (*func)(void *), void *arg) {
    // Create a new task
    task_t *task = malloc(sizeof(task_t));
    if (task == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Initialize the task
    task->func = func;
    task->arg = arg;
    task->next = NULL;

    // Lock the queue
    pthread_mutex_lock(&queue_lock);

    // Add the task to the queue
    if (queue == NULL) {
        queue = task;
    } else {
        task->next = queue;
        queue = task;
    }

    // Signal that a task has been added to the queue
    pthread_cond_signal(&queue_cond);

    // Unlock the queue
    pthread_mutex_unlock(&queue_lock);
}

// Create a thread pool
void create_thread_pool(int num_threads) {
    // Create an array of threads
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    if (threads == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Free the array of threads
    free(threads);
}

// Destroy the thread pool
void destroy_thread_pool() {
    // Lock the queue
    pthread_mutex_lock(&queue_lock);

    // Signal that the thread pool is being destroyed
    pthread_cond_broadcast(&queue_cond);

    // Unlock the queue
    pthread_mutex_unlock(&queue_lock);
}

// Example task function
void task_func(void *arg) {
    printf("Task %d executed\n", (int) arg);
}

int main() {
    // Create a thread pool with 4 threads
    create_thread_pool(4);

    // Add some tasks to the queue
    for (int i = 0; i < 10; i++) {
        add_task(task_func, (void *) i);
    }

    // Destroy the thread pool
    destroy_thread_pool();

    return 0;
}