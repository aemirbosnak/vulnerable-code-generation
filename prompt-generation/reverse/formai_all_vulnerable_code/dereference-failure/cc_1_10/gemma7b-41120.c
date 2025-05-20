//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void reshape(int **arr, int n, int m)
{
    int i, j, k = 0;
    int *ptr = (int *)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = ptr[k];
            k++;
        }
    }

    free(arr);
    arr = NULL;
}

int main()
{
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    reshape(arr, 2, 3);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}