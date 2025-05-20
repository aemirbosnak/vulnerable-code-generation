//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define ERR_BUFFER_SIZE 256

// Custom error handling function
void handleError(const char *msg, int errCode) {
    fprintf(stderr, "Error: %s. Code: %d\n", msg, errCode);
    exit(errCode);
}

// Function to simulate an asynchronous task
void *asynchronousTask(void *arg) {
    int threadId = *(int *)arg;
    free(arg); // Free the allocated memory for threadId

    // Simulate random task completion time
    int sleepTime = rand() % 3 + 1; // Sleep for 1 to 3 seconds
    printf("Thread %d: Starting work for %d seconds...\n", threadId, sleepTime);
    
    sleep(sleepTime);
    
    // Randomly decide if an error occurs
    if (rand() % 2 == 0) {
        handleError("Simulated random error occurred", threadId);
    }

    printf("Thread %d: Work done!\n", threadId);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        int *threadId = malloc(sizeof(int)); // Dynamic allocation for threadId
        if (threadId == NULL) {
            handleError("Failed to allocate memory for thread ID", 1);
        }
        *threadId = i + 1; // Assign thread number (1 to NUM_THREADS)

        int ret = pthread_create(&threads[i], NULL, asynchronousTask, threadId);
        if (ret != 0) {
            handleError("Failed to create thread", ret);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        int ret = pthread_join(threads[i], NULL);
        if (ret != 0) {
            handleError("Failed to join thread", ret);
        }
    }

    printf("All threads completed successfully.\n");
    return 0;
}