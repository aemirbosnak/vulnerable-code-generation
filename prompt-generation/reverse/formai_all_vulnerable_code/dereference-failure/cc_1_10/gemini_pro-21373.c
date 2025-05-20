//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
// A multi-threaded C program to print a pattern
// using pthreads
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The number of threads to create
#define NUM_THREADS 4

// The number of rows in the pattern
#define NUM_ROWS 10

// The number of columns in the pattern
#define NUM_COLS 10

// The character to print in the pattern
#define CHAR_TO_PRINT '*'

// The mutex to protect the shared variable
pthread_mutex_t mutex;

// The shared variable to store the current row
int current_row = 0;

// The thread function
void *thread_func(void *arg)
{
    // Get the thread ID
    int thread_id = *(int *)arg;

    // Loop until all rows have been printed
    while (current_row < NUM_ROWS)
    {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // If the current row is less than the number
        // of rows, print the pattern for this row
        if (current_row < NUM_ROWS)
        {
            for (int i = 0; i < NUM_COLS; i++)
            {
                printf("%c", CHAR_TO_PRINT);
            }
            printf("\n");
            current_row++;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, thread_func, arg);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}