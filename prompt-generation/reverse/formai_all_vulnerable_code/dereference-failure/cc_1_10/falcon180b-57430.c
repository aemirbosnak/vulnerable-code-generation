//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data;

// Define the thread function prototype
void *thread_func(void *arg);

// Define the thread array
thread_data threads[MAX_THREADS];

// Define the number of threads
int num_threads = 0;

// Define the mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a new thread
void create_thread(int id, void *(*func)(void *), void *arg) {
    if (num_threads >= MAX_THREADS) {
        printf("Error: Maximum number of threads reached.\n");
        return;
    }

    threads[num_threads].id = id;
    threads[num_threads].func = func;
    threads[num_threads].arg = arg;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, &threads[num_threads]);

    num_threads++;
}

// Function to wait for all threads to finish
void wait_for_threads() {
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i].id, NULL);
    }
}

// Thread function
void *thread_func(void *arg) {
    thread_data *thread_data = arg;

    pthread_mutex_lock(&mutex);
    printf("Thread %d started.\n", thread_data->id);
    pthread_mutex_unlock(&mutex);

    void *result = thread_data->func(thread_data->arg);

    pthread_mutex_lock(&mutex);
    printf("Thread %d finished with result: %p.\n", thread_data->id, result);
    pthread_mutex_unlock(&mutex);

    return result;
}

// Main function
int main() {
    create_thread(1, thread_func, NULL);
    create_thread(2, thread_func, NULL);
    create_thread(3, thread_func, NULL);

    wait_for_threads();

    return 0;
}