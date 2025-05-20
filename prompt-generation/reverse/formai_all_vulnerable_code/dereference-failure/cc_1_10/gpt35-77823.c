//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define a structure to hold thread argument data
struct ThreadArgs {
    int threadId;
    int iterations;
};

// Define the thread function
void *myThreadFunc(void *threadArgs) {
    struct ThreadArgs *args = (struct ThreadArgs *) threadArgs;
    int threadId = args->threadId;
    int iterations = args->iterations;
    
    // Output a message indicating that the thread has started
    printf("Thread %d starting...\n", threadId);
    
    // Loop for the specified number of iterations
    for (int i = 0; i < iterations; i++) {
        printf("Thread %d iteration %d\n", threadId, i);
        sleep(1); // Sleep for 1 second to simulate work
    }
    
    // Output a message indicating that the thread has finished
    printf("Thread %d finishing...\n", threadId);
    
    // Free the thread argument memory
    free(args);
    
    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Initialize the threading variables
    pthread_t threads[3];
    struct ThreadArgs *args;
    
    // Create and start three threads
    for (int i = 0; i < 3; i++) {
        // Allocate memory for the thread argument data
        args = (struct ThreadArgs *) malloc(sizeof(struct ThreadArgs));
        args->threadId = i;
        args->iterations = i+1;
        
        // Create the thread and pass it the argument data
        int result = pthread_create(&threads[i], NULL, myThreadFunc, (void *) args);
        
        // Check if the thread creation was successful
        if (result) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
        
        printf("Started thread %d with %d iterations\n", i, i+1);
    }
    
    // Wait for the threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Output a message indicating that all threads have finished
    printf("All threads have finished.\n");
    
    return 0;
}