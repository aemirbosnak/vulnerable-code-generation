//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, range;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    range = max - min + 1;

    bucket_size = range / MAX_SIZE;

    int **buckets = malloc(bucket_size * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        buckets[k][arr[i][1]] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (buckets[i][j] != NULL)
            {
                printf("%d ", buckets[i][j]);
            }
        }
    }

    free(buckets);
}

int main()
{
    int n, i, **arr;

    scanf("Enter the number of elements: ", &n);

    arr = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = malloc(2 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        scanf("Enter the element: ", &arr[i][0]);
        scanf("Enter the index: ", &arr[i][1]);
    }

    bucket_sort(arr, n);

    printf("\n");

    return 0;
}