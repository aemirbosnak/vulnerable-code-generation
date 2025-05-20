//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: statistical
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4

void* thread_function(void* arg) {
    // Each thread should print its own ID
    int thread_id = *((int*) arg);
    printf("Thread %d started\n", thread_id);

    // Sleep for 1 second
    sleep(1);

    // Each thread should print its own ID again
    printf("Thread %d finished\n", thread_id);

    // Return NULL to indicate the end of the thread
    return NULL;
}

int main() {
    // Create an array to store thread IDs
    int thread_ids[MAX_THREADS];

    // Initialize thread IDs to -1 (indicating that they haven't been created yet)
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = -1;
    }

    // Create a new thread for each thread ID
    for (int i = 0; i < MAX_THREADS; i++) {
        if (thread_ids[i] == -1) {
            // Create a new thread and set its ID to i
            pthread_t thread;
            int result = pthread_create(&thread, NULL, thread_function, &i);
            if (result!= 0) {
                printf("Error creating thread: %s\n", strerror(result));
                return 1;
            }

            // Update the thread ID array
            thread_ids[i] = i;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // Print the number of threads that finished successfully
    int num_threads = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        if (thread_ids[i]!= -1) {
            num_threads++;
        }
    }
    printf("Number of threads that finished: %d\n", num_threads);

    // Destroy the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        if (thread_ids[i]!= -1) {
            pthread_detach(thread_ids[i]);
            thread_ids[i] = -1;
        }
    }

    return 0;
}