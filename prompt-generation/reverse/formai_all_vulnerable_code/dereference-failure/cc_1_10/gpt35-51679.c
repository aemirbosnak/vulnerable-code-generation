//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 //Number of threads to be created

pthread_mutex_t mutex_thread; //Mutex for thread synchronization

void* thread_function(void* arg)
{
    int thread_id = *(int*) arg;
    
    pthread_mutex_lock(&mutex_thread);
    printf("Thread %d entered the critical section\n", thread_id);
    sleep(1); //Simulating some task
    printf("Thread %d exiting the critical section\n", thread_id);
    pthread_mutex_unlock(&mutex_thread);
    
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_init(&mutex_thread, NULL); //Initializing the mutex
    
    pthread_t threads[NUM_THREADS];
    
    for(int i=0; i<NUM_THREADS; i++)
    {
        int* thread_id = (int*) malloc(sizeof (int));
        *thread_id = i;
        if(pthread_create(&threads[i], NULL, thread_function, thread_id)) //Creating the threads
        {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }
    
    for(int i=0; i<NUM_THREADS; i++)
    {
        if(pthread_join(threads[i], NULL)) //Joining the threads
        {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }
    
    pthread_mutex_destroy(&mutex_thread); //Destroying the mutex
    
    return 0;
}