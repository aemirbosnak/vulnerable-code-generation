//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: surprised
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to hold the thread ID and a variable to hold the number of threads
typedef struct thread_info
{
    int thread_id;
    int num_threads;
} thread_info_t;

// A function to print the thread ID and the number of threads
void *thread_function(void *param)
{
    // Get the thread ID and the number of threads
    thread_info_t *info = (thread_info_t *)param;
    printf("Thread %d: Number of threads = %d\n", info->thread_id, info->num_threads);

    // Sleep for 1 second
    sleep(1);

    return NULL;
}

// A function to create and start multiple threads
void *create_threads(void *param)
{
    // Get the number of threads
    int num_threads = *(int *)param;

    // Create multiple threads
    for (int i = 0; i < num_threads; i++)
    {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, (void *)&i);
    }

    return NULL;
}

// A function to wait for all threads to finish
void *join_threads(void *param)
{
    // Get the number of threads
    int num_threads = *(int *)param;

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(i, NULL);
    }

    return NULL;
}

// The main function
int main(int argc, char *argv[])
{
    // Get the number of threads
    int num_threads = atoi(argv[1]);

    // Create multiple threads
    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    for (int i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, create_threads, (void *)&thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}