//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

int main()
{
    int **cells = NULL;
    int i, j, k;

    // Allocate memory for the cells
    cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the cells
    for (i = 0; i < MAX_CELLS; i++)
    {
        for (j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Create a random pattern
    for (i = 0; i < MAX_CELLS; i++)
    {
        for (j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Print the pattern
    for (i = 0; i < MAX_CELLS; i++)
    {
        for (j = 0; j < MAX_CELLS; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Simulate life
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < MAX_CELLS; i++)
        {
            for (j = 0; j < MAX_CELLS; j++)
            {
                int alive = cells[i][j] == 1;
                int num_alive = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0) continue;
                        if (cells[i + x][y] == 1) num_alive++;
                    }
                }
                if (alive && num_alive < 2) cells[i][j] = 0;
                else if (!alive && num_alive == 2) cells[i][j] = 1;
            }
        }
        printf("Generation %d:\n", k);
        for (i = 0; i < MAX_CELLS; i++)
        {
            for (j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }
    }

    // Free memory
    for (i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}