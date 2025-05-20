//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a thread function
void *thread_function(void *arg) {
    // Get the thread ID
    int thread_id = *((int *)arg);

    // Print the thread ID
    printf("Thread %d started\n", thread_id);

    // Sleep for a random amount of time
    sleep(rand() % 5);

    // Print the thread ID again
    printf("Thread %d finished\n", thread_id);

    // Return the thread ID
    return (void *)thread_id;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }

    // Get the number of threads
    int num_threads = atoi(argv[1]);

    // Create an array of thread IDs
    int thread_ids[num_threads];

    // Create an array of threads
    pthread_t threads[num_threads];

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the thread IDs
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d returned %d\n", thread_ids[i], thread_ids[i]);
    }

    return 0;
}