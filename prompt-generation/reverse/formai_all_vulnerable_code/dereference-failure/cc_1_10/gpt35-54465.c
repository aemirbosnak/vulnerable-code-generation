//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 4
#define N_TASKS 20

// Define a task struct
typedef struct {
    int id;
    int duration;
} Task;

// Define a thread pool struct
typedef struct {
    Task **tasks; // Array of pointers to tasks
    int n_tasks; // Number of tasks in the array
    int head; // Index of next task to be executed
    pthread_mutex_t mutex; // Mutex for accessing the task array
    pthread_cond_t cond; // Condition variable for signaling new task
} ThreadPool;

// Allocate memory for a new task with the given id and duration
Task* new_task(int id, int duration) {
    Task *task = malloc(sizeof(Task));
    if (task == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    task->id = id;
    task->duration = duration;
    return task;
}

// Free memory for a task
void free_task(Task *task) {
    free(task);
}

// Thread function for executing tasks
void* execute_task(void *arg) {
    ThreadPool *pool = (ThreadPool *) arg;
    Task *task;
    while (1) {
        pthread_mutex_lock(&pool->mutex);
        while (pool->head >= pool->n_tasks) {
            pthread_cond_wait(&pool->cond, &pool->mutex);
        }
        task = pool->tasks[pool->head++];
        pthread_mutex_unlock(&pool->mutex);
        if (task == NULL) {
            break; // NULL task signals end of execution
        }
        printf("Task %d started\n", task->id);
        sleep(task->duration);
        printf("Task %d finished\n", task->id);
        free_task(task);
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    Task *task;
    pthread_t threads[N_THREADS];
    ThreadPool pool = {
        .tasks = malloc(N_TASKS * sizeof(Task *)),
        .n_tasks = N_TASKS,
        .head = 0,
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .cond = PTHREAD_COND_INITIALIZER
    };
    if (pool.tasks == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    // Add tasks to the task array
    for (i = 0; i < N_TASKS; i++) {
        pool.tasks[i] = new_task(i, rand() % 5 + 1); // Duration is 1-5 seconds
    }
    // Add NULL tasks to signal end of execution
    for (i = 0; i < N_THREADS; i++) {
        pool.tasks[N_TASKS + i] = NULL;
    }
    // Create threads
    for (i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, execute_task, &pool);
    }
    // Wait for threads to finish
    for (i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Free memory for the task array
    for (i = 0; i < N_TASKS; i++) {
        free_task(pool.tasks[i]);
    }
    free(pool.tasks);
    return 0;
}