//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Define the number of threads
#define MAX_THREADS 5

// Structure to store thread data (customizable)
typedef struct {
    int thread_id;  // Unique thread identifier
    int sleep_time; // Time the thread sleeps
} thread_data_t;

// Function for the thread to execute
void* thread_function(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    printf("Thread %d: Started\n", data->thread_id);
    
    // Simulating some processing time
    sleep(data->sleep_time);
    
    printf("Thread %d: Finished after %d seconds\n", data->thread_id, data->sleep_time);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // Handling configurable sleep times for threads through command line arguments
    int sleep_times[MAX_THREADS] = {1, 2, 3, 4, 5}; // Default sleep times
    int num_threads = MAX_THREADS;

    if (argc > 1) {
        num_threads = argc - 1; // Number of threads based on command line input
        if (num_threads > MAX_THREADS) num_threads = MAX_THREADS;

        // Parse command line arguments as sleep times
        for (int i = 0; i < num_threads; i++) {
            sleep_times[i] = atoi(argv[i + 1]);
        }
    }

    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];

    // Creating threads based on sleep times
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].sleep_time = sleep_times[i];
        
        int rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_data[i]);
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread %d, %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Joining threads to ensure they complete their execution
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed successfully.\n");
    return 0;
}