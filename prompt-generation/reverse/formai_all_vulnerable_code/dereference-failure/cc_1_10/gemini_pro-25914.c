//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

// Mutex to protect shared data
pthread_mutex_t mutex;

// Shared data variable
int shared_variable = 0;

// Thread function
void *thread_function(void *arg) {
    // Get the thread number
    int thread_num = *(int *)arg;

    // Acquire the mutex lock
    pthread_mutex_lock(&mutex);

    // Increment the shared variable
    shared_variable += thread_num;

    // Release the mutex lock
    pthread_mutex_unlock(&mutex);

    // Print the thread number and shared variable value
    printf("Thread %d: Shared variable = %d\n", thread_num, shared_variable);

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create an array of thread IDs
    pthread_t thread_ids[NUM_THREADS];

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&thread_ids[i], NULL, thread_function, (void *)thread_num);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the final value of the shared variable
    printf("Final value of shared variable: %d\n", shared_variable);

    return 0;
}