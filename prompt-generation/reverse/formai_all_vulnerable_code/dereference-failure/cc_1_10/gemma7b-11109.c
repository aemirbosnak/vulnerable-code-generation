//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, *bucket, **histogram = NULL;

    // Calculate the bucket size
    bucket_size = n / MAX_SIZE;

    // Create the bucket array
    bucket = (int *)malloc(bucket_size * MAX_SIZE * sizeof(int));

    // Create the histogram
    histogram = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        histogram[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        histogram[k][arr[i] % bucket_size]++;
    }

    // Merge the buckets
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (histogram[i][j] > 0)
            {
                for (k = 0; k < histogram[i][j]; k++)
                {
                    arr[i * MAX_SIZE + k] = j * bucket_size + i;
                }
            }
        }
    }

    // Free the memory
    free(bucket);
    for (i = 0; i < bucket_size; i++)
    {
        free(histogram[i]);
    }
    free(histogram);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 2, 4, 3, 6};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}