//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void printGrid(int **grid)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", grid[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = (int **)malloc(MAX * sizeof(int *));
    for(int r = 0; r < MAX; r++)
    {
        grid[r] = (int *)malloc(MAX * sizeof(int));
    }

    // Initial grid
    grid[0][0] = grid[0][1] = grid[1][0] = grid[1][1] = 1;

    // Game of Life rules
    for(int t = 0; t < 10; t++)
    {
        printGrid(grid);

        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int neighbors = 0;
                if(r - 1) neighbors++;
                if(r + 1) neighbors++;
                if(c - 1) neighbors++;
                if(c + 1) neighbors++;

                if(grid[r][c] && neighbors < 2) grid[r][c] = 0;
                else if(!grid[r][c] && neighbors == 3) grid[r][c] = 1;
            }
        }
    }

    printGrid(grid);

    for(int r = 0; r < MAX; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}