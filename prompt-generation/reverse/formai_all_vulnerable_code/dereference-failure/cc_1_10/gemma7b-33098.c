//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void arith_operations(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = arr[i][0] + arr[0][j];
            }
        }
    }
}

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int **arr = (int **)malloc(n * sizeof(int *)), i, j;
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("Enter the element at (%d, %d): ", &arr[i][j]);
        }
    }

    arith_operations(arr, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("The element at (%d, %d) is: %d\n", i, j, arr[i][j]);
        }
    }

    free(arr);

    return 0;
}