//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

void percolate(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = i + 1;
                int y = j + 1;

                if (x < size && arr[x][y] == 0)
                {
                    arr[x][y] = 1;
                }

                x = i - 1;
                if (x >= 0 && arr[x][y] == 0)
                {
                    arr[x][y] = 1;
                }

                y = j - 1;
                if (y >= 0 && arr[i][y] == 0)
                {
                    arr[i][y] = 1;
                }

                y = j + 1;
                if (y < size && arr[i][y] == 0)
                {
                    arr[i][y] = 1;
                }
            }
        }
    }
}

int main()
{
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    int size = MAX_SIZE;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[10][10] = 1;
    arr[10][11] = 1;
    arr[11][10] = 1;

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