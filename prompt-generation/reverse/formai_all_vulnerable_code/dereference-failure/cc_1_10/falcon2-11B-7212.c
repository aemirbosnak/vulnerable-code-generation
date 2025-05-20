//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A simple function that performs a long computation
void* do_work(void* args)
{
    int thread_id = *(int*)args;
    printf("Thread %d started\n", thread_id);
    
    // Do some work
    for(int i=0; i<1000000; i++)
    {
        int sum = 0;
        for(int j=0; j<1000000; j++)
        {
            sum += i + j;
        }
        printf("Thread %d: Sum is %d\n", thread_id, sum);
    }
    
    printf("Thread %d finished\n", thread_id);
    return NULL;
}

// A function that creates and starts a new thread
void* start_thread(void* args)
{
    int thread_id = *(int*)args;
    pthread_t thread;
    pthread_create(&thread, NULL, do_work, &thread_id);
    return NULL;
}

// The main function
int main(int argc, char** argv)
{
    // Create and start 10 threads
    pthread_t threads[10];
    int thread_ids[10];
    for(int i=0; i<10; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, start_thread, &thread_ids[i]);
    }
    
    // Wait for all threads to finish
    for(int i=0; i<10; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}