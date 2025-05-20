//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg);

int main(int argc, char **argv) 
{
    pthread_t threads[NUM_THREADS];
    int rc, i;
    int *thread_id;
    /* create all threads */
    for (i = 0; i < NUM_THREADS; i++) 
    {
        thread_id = malloc(sizeof(int));
        *thread_id = i+1;
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)thread_id);
        if (rc) 
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* wait for all threads to complete */
    for (i = 0; i < NUM_THREADS; i++) 
    {
        rc = pthread_join(threads[i], NULL);
        if (rc) 
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }
    printf("All threads completed successfully.\n");
    pthread_exit(NULL);
}

void *thread_function(void *arg) 
{
    int thread_id = *(int *)arg;

    printf("Thread %d started.\n", thread_id);

    /* Do some useful task here... */
    // ...
    // ...
    printf("Thread %d completed.\n", thread_id);

    pthread_exit(NULL);
}