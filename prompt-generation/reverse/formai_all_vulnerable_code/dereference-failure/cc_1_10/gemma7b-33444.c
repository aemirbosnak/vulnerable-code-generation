//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolate(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = i;
                int y = j;
                arr[x][y] = 2;
                if (x > 0)
                {
                    arr[x - 1][y] = 2;
                }
                if (x < MAX_SIZE - 1)
                {
                    arr[x + 1][y] = 2;
                }
                if (y > 0)
                {
                    arr[x][y - 1] = 2;
                }
                if (y < MAX_SIZE - 1)
                {
                    arr[x][y + 1] = 2;
                }
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Create a random pattern
    arr[5][5] = 1;
    arr[6][5] = 1;
    arr[6][6] = 1;
    arr[7][6] = 1;

    percolate(arr, size);

    // Print the result
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