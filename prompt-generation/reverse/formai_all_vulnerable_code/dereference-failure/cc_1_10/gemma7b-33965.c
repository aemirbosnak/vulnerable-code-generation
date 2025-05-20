//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, *bucket, **sorted_arr;

    sorted_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        sorted_arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    bucket_size = n;
    bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < bucket_size; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        bucket[k]++;
    }

    for (i = 1; i < bucket_size; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        k = arr[i];
        sorted_arr[bucket[k] - 1][k] = arr[i];
        bucket[k]--;
    }

    for (i = 0; i < n; i++)
    {
        free(sorted_arr[i]);
    }

    free(sorted_arr);
    free(bucket);
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % MAX;
        }
    }

    bucket_sort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}