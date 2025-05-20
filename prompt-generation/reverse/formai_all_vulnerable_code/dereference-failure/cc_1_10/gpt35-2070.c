//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a global mutex variable
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Define a global boolean variable to check the status of the thread
bool are_threads_done = false;

// Define the function to be run inside the thread
void* thread_function(void* arg)
{
    // Lock the mutex before starting the thread
    pthread_mutex_lock(&mtx);

    // Check if other threads are done and set the boolean variable accordingly
    if (!are_threads_done)
    {
        are_threads_done = true;
    }

    // Unlock the mutex before ending the thread
    pthread_mutex_unlock(&mtx);

    return NULL;
}

int main()
{
    // Define the number of threads to be created
    int num_threads = 10;

    // Create an array of thread IDs
    pthread_t* thread_ids = malloc(num_threads * sizeof(pthread_t));

    // Create the threads
    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&thread_ids[i], NULL, thread_function, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }

    // Check if all the threads are done
    if (are_threads_done)
    {
        printf("All threads are done. Paranoid mode activated!\n");
    }
    else
    {
        printf("Something went wrong. Threads are not done!\n");
    }

    // Cleanup
    free(thread_ids);
    pthread_mutex_destroy(&mtx);

    return 0;
}