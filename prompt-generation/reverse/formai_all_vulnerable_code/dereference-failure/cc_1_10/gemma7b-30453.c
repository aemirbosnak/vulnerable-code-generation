//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int **grid = NULL;
    int i, j, k, seed, percolate = 0;

    seed = time(NULL);
    srand(seed);

    grid = (int**)malloc(MAX * sizeof(int*));
    for (i = 0; i < MAX; i++)
    {
        grid[i] = (int*)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation algorithm
    for (k = 0; k < MAX; k++)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (rand() % 2 == 0)
                    {
                        grid[i][j] = 1;
                        percolate++;
                    }
                }
            }
        }
    }

    // Print the percolated grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Print the number of percolated sites
    printf("Number of percolated sites: %d\n", percolate);

    return 0;
}