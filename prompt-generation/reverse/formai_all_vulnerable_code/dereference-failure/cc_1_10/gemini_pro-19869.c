//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

// Task data structure
typedef struct task {
    void (*func)(void *);    // Function pointer
    void *arg;              // Function argument
    int delay;              // Delay in seconds
    struct task *next;      // Next task in the queue
} task_t;

// Task queue
static task_t *task_queue;

// Mutex to protect the task queue
static pthread_mutex_t task_queue_mutex;

// Condition variable to signal when a task is added to the queue
static pthread_cond_t task_queue_cond;

// Flag to indicate whether the scheduler is running
static bool scheduler_running;

// Create a new task
task_t *task_create(void (*func)(void *), void *arg, int delay) {
    task_t *task = malloc(sizeof(task_t));
    task->func = func;
    task->arg = arg;
    task->delay = delay;
    task->next = NULL;
    return task;
}

// Add a task to the queue
void task_add(task_t *task) {
    pthread_mutex_lock(&task_queue_mutex);
    task->next = task_queue;
    task_queue = task;
    pthread_cond_signal(&task_queue_cond);
    pthread_mutex_unlock(&task_queue_mutex);
}

// Remove a task from the queue
task_t *task_remove() {
    pthread_mutex_lock(&task_queue_mutex);
    task_t *task = task_queue;
    if (task != NULL) {
        task_queue = task->next;
    }
    pthread_mutex_unlock(&task_queue_mutex);
    return task;
}

// Scheduler thread
void *scheduler(void *arg) {
    while (scheduler_running) {
        // Wait for a task to be added to the queue
        pthread_mutex_lock(&task_queue_mutex);
        while (task_queue == NULL) {
            pthread_cond_wait(&task_queue_cond, &task_queue_mutex);
        }
        // Get the next task from the queue
        task_t *task = task_remove();
        pthread_mutex_unlock(&task_queue_mutex);

        // Sleep for the specified delay
        sleep(task->delay);

        // Execute the task
        task->func(task->arg);

        // Free the task
        free(task);
    }
    return NULL;
}

// Start the scheduler
void scheduler_start() {
    scheduler_running = true;
    pthread_t thread;
    pthread_create(&thread, NULL, scheduler, NULL);
}

// Stop the scheduler
void scheduler_stop() {
    scheduler_running = false;
    pthread_cond_signal(&task_queue_cond);
}

// Example task function
void task_function(void *arg) {
    printf("Task %s executed\n", (char *)arg);
}

// Main function
int main() {
    // Initialize the task queue
    task_queue = NULL;

    // Initialize the mutex and condition variable
    pthread_mutex_init(&task_queue_mutex, NULL);
    pthread_cond_init(&task_queue_cond, NULL);

    // Add some tasks to the queue
    task_add(task_create(task_function, "A", 1));
    task_add(task_create(task_function, "B", 2));
    task_add(task_create(task_function, "C", 3));

    // Start the scheduler
    scheduler_start();

    // Wait for the scheduler to finish
    scheduler_stop();

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&task_queue_mutex);
    pthread_cond_destroy(&task_queue_cond);

    return 0;
}