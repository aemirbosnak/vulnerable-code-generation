//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Define the task structure
typedef struct task {
    void (*func)(void *);
    void *arg;
} task_t;

// Define the task queue
static task_t *task_queue = NULL;
static int task_queue_size = 0;
static int task_queue_head = 0;
static int task_queue_tail = 0;

// Define the task scheduler thread
static pthread_t task_scheduler_thread;

// Define the task scheduler thread condition variable
static pthread_cond_t task_scheduler_cond = PTHREAD_COND_INITIALIZER;

// Define the task scheduler thread mutex
static pthread_mutex_t task_scheduler_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the signal handler
static void signal_handler(int signum) {
    // Check if the signal is SIGINT
    if (signum == SIGINT) {
        // Signal the task scheduler thread to stop
        pthread_cond_signal(&task_scheduler_cond);
    }
}

// Define the task scheduler thread function
static void *task_scheduler_thread_func(void *arg) {
    // Loop forever
    while (1) {
        // Lock the task scheduler mutex
        pthread_mutex_lock(&task_scheduler_mutex);

        // Wait for a task to be added to the queue
        while (task_queue_size == 0) {
            pthread_cond_wait(&task_scheduler_cond, &task_scheduler_mutex);
        }

        // Get the next task from the queue
        task_t task = task_queue[task_queue_head];

        // Increment the task queue head
        task_queue_head = (task_queue_head + 1) % task_queue_size;

        // Decrease the task queue size
        task_queue_size--;

        // Unlock the task scheduler mutex
        pthread_mutex_unlock(&task_scheduler_mutex);

        // Execute the task
        task.func(task.arg);
    }

    return NULL;
}

// Initialize the task scheduler
static void task_scheduler_init() {
    // Create the task scheduler thread
    pthread_create(&task_scheduler_thread, NULL, task_scheduler_thread_func, NULL);

    // Register the signal handler
    signal(SIGINT, signal_handler);
}

// Add a task to the queue
static void task_scheduler_add(void (*func)(void *), void *arg) {
    // Lock the task scheduler mutex
    pthread_mutex_lock(&task_scheduler_mutex);

    // Reallocate the task queue if necessary
    if (task_queue_size == task_queue_head) {
        task_queue = realloc(task_queue, (task_queue_size + 1) * sizeof(task_t));
        task_queue_tail = task_queue_size;
        task_queue_size++;
    }

    // Add the task to the queue
    task_queue[task_queue_tail] = (task_t){.func = func, .arg = arg};

    // Increment the task queue tail
    task_queue_tail = (task_queue_tail + 1) % task_queue_size;

    // Signal the task scheduler thread
    pthread_cond_signal(&task_scheduler_cond);

    // Unlock the task scheduler mutex
    pthread_mutex_unlock(&task_scheduler_mutex);
}

// Main function
int main() {
    // Initialize the task scheduler
    task_scheduler_init();

    // Add some tasks to the queue
    task_scheduler_add(printf, "Hello, world!\n");
    task_scheduler_add(printf, "Goodbye, world!\n");

    // Join the task scheduler thread
    pthread_join(task_scheduler_thread, NULL);

    return 0;
}