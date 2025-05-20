//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **arr;
    int i, j, k, l, n, m;
    int seed;

    // Allocate memory
    arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation
    for (k = 0; k < 100; k++)
    {
        n = rand() % MAX_SIZE;
        m = rand() % MAX_SIZE;
        if (arr[n][m] == 0)
        {
            arr[n][m] = 1;
        }
    }

    // Print the grid
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}