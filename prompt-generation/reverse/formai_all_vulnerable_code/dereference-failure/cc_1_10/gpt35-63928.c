//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* thread_function(void* arg)
{
    // Prevent other threads from accessing the shared resource
    pthread_mutex_lock(&lock);
    
    int* num_ptr = (int*) arg;
    int num = *num_ptr;
    printf("Thread %d is running\n", num);
    // Sleep for few seconds
    sleep(2);

    printf("Thread %d is done\n", num);

    // Release the lock so other threads can access the shared resource
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[5];

    // Initialize the mutex lock
    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed\n");
        return 1;
    }

    int i;
    for(i = 0; i < 5; i++)
    {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        // Create new threads
        if(pthread_create(&threads[i], NULL, thread_function, (void*) thread_num) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    for(i = 0; i < 5; i++)
    {
        // Wait for all threads to finish
        if(pthread_join(threads[i], NULL) != 0)
        {
            printf("Thread join failed\n");
            return 1;
        }
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    printf("All threads have completed their execution\n");
    return 0;
}