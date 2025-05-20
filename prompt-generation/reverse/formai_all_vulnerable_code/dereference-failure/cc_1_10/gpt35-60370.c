//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 100000

double get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (tv.tv_usec / 1000000.0);
}

void busy_wait(int n)
{
    int i;
    for(i = 0; i < n * 1000000; i++);
}

int main()
{
    double start, end;
    int i, j, sum = 0;

    // Generate random integer array
    int *arr = malloc(N * sizeof(int));
    srand(time(NULL));
    for(i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
    }

    // Benchmark sorting algorithm
    start = get_time();
    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = get_time();
    printf("Sorting took %f seconds.\n", end - start);

    // Benchmark busy-wait loop
    start = get_time();
    busy_wait(10);
    end = get_time();
    printf("Busy-wait loop took %f seconds.\n", end - start);

    // Benchmark multiplication loop
    start = get_time();
    for(i = 1; i <= 100000; i++)
    {
        sum *= i;
    }
    end = get_time();
    printf("Multiplication loop took %f seconds.\n", end - start);

    free(arr);
    return 0;
}