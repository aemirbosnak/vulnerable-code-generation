//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
This program demonstrates a dynamic threading library implementation in C.
The program creates a pool of worker threads and assigns them tasks to execute.
The tasks are created dynamically and the number of threads in the pool is determined at runtime.
*/

// A task struct that holds the task function and its arguments
typedef struct Task {
    void (*func)(void*);
    void* arg;
} Task;

// A queue struct that holds the task queue and its synchronization primitives
typedef struct Queue {
    Task* tasks;
    int size;
    int in;
    int out;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} Queue;

// A worker function that pulls tasks from the task queue and executes them
void* worker(void* arg) {
    Queue* queue = (Queue*)arg;

    while (1) {
        pthread_mutex_lock(&queue->lock);

        // Wait for a task to be added to the queue
        while (queue->size == 0) {
            pthread_cond_wait(&queue->not_empty, &queue->lock);
        }

        // Get the next task from the queue
        Task task = queue->tasks[queue->out];
        queue->out = (queue->out + 1) % queue->size;
        queue->size--;

        // Signal that the queue is not full
        pthread_cond_signal(&queue->not_full);

        // Execute the task and free its arguments
        (*task.func)(task.arg);
        free(task.arg);

        pthread_mutex_unlock(&queue->lock);
    }
}

// A function to add a task to the task queue
void add_task(Queue* queue, void (*func)(void*), void* arg) {
    pthread_mutex_lock(&queue->lock);

    // Wait for space to become available in the queue
    while (queue->size == queue->in) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }

    // Add the task to the queue
    Task task;
    task.func = func;
    task.arg = arg;
    queue->tasks[queue->in] = task;
    queue->in = (queue->in + 1) % queue->size;
    queue->size++;

    // Signal that the queue is not empty
    pthread_cond_signal(&queue->not_empty);

    pthread_mutex_unlock(&queue->lock);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <num_threads> <num_tasks>\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    int num_threads = atoi(argv[1]);
    int num_tasks = atoi(argv[2]);

    // Initialize the task queue
    Queue queue;
    queue.tasks = (Task*)malloc(num_tasks * sizeof(Task));
    queue.size = 0;
    queue.in = 0;
    queue.out = 0;
    pthread_mutex_init(&queue.lock, NULL);
    pthread_cond_init(&queue.not_empty, NULL);
    pthread_cond_init(&queue.not_full, NULL);

    // Create the worker threads
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, worker, (void*)&queue);
    }

    // Add tasks to the task queue
    for (int i = 0; i < num_tasks; i++) {
        int* arg = (int*)malloc(sizeof(int));
        *arg = i;
        add_task(&queue, (void (*)(void*))&printf, (void*)arg);
    }

    // Wait for the worker threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up resources
    free(queue.tasks);
    free(threads);
    pthread_mutex_destroy(&queue.lock);
    pthread_cond_destroy(&queue.not_empty);
    pthread_cond_destroy(&queue.not_full);

    return 0;
}