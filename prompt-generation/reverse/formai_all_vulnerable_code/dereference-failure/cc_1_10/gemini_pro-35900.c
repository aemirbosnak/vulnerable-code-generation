//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    int priority;       // Task priority
    void (*func)(void*); // Task function
    void *args;         // Task arguments
    struct task *next;   // Next task in the queue
} task_t;

// Task queue
task_t *task_queue = NULL;

// Mutex to protect the task queue
pthread_mutex_t task_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to wait for the task queue to be non-empty
pthread_cond_t task_queue_cond = PTHREAD_COND_INITIALIZER;

// Thread function to execute tasks
void *task_executor(void *args) {
    while (1) {
        // Lock the task queue mutex
        pthread_mutex_lock(&task_queue_mutex);

        // Wait for the task queue to be non-empty
        while (task_queue == NULL) {
            pthread_cond_wait(&task_queue_cond, &task_queue_mutex);
        }

        // Get the first task from the queue
        task_t *task = task_queue;
        task_queue = task->next;

        // Unlock the task queue mutex
        pthread_mutex_unlock(&task_queue_mutex);

        // Execute the task
        task->func(task->args);

        // Free the task
        free(task);
    }

    return NULL;
}

// Function to add a task to the task queue
void task_add(int id, int priority, void (*func)(void*), void *args) {
    // Allocate memory for the new task
    task_t *task = malloc(sizeof(task_t));

    // Initialize the new task
    task->id = id;
    task->priority = priority;
    task->func = func;
    task->args = args;
    task->next = NULL;

    // Lock the task queue mutex
    pthread_mutex_lock(&task_queue_mutex);

    // Add the new task to the queue
    if (task_queue == NULL) {
        task_queue = task;
    } else {
        task_t *curr = task_queue;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = task;
    }

    // Unlock the task queue mutex
    pthread_mutex_unlock(&task_queue_mutex);

    // Signal the condition variable to wake up the task executor thread
    pthread_cond_signal(&task_queue_cond);
}

// Example task function
void task_func(void *args) {
    int *id = (int *)args;
    printf("Executing task %d\n", *id);
}

// Main function
int main() {
    // Create the task executor thread
    pthread_t task_executor_thread;
    pthread_create(&task_executor_thread, NULL, task_executor, NULL);

    // Add some tasks to the task queue
    for (int i = 0; i < 10; i++) {
        task_add(i, rand() % 10, task_func, &i);
    }

    // Join the task executor thread
    pthread_join(task_executor_thread, NULL);

    return 0;
}