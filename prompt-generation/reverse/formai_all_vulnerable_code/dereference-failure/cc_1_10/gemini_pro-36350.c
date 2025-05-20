//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Thread function */
void *thread_func(void *arg)
{
    int *num = (int *)arg;
    printf("Thread %d created\n", *num);

    /* Sleep for some time */
    sleep(2);

    printf("Thread %d exiting\n", *num);

    return NULL;
}

int main()
{
    /* Initialize number of threads */
    int num_threads = 5;

    /* Create threads */
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++)
    {
        int *num = malloc(sizeof(int));
        *num = i;
        if (pthread_create(&threads[i], NULL, thread_func, (void *)num) != 0)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    /* Join threads */
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    /* Destroy threads */
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_detach(threads[i]) != 0)
        {
            perror("pthread_detach");
            exit(EXIT_FAILURE);
        }
    }

    printf("Main thread exiting\n");

    return 0;
}