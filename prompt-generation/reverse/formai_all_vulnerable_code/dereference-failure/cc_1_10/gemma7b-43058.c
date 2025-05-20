//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **arr, int n)
{
    int i, j, count = 0, prev = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == prev)
            {
                count++;
            }
            else
            {
                prev = arr[i][j];
                count = 1;
            }

            arr[i][j] = count;
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
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("Enter the element: ", &arr[i][j]);
        }
    }

    compress(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("The compressed element is: %d ", arr[i][j]);
        }
    }

    return 0;
}