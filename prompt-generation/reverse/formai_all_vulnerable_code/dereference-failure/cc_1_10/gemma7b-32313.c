//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
    int i, j, count[k], bucket[k][n], **ptr = arr;

    for (i = 0; i < k; i++)
    {
        count[i] = 0;
        for (j = 0; j < n; j++)
        {
            if ((*ptr)[j] % k == i)
            {
                count[i]++;
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            bucket[i][j] = ptr[j];
        }
    }

    int l = 0;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            ptr[l++] = bucket[i][j];
        }
    }
}

int main()
{
    int n = 10;
    int k = 5;
    int *arr = malloc(n * sizeof(int));

    // Populate the array
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 4;
    arr[5] = 3;
    arr[6] = 2;
    arr[7] = 4;
    arr[8] = 1;
    arr[9] = 5;

    bucket_sort(&arr, n, k);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}