//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize = 1, min, max;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucketSize = (max - min) / MAX_SIZE + 1;

    int **buckets = (int **)malloc(bucketSize * sizeof(int *));

    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0] / MAX_SIZE][arr[i][0] % MAX_SIZE] = arr[i];
    }

    int **sortedArr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        sortedArr[i] = (int *)malloc(2 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        sortedArr[i][0] = buckets[arr[i][0] / MAX_SIZE][arr[i][0] % MAX_SIZE];
        sortedArr[i][1] = arr[i][1];
    }

    free(buckets);
    free(sortedArr);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 2;
    arr[0][1] = 5;
    arr[1][0] = 4;
    arr[1][1] = 3;
    arr[2][0] = 6;
    arr[2][1] = 2;
    arr[3][0] = 3;
    arr[3][1] = 4;
    arr[4][0] = 8;
    arr[4][1] = 6;
    arr[5][0] = 4;
    arr[5][1] = 2;
    arr[6][0] = 7;
    arr[6][1] = 8;
    arr[7][0] = 6;
    arr[7][1] = 3;
    arr[8][0] = 9;
    arr[8][1] = 4;
    arr[9][0] = 2;
    arr[9][1] = 8;

    bucketSort(arr, 10);

    printf("Sorted Array:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("(%d, %d) ", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}