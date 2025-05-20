//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, min, max, indexOfMin, indexOfMax;
    bucketSize = MAX_SIZE;
    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (min > arr[i][0])
            {
                min = arr[i][0];
                indexOfMin = i;
            }
            if (max < arr[i][0])
            {
                max = arr[i][0];
                indexOfMax = i;
            }
        }
    }
    printf("Index of minimum element: %d\n", indexOfMin);
    printf("Index of maximum element: %d\n", indexOfMax);
}

int main()
{
    int **arr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i][1]; j++)
        {
            scanf("%d", &arr[i][0]);
        }
    }

    bucketSort(arr, n);

    return 0;
}