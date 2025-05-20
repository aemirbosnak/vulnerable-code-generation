//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg);

pthread_mutex_t lock; // declare a mutex lock

int main()
{
    pthread_t thread_1, thread_2;
    int thread_1_result, thread_2_result;
    int err;
    
    err = pthread_mutex_init(&lock, NULL); // initialize the mutex lock
    if (err) // error handling for mutex initialization
    {
        printf("Error initializing mutex lock\n");
        exit(-1);
    }
    
    // create thread 1
    err = pthread_create(&thread_1, NULL, thread_func, "Thread 1");
    if (err) // error handling for thread creation
    {
        printf("Error creating thread 1\n");
        pthread_mutex_destroy(&lock); // destroy the mutex lock
        exit(-1);
    }
    
    // create thread 2
    err = pthread_create(&thread_2, NULL, thread_func, "Thread 2");
    if (err) // error handling for thread creation
    {
        printf("Error creating thread 2\n");
        pthread_mutex_destroy(&lock); // destroy the mutex lock
        exit(-1);
    }
    
    // wait for thread 1 to finish
    err = pthread_join(thread_1, (void **)&thread_1_result);
    if (err) // error handling for thread join
    {
        printf("Error joining thread 1\n");
        pthread_mutex_destroy(&lock); // destroy the mutex lock
        exit(-1);
    }
    
    // wait for thread 2 to finish
    err = pthread_join(thread_2, (void **)&thread_2_result);
    if (err) // error handling for thread join
    {
        printf("Error joining thread 2\n");
        pthread_mutex_destroy(&lock); // destroy the mutex lock
        exit(-1);
    }
    
    pthread_mutex_destroy(&lock); // destroy the mutex lock
    
    return 0;
}

void *thread_func(void *arg)
{
    char *thread_name = (char *)arg;
    int i;
    
    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock); // lock the mutex
        
        printf("%s: %d\n", thread_name, i);
        
        pthread_mutex_unlock(&lock); // unlock the mutex
    }
    
    pthread_exit(NULL);
}