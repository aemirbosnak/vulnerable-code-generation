//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure to pass multiple variables to the thread function
struct thread_args {
    int id;
    int delay;
};

// Function that each thread will execute
void* thread_func(void* args) {
    struct thread_args* my_args = (struct thread_args*) args;
    
    printf("Thread %d started with delay %d\n", my_args->id, my_args->delay);
    
    // Do some work based on the delay time
    for (int i = 1; i <= my_args->delay; i++) {
        printf("Thread %d working...\n", my_args->id);
    }
    
    printf("Thread %d finished\n", my_args->id);
    free(my_args);  // Free the memory allocated for the argument structure
    pthread_exit(NULL);  // Terminate the thread
}

int main() {
    pthread_t threads[5];  // Create an array of threads
    int rc;
    
    // Create 5 threads with different delays
    for (int i = 0; i < 5; i++) {
        struct thread_args* args = (struct thread_args*) malloc(sizeof(struct thread_args));
        args->id = i;
        args->delay = (i+1) * 2;
        
        rc = pthread_create(&threads[i], NULL, thread_func, (void*)args);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads finished\n");
    return 0;
}