//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10
#define NUM_TASKS 100

typedef struct task {
    int id;
    int arrival_time;
    int burst_time;
} task_t;

typedef struct thread_args {
    int thread_id;
    task_t *tasks;
    int num_tasks;
} thread_args_t;

// Global variables
task_t tasks[NUM_TASKS];
int task_idx = 0;
pthread_mutex_t task_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t task_cond = PTHREAD_COND_INITIALIZER;

// Thread function
void *thread_func(void *args) {
    thread_args_t *t_args = (thread_args_t *)args;

    while (1) {
        // Acquire the lock
        pthread_mutex_lock(&task_lock);

        // Wait for a task to become available
        while (task_idx == 0) {
            pthread_cond_wait(&task_cond, &task_lock);
        }

        // Get the next task
        task_t task = tasks[task_idx];
        task_idx--;

        // Release the lock
        pthread_mutex_unlock(&task_lock);

        // Execute the task
        printf("Thread %d: Executing task %d\n", t_args->thread_id, task.id);
        sleep(task.burst_time);
    }

    return NULL;
}

// Main function
int main() {
    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args_t *t_args = malloc(sizeof(thread_args_t));
        t_args->thread_id = i;
        t_args->tasks = tasks;
        t_args->num_tasks = NUM_TASKS;
        pthread_create(&threads[i], NULL, thread_func, (void *)t_args);
    }

    // Generate the tasks
    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].arrival_time = rand() % 10;
        tasks[i].burst_time = rand() % 10;
    }

    // Start the tasks
    pthread_mutex_lock(&task_lock);
    task_idx = NUM_TASKS;
    pthread_cond_broadcast(&task_cond);
    pthread_mutex_unlock(&task_lock);

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}