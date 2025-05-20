//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int arr[], int n)
{
    int i, j, k, bucket_size, *bucket, **histogram = NULL;

    histogram = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        histogram[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    bucket_size = n / MAX_SIZE;
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            histogram[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / MAX_SIZE;
        histogram[k][arr[i] % MAX_SIZE]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (histogram[i][j] > 0)
            {
                for (k = 0; k < histogram[i][j]; k++)
                {
                    arr[i * MAX_SIZE + k] = j * MAX_SIZE + k;
                }
            }
        }
    }

    free(histogram);
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 6, 1, 9, 7, 3};
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