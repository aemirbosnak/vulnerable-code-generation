//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, *bucket, **arr_cpy;

    bucket_size = n / 10 + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    arr_cpy = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr_cpy[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        arr_cpy[k][arr[i]] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr_cpy[i][j] != NULL)
            {
                arr[j] = arr_cpy[i][j];
            }
        }
    }

    free(bucket);
    for (i = 0; i < n; i++)
    {
        free(arr_cpy[i]);
    }
    free(arr_cpy);
}

int main()
{
    int n, i, arr[10] = {4, 3, 5, 2, 8, 9, 1, 7, 6, 0};

    n = sizeof(arr) / sizeof(int);
    bucket_sort(arr, n);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n");

    return 0;
}