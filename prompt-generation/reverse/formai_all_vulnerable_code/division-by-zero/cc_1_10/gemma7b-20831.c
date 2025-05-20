//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, min, max, bucket_size, *bucket, **bucket_arr;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    bucket_size = (max - min) / bucket_size + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    bucket_arr = (int **)malloc(bucket_size * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
        bucket_arr[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = (arr[i] - min) / bucket_size;
        bucket_arr[k][i] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[j] = bucket_arr[i][j];
        }
    }

    free(bucket);
    free(bucket_arr);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);

    printf("\n");

    return 0;
}