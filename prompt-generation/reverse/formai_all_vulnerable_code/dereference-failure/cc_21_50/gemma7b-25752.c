//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

int main()
{
    int **arr = NULL;
    int i, j, k, n, m, r, seed;

    // Allocate memory
    arr = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Set the seeds
    seed = time(NULL);
    srand(seed);

    // Percolation
    n = rand() % DIM;
    m = rand() % DIM;
    arr[n][m] = 1;

    // Spread the infection
    for (r = 0; r < 10; r++)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (arr[i][j] == 1)
                {
                    k = rand() % 4;
                    switch (k)
                    {
                        case 0:
                            if (i - 1 >= 0 && arr[i - 1][j] == 0)
                                arr[i - 1][j] = 1;
                            break;
                        case 1:
                            if (j - 1 >= 0 && arr[i][j - 1] == 0)
                                arr[i][j - 1] = 1;
                            break;
                        case 2:
                            if (i + 1 < DIM && arr[i + 1][j] == 0)
                                arr[i + 1][j] = 1;
                            break;
                        case 3:
                            if (j + 1 < DIM && arr[i][j + 1] == 0)
                                arr[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }
    }

    // Print the result
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}