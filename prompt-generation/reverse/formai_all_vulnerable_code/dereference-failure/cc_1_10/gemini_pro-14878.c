//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

// Maximum number of tasks
#define MAX_TASKS 100

// Task structure
typedef struct {
    int id;
    int priority;
    int delay; // in seconds
    void (*func)(void *);
    void *args;
} task_t;

// Task queue
task_t *tasks[MAX_TASKS];

// Task queue size
int task_size = 0;

// Mutex to protect the task queue
pthread_mutex_t task_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when a task is added to the queue
pthread_cond_t task_added_cond = PTHREAD_COND_INITIALIZER;

// Thread function to process tasks
void *task_processor(void *args) {
    while (true) {
        // Lock the task queue
        pthread_mutex_lock(&task_queue_mutex);

        // Wait for a task to be added to the queue
        pthread_cond_wait(&task_added_cond, &task_queue_mutex);

        // Get the first task from the queue
        task_t *task = tasks[0];

        // Remove the task from the queue
        for (int i = 0; i < task_size - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_size--;

        // Unlock the task queue
        pthread_mutex_unlock(&task_queue_mutex);

        // Execute the task
        task->func(task->args);

        // Free the task
        free(task);
    }
    return NULL;
}

// Function to add a task to the queue
void add_task(task_t *task) {
    // Lock the task queue
    pthread_mutex_lock(&task_queue_mutex);

    // Add the task to the queue
    tasks[task_size] = task;
    task_size++;

    // Signal that a task has been added to the queue
    pthread_cond_signal(&task_added_cond);

    // Unlock the task queue
    pthread_mutex_unlock(&task_queue_mutex);
}

// Example task function
void print_hello(void *args) {
    char *name = (char *)args;
    printf("Hello, %s!\n", name);
}

int main() {
    // Create a thread to process tasks
    pthread_t thread;
    pthread_create(&thread, NULL, task_processor, NULL);

    // Add some tasks to the queue
    for (int i = 0; i < 10; i++) {
        task_t *task = malloc(sizeof(task_t));
        task->id = i;
        task->priority = 1;
        task->delay = 1;
        task->func = print_hello;
        task->args = "John";
        add_task(task);
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}