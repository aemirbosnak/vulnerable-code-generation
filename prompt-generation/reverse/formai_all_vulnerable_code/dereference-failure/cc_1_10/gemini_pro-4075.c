//GEMINI-pro DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables
int shared_variable = 0;
pthread_mutex_t lock;

// Thread function
void* thread_function(void* arg) {
    // Get the thread number
    int thread_num = *(int*)arg;

    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Increment the shared variable
    shared_variable++;

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Print the thread number and the shared variable
    printf("Thread %d: shared_variable = %d\n", thread_num, shared_variable);

    return NULL;
}

int main() {
    // Initialize the lock
    pthread_mutex_init(&lock, NULL);

    // Create the threads
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, thread_function, thread_num);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the lock
    pthread_mutex_destroy(&lock);

    return 0;
}