//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max;
    int **buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        min = arr[i][0];
        max = arr[i][1];
        buckets[min][max]++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (buckets[i][j] > 0)
            {
                for (k = 0; k < buckets[i][j]; k++)
                {
                    arr[k][0] = i;
                    arr[k][1] = j;
                }
            }
        }
    }

    free(buckets);
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Generate random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = rand() % MAX;
        arr[i][1] = rand() % MAX;
    }

    bucket_sort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d)\n", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}