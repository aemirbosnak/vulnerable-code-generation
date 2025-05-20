//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Each thread will execute this function
void* thread_function(void* arg)
{
    // Get the thread ID
    int tid = (int)arg;

    // Print a message from the thread
    printf("Hello from thread %d!\n", tid);

    // Sleep for a random amount of time
    sleep(rand() % 5);

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char** argv)
{
    // Check if the user specified the number of threads
    if (argc < 2)
    {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of threads
    int num_threads = atoi(argv[1]);

    // Create an array of thread IDs
    pthread_t* thread_ids = malloc(sizeof(pthread_t) * num_threads);

    // Create the threads
    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&thread_ids[i], NULL, thread_function, (void*)i);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }

    // Free the thread IDs
    free(thread_ids);

    // Exit the program
    return EXIT_SUCCESS;
}