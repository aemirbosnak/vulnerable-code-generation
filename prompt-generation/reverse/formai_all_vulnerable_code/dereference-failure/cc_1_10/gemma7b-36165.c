//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
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
                int x = i + 1;
                int y = j + 1;
                if (x < size && y < size && arr[x][y] == 0)
                {
                    arr[x][y] = 1;
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
    arr[3][4] = arr[5][6] = arr[7][8] = 1;

    percolate(arr, size);

    // Print the percolated array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}