//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, *bucket, **histogram = NULL;

    bucket_size = n / 10 + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    histogram = (int **)malloc(bucket_size * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
    {
        histogram[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        histogram[k][arr[i]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (histogram[i][j] > 0)
            {
                for (k = 0; k < histogram[i][j]; k++)
                {
                    arr[i * bucket_size + k] = j;
                }
            }
        }
    }

    free(bucket);
    for (i = 0; i < bucket_size; i++)
    {
        free(histogram[i]);
    }
    free(histogram);
}

int main()
{
    int arr[] = {3, 5, 8, 2, 4, 7, 1, 9, 6, 0};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}