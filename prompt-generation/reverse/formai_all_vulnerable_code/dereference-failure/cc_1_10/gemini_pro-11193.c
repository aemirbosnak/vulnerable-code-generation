//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A simple thread function
void *thread_function(void *arg)
{
    // Cast the argument to an int pointer
    int *num = (int *)arg;

    // Print the number
    printf("Thread %d: %d\n", pthread_self(), *num);

    // Return NULL to indicate success
    return NULL;
}

int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number of threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of threads from the command line
    int num_threads = atoi(argv[1]);

    // Create an array of thread IDs
    pthread_t threads[num_threads];

    // Create an array of numbers to pass to the threads
    int numbers[num_threads];

    // Initialize the numbers array
    for (int i = 0; i < num_threads; i++)
    {
        numbers[i] = i;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++)
    {
        // Create a thread and pass it the number to print
        if (pthread_create(&threads[i], NULL, thread_function, &numbers[i]) != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            fprintf(stderr, "Error waiting for thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Print a newline to the console
    printf("\n");

    // Exit the program
    return EXIT_SUCCESS;
}