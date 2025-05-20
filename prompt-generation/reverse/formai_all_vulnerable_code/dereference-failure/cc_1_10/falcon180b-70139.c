//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int arr[], int n)
{
    int i, j, k, max, min;
    int *bucket[n];

    // Initialize all buckets to empty
    for (i = 0; i < n; i++)
        bucket[i] = NULL;

    // Insert each element into its corresponding bucket
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            continue;
        max = arr[i] * n;
        min = arr[i];
        k = (max - min) / n + 1;
        for (j = 0; j < k; j++)
        {
            if (j * n <= max && (j + 1) * n > max)
                break;
        }
        bucket[j] = (int *)realloc(bucket[j], (k + 1) * sizeof(int));
        bucket[j][k - 1] = arr[i];
    }

    // Concatenate all non-empty buckets
    int *result = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (bucket[i]!= NULL)
        {
            for (j = 0; j <= k; j++)
            {
                result[index++] = bucket[i][j];
            }
            free(bucket[i]);
            bucket[i] = NULL;
        }
    }

    // Copy the result back to the original array
    for (i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

int main()
{
    int arr[] = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}