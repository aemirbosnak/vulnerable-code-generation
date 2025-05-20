//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, min, max;
    int **buckets = NULL;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    bucket_size = (max - min) / MAX_SIZE + 1;
    buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = (arr[i] - min) / bucket_size;
        buckets[k][arr[i]] = 1;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (buckets[i][j] == 1)
            {
                arr[k] = j + min;
                k++;
            }
        }
    }

    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6, 0};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);

    printf("\n");

    return 0;
}