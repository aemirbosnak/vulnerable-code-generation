//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: excited
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Define a function that will be executed by each thread
void* thread_func(void* arg) {
    // Get the argument passed to the thread function
    int thread_num = *((int*) arg);
    
    // Print a message indicating the thread number
    printf("Thread %d started\n", thread_num);
    
    // Sleep for 2 seconds
    sleep(2);
    
    // Print a message indicating the thread has finished
    printf("Thread %d finished\n", thread_num);
    
    // Return NULL to indicate the thread has finished
    return NULL;
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }
    
    // Get the number of threads to create
    int num_threads = atoi(argv[1]);
    
    // Create the pthread mutex
    pthread_mutex_t mutex;
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Create a list of threads to be managed
    pthread_t threads[num_threads];
    
    // Initialize the threads to NULL
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, &i);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Clean up the mutex
    pthread_mutex_destroy(&mutex);
    
    // Exit the program
    return 0;
}