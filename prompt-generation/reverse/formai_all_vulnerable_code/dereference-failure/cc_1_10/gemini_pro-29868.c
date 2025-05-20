//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Define the task structure
typedef struct task {
    int id;                 // Task ID
    int priority;           // Task priority
    void (*func)(void *);   // Task function
    void *arg;              // Task argument
} task_t;

// Define the task queue
static task_t *task_queue = NULL;
static int task_queue_size = 0;

// Define the task scheduler thread
static pthread_t task_scheduler_thread;

// Define the task scheduler mutex
static pthread_mutex_t task_scheduler_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the task scheduler condition variable
static pthread_cond_t task_scheduler_cond = PTHREAD_COND_INITIALIZER;

// Function to compare two tasks by priority
static int compare_tasks(const void *a, const void *b) {
    const task_t *ta = (const task_t *)a;
    const task_t *tb = (const task_t *)b;

    return tb->priority - ta->priority;
}

// Function to add a task to the task queue
static void add_task(task_t *task) {
    // Lock the task scheduler mutex
    pthread_mutex_lock(&task_scheduler_mutex);

    // Add the task to the task queue
    task_queue = realloc(task_queue, (task_queue_size + 1) * sizeof(task_t));
    task_queue[task_queue_size++] = *task;

    // Sort the task queue by priority
    qsort(task_queue, task_queue_size, sizeof(task_t), compare_tasks);

    // Unlock the task scheduler mutex
    pthread_mutex_unlock(&task_scheduler_mutex);

    // Signal the task scheduler condition variable
    pthread_cond_signal(&task_scheduler_cond);
}

// Function to remove a task from the task queue
static task_t *remove_task() {
    // Lock the task scheduler mutex
    pthread_mutex_lock(&task_scheduler_mutex);

    // Remove the task from the task queue
    task_t *task = NULL;
    if (task_queue_size > 0) {
        task = &task_queue[0];
        task_queue_size--;
        task_queue = realloc(task_queue, task_queue_size * sizeof(task_t));
    }

    // Unlock the task scheduler mutex
    pthread_mutex_unlock(&task_scheduler_mutex);

    return task;
}

// Function to execute a task
static void execute_task(task_t *task) {
    // Call the task function
    task->func(task->arg);

    // Free the task
    free(task);
}

// Function to run the task scheduler
static void *task_scheduler(void *arg) {
    while (1) {
        // Lock the task scheduler mutex
        pthread_mutex_lock(&task_scheduler_mutex);

        // Wait for a task to be added to the task queue
        while (task_queue_size == 0) {
            pthread_cond_wait(&task_scheduler_cond, &task_scheduler_mutex);
        }

        // Remove the task from the task queue
        task_t *task = remove_task();

        // Unlock the task scheduler mutex
        pthread_mutex_unlock(&task_scheduler_mutex);

        // Execute the task
        execute_task(task);
    }

    return NULL;
}

// Function to create a task
task_t *create_task(void (*func)(void *), void *arg, int priority) {
    // Allocate memory for the task
    task_t *task = malloc(sizeof(task_t));

    // Initialize the task
    task->id = rand();
    task->priority = priority;
    task->func = func;
    task->arg = arg;

    return task;
}

// Function to destroy a task
void destroy_task(task_t *task) {
    // Free the task
    free(task);
}

// Function to start the task scheduler
void start_task_scheduler() {
    // Create the task scheduler thread
    pthread_create(&task_scheduler_thread, NULL, task_scheduler, NULL);
}

// Function to stop the task scheduler
void stop_task_scheduler() {
    // Cancel the task scheduler thread
    pthread_cancel(task_scheduler_thread);

    // Join the task scheduler thread
    pthread_join(task_scheduler_thread, NULL);
}

// Example task function
void task_function(void *arg) {
    printf("Task %d executed\n", (int)arg);
}

// Example program
int main() {
    // Start the task scheduler
    start_task_scheduler();

    // Create some tasks
    task_t *task1 = create_task(task_function, (void *)1, 1);
    task_t *task2 = create_task(task_function, (void *)2, 2);
    task_t *task3 = create_task(task_function, (void *)3, 3);

    // Add the tasks to the task queue
    add_task(task1);
    add_task(task2);
    add_task(task3);

    // Wait for the tasks to complete
    while (task_queue_size > 0) {
        sleep(1);
    }

    // Stop the task scheduler
    stop_task_scheduler();

    return 0;
}