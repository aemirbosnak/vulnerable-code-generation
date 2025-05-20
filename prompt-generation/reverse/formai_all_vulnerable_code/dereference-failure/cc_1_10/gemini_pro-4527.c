//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

// Task structure
typedef struct task {
    void (*func)(void*); // Function to execute
    void* arg; // Argument to pass to the function
    time_t run_time; // Time to run the task
} task_t;

// Task queue
static task_t* task_queue = NULL;
static int task_queue_size = 0;
static int task_queue_capacity = 0;

// Task scheduler thread
static pthread_t scheduler_thread;
static int scheduler_running = 1;

// Mutex and condition variable for task synchronization
static pthread_mutex_t task_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t task_cond = PTHREAD_COND_INITIALIZER;

// Function to add a task to the queue
void add_task(void (*func)(void*), void* arg, time_t run_time) {
    // Reallocate the task queue if necessary
    if (task_queue_size >= task_queue_capacity) {
        task_queue_capacity *= 2;
        task_queue = realloc(task_queue, task_queue_capacity * sizeof(task_t));
    }

    // Add the task to the queue
    task_queue[task_queue_size].func = func;
    task_queue[task_queue_size].arg = arg;
    task_queue[task_queue_size].run_time = run_time;
    task_queue_size++;
}

// Function to run the task scheduler
void* scheduler_thread_func(void* arg) {
    while (scheduler_running) {
        // Acquire the task mutex
        pthread_mutex_lock(&task_mutex);

        // Wait for a task to be available
        while (task_queue_size == 0) {
            pthread_cond_wait(&task_cond, &task_mutex);
        }

        // Get the next task to run
        task_t task = task_queue[0];

        // Remove the task from the queue
        for (int i = 0; i < task_queue_size - 1; i++) {
            task_queue[i] = task_queue[i + 1];
        }
        task_queue_size--;

        // Release the task mutex
        pthread_mutex_unlock(&task_mutex);

        // Run the task
        task.func(task.arg);
    }

    return NULL;
}

// Function to start the task scheduler
void start_scheduler() {
    // Create the scheduler thread
    pthread_create(&scheduler_thread, NULL, scheduler_thread_func, NULL);
}

// Function to stop the task scheduler
void stop_scheduler() {
    // Set the scheduler running flag to false
    scheduler_running = 0;

    // Signal the scheduler thread to wake up
    pthread_cond_signal(&task_cond);

    // Join the scheduler thread
    pthread_join(scheduler_thread, NULL);
}

// Example task function
void task_func(void* arg) {
    printf("Task %d running\n", (int)arg);
    sleep(1);
}

// Main function
int main() {
    // Start the task scheduler
    start_scheduler();

    // Add some tasks to the queue
    for (int i = 0; i < 10; i++) {
        add_task(task_func, (void*)i, time(NULL) + i);
    }

    // Wait for the tasks to finish
    sleep(10);

    // Stop the task scheduler
    stop_scheduler();

    return 0;
}