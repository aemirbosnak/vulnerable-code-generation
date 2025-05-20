//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

void percolate(int **arr, int size)
{
    int i, j, k, r, n;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }
    for (r = 0; r < MAX_SIZE; r++)
    {
        for (n = 0; n < size; n++)
        {
            for (k = 0; k < size; k++)
            {
                if (arr[n][k] == 1 && arr[n][k] != arr[r][k])
                {
                    arr[r][k] = 1;
                }
            }
        }
    }
}

int main()
{
    int **arr;
    int size;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);
    arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }
    percolate(arr, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}