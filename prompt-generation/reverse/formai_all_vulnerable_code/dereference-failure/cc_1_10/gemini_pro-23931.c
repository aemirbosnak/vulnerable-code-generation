//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Task structure
typedef struct task {
    void (*func)(void *arg);  // Function pointer
    void *arg;               // Argument to the function
    struct task *next;       // Next task in the queue
} task;

// Task queue
static task *task_queue = NULL;

// Mutex to protect the task queue
static pthread_mutex_t task_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal that a task has been added to the queue
static pthread_cond_t task_queue_cond = PTHREAD_COND_INITIALIZER;

// Function to add a task to the queue
void task_add(void (*func)(void *arg), void *arg) {
    // Allocate memory for the new task
    task *new_task = malloc(sizeof(task));
    if (!new_task) {
        perror("malloc");
        exit(1);
    }

    // Initialize the new task
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    // Lock the task queue
    pthread_mutex_lock(&task_queue_mutex);

    // Add the new task to the end of the queue
    if (task_queue) {
        task *last_task = task_queue;
        while (last_task->next) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    } else {
        task_queue = new_task;
    }

    // Unlock the task queue
    pthread_mutex_unlock(&task_queue_mutex);

    // Signal that a task has been added to the queue
    pthread_cond_signal(&task_queue_cond);
}

// Function to get the next task from the queue
task *task_get() {
    // Lock the task queue
    pthread_mutex_lock(&task_queue_mutex);

    // Wait for a task to be added to the queue
    while (!task_queue) {
        pthread_cond_wait(&task_queue_cond, &task_queue_mutex);
    }

    // Get the next task from the queue
    task *next_task = task_queue;
    task_queue = task_queue->next;

    // Unlock the task queue
    pthread_mutex_unlock(&task_queue_mutex);

    // Return the next task
    return next_task;
}

// Function to run a task
void task_run(task *task) {
    // Call the task function
    task->func(task->arg);

    // Free the task memory
    free(task);
}

// Task 1: Print a message
void task1(void *arg) {
    printf("Task 1: %s\n", (char *) arg);
}

// Task 2: Sleep for a while
void task2(void *arg) {
    sleep(1);
    printf("Task 2: %s\n", (char *) arg);
}

// Main function
int main() {
    // Add tasks to the queue
    task_add(task1, "Hello, world!");
    task_add(task2, "Goodbye, world!");

    // Run the tasks
    while (task_queue) {
        task *next_task = task_get();
        task_run(next_task);
    }

    return 0;
}