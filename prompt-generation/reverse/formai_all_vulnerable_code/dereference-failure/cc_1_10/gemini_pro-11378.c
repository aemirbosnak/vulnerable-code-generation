//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TASKS 10

// Task structure
typedef struct task {
    int id;             // Task ID
    int priority;       // Task priority
    void (*func)(void*); // Task function
    void *arg;          // Task argument
} task_t;

// Task queue
static task_t task_queue[NUM_TASKS];
static int task_queue_head = 0;
static int task_queue_tail = 0;

// Semaphore to protect the task queue
static sem_t task_queue_sem;

// Thread function for the task scheduler
static void *task_scheduler(void *arg) {
    while (1) {
        // Wait for a task to be added to the queue
        sem_wait(&task_queue_sem);

        // Get the next task from the queue
        task_t task = task_queue[task_queue_head];
        task_queue_head = (task_queue_head + 1) % NUM_TASKS;

        // Execute the task
        task.func(task.arg);
    }

    return NULL;
}

// Function to add a task to the queue
void task_add(task_t task) {
    // Acquire the semaphore to protect the task queue
    sem_wait(&task_queue_sem);

    // Add the task to the queue
    task_queue[task_queue_tail] = task;
    task_queue_tail = (task_queue_tail + 1) % NUM_TASKS;

    // Release the semaphore
    sem_post(&task_queue_sem);
}

// Example task function
void task_func(void *arg) {
    printf("Task %d executed\n", (int) arg);
}

int main(void) {
    // Initialize the task queue semaphore
    sem_init(&task_queue_sem, 0, 0);

    // Create the task scheduler thread
    pthread_t task_scheduler_thread;
    pthread_create(&task_scheduler_thread, NULL, task_scheduler, NULL);

    // Add some tasks to the queue
    for (int i = 0; i < NUM_TASKS; i++) {
        task_t task = { .id = i, .priority = rand() % 10, .func = task_func, .arg = (void *) i };
        task_add(task);
    }

    // Join the task scheduler thread
    pthread_join(task_scheduler_thread, NULL);

    return 0;
}