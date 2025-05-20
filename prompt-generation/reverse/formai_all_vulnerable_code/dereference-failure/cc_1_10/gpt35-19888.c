//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 1000000000

double sum = 0;
double *arr;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *sum_array(void *arg)
{
    int thread_no = *(int *)arg;

    double partial_sum = 0;

    for (int i = thread_no; i < SIZE; i += 4)
    {
        partial_sum += *(arr + i);
    }

    pthread_mutex_lock(&mutex);
    sum += partial_sum;
    pthread_mutex_unlock(&mutex);

    pthread_cond_signal(&cond);

    return NULL;
}

int main()
{
    arr = (double *)malloc(sizeof(double) * SIZE);

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        *(arr + i) = rand();
    }

    pthread_t threads[4];
    int thread_nos[4] = {0, 1, 2, 3};

    clock_t begin = clock();

    for (int i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, sum_array, (void *)&thread_nos[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_cond_wait(&cond, &mutex);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Sum = %lf\n", sum);
    printf("Time taken = %lf", time_spent);

    return 0;
}