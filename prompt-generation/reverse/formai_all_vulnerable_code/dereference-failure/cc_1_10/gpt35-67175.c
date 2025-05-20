//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function1(void *arg);
void *thread_function2(void *arg);
void *thread_function3(void *arg);

int main()
{
    pthread_t thread1, thread2, thread3;
    int thread1_error, thread2_error, thread3_error;

    // Create thread1
    thread1_error = pthread_create(&thread1, NULL, thread_function1, NULL);
    if (thread1_error != 0)
    {
        fprintf(stderr, "Thread1 creation failed: %s\n", strerror(thread1_error));
        exit(EXIT_FAILURE);
    }

    // Create thread2
    thread2_error = pthread_create(&thread2, NULL, thread_function2, NULL);
    if (thread2_error != 0)
    {
        fprintf(stderr, "Thread2 creation failed: %s\n", strerror(thread2_error));
        pthread_cancel(thread1);
        exit(EXIT_FAILURE);
    }

    // Create thread3
    thread3_error = pthread_create(&thread3, NULL, thread_function3, NULL);
    if (thread3_error != 0)
    {
        fprintf(stderr, "Thread3 creation failed: %s\n", strerror(thread3_error));
        pthread_cancel(thread1);
        pthread_cancel(thread2);
        exit(EXIT_FAILURE);
    }

    // Wait for threads to complete
    if (pthread_join(thread1, NULL) != 0)
    {
        fprintf(stderr, "Thread1 join failed: %s\n", strerror(thread1_error));
        pthread_cancel(thread2);
        pthread_cancel(thread3);
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        fprintf(stderr, "Thread2 join failed: %s\n", strerror(thread2_error));
        pthread_cancel(thread3);
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread3, NULL) != 0)
    {
        fprintf(stderr, "Thread3 join failed: %s\n", strerror(thread3_error));
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *thread_function1(void *arg)
{
    printf("Thread1 is running...\n");
    return NULL;
}

void *thread_function2(void *arg)
{
    printf("Thread2 is running...\n");
    // Intentionally force a segmentation fault
    int *p = NULL;
    *p = 10;

    return NULL;
}

void *thread_function3(void *arg)
{
    printf("Thread3 is running...\n");
    // Intentionally cause a divide by zero error
    int x = 5, y = 0;
    int z = x / y;

    return NULL;
}