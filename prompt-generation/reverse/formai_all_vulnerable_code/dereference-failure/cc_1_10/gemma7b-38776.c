//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n)
{
    int i, j, k, buckets[n], min, max;
    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (min > arr[i][0])
                min = arr[i][0];
            if (max < arr[i][0])
                max = arr[i][0];
        }
    }

    buckets[0] = min;
    buckets[n - 1] = max;
    for (k = 1; buckets[k] - buckets[k - 1] > 0; k++)
    {
        buckets[k] = buckets[k - 1] + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            arr[i][0] = buckets[arr[i][2]] - 1;
        }
    }
}

int main()
{
    int **arr = NULL;
    int n = 0;

    scanf("Enter the number of elements: ", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        scanf("Enter the element: ", &arr[i][0]);
        scanf("Enter the number of occurrences: ", &arr[i][1]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i][1]; j++)
        {
            printf("%d ", arr[i][0]);
        }
        printf("\n");
    }

    return 0;
}