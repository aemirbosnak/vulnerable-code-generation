//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void drawGrid(int **grid, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", grid[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = (int**)malloc(MAX_SIZE * sizeof(int*));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    int size = MAX_SIZE;
    int generation = 0;

    // Initialize the grid
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Game loop
    while(1)
    {
        drawGrid(grid, size);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(grid[r + dr][c + dc] && grid[r + dr][c + dc] != grid[r][c])
                        {
                            neighbors++;
                        }
                    }
                }

                if(grid[r][c] == 1 && neighbors < 2)
                {
                    grid[r][c] = 0;
                }
                else if(grid[r][c] == 0 && neighbors == 3)
                {
                    grid[r][c] = 1;
                }
            }
        }

        generation++;
        printf("Press any key to continue...");
        getchar();
    }

    // Free the memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}