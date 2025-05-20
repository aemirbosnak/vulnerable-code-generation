//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Define the task structure
typedef struct task {
    int id;             // Task ID
    int priority;       // Task priority
    void* (*func)(void*);    // Task function pointer
    void* arg;           // Task argument
    struct task* next;    // Next task in the queue
} task_t;

// Define the task queue
task_t* task_queue = NULL;

// Mutex to protect the task queue
pthread_mutex_t task_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal that a task has been added to the queue
pthread_cond_t task_queue_cond = PTHREAD_COND_INITIALIZER;

// Thread function to execute tasks
void* task_executor(void* arg) {
    while (1) {
        // Acquire the task queue mutex
        pthread_mutex_lock(&task_queue_mutex);

        // Wait for a task to be added to the queue
        pthread_cond_wait(&task_queue_cond, &task_queue_mutex);

        // Get the task from the queue
        task_t* task = task_queue;
        task_queue = task->next;

        // Release the task queue mutex
        pthread_mutex_unlock(&task_queue_mutex);

        // Execute the task
        task->func(task->arg);

        // Free the task
        free(task);
    }

    return NULL;
}

// Function to add a task to the queue
void task_add(int id, int priority, void* (*func)(void*), void* arg) {
    // Create a new task
    task_t* task = malloc(sizeof(task_t));
    task->id = id;
    task->priority = priority;
    task->func = func;
    task->arg = arg;
    task->next = NULL;

    // Acquire the task queue mutex
    pthread_mutex_lock(&task_queue_mutex);

    // Add the task to the queue
    if (task_queue == NULL) {
        task_queue = task;
    } else {
        task_t* prev = NULL;
        task_t* curr = task_queue;
        while (curr != NULL && curr->priority >= priority) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            task->next = task_queue;
            task_queue = task;
        } else {
            prev->next = task;
            task->next = curr;
        }
    }

    // Signal that a task has been added to the queue
    pthread_cond_signal(&task_queue_cond);

    // Release the task queue mutex
    pthread_mutex_unlock(&task_queue_mutex);
}

// Function to create the task scheduler
void task_scheduler_create(int num_threads) {
    // Create threads to execute tasks
    for (int i = 0; i < num_threads; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, task_executor, NULL);
    }
}

// Function to destroy the task scheduler
void task_scheduler_destroy() {
    // Destroy the task queue mutex
    pthread_mutex_destroy(&task_queue_mutex);

    // Destroy the task queue condition variable
    pthread_cond_destroy(&task_queue_cond);
}

// Example task function
void* task_function(void* arg) {
    // Get the task ID
    int id = *(int*)arg;

    // Sleep for a random amount of time
    srand(time(NULL));
    int sleep_time = rand() % 1000;
    sleep(sleep_time);

    // Print the task ID and sleep time
    printf("Task %d slept for %d milliseconds\n", id, sleep_time);

    return NULL;
}

// Main function
int main() {
    // Create the task scheduler
    task_scheduler_create(4);

    // Add tasks to the queue
    for (int i = 0; i < 10; i++) {
        int id = i;
        int priority = rand() % 10;
        task_add(id, priority, task_function, &id);
    }

    // Wait for all tasks to complete
    sleep(10);

    // Destroy the task scheduler
    task_scheduler_destroy();

    return 0;
}