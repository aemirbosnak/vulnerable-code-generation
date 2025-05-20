//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

pthread_mutex_t mutex1;
int count =0;

void *threadFunc(void* arg)
{
    int* id = (int*) arg;
    int localCount = 0;

    pthread_mutex_lock(&mutex1);

    while(count<10) //Perform task for 10 iterations
    {
        count++;
        localCount++;
        printf("Thread %d incremented count to %d\n", *id, count);
    }

    pthread_mutex_unlock(&mutex1);

    printf("Thread %d performed %d iterations\n", *id, localCount);

    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t threads[MAX_THREADS];

    int i;

    if (pthread_mutex_init(&mutex1, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    int* threadIds = (int*) malloc(sizeof(int) * MAX_THREADS);

    for (i=0; i<MAX_THREADS; i++)
    {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, &threadIds[i]);
    }

    for (i=0; i<MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex1);

    printf("Final count is %d\n", count);

    return 0;
}