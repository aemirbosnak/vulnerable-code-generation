//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize_grid(int **grid, int size)
{
    grid = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        grid[i] = 0;
    }
}

void print_grid(int **grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i * size + j]);
        }
        printf("\n");
    }
}

void calculate_next_state(int **grid, int size)
{
    int **next_grid = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num_alive_neighbors = 0;
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if (r == 0 && c == 0)
                        continue;
                    if (grid[i + r][j + c] == 1)
                        num_alive_neighbors++;
                }
            }
            next_grid[i * size + j] = (num_alive_neighbors == 2) || (num_alive_neighbors == 3);
        }
    }

    free(next_grid);
}

int main()
{
    int size = MAX_SIZE;
    int **grid = NULL;

    initialize_grid(grid, size);
    grid[0][0] = 1;
    grid[1][0] = 1;
    grid[2][0] = 1;
    grid[0][1] = 1;
    grid[1][1] = 1;

    print_grid(grid, size);

    calculate_next_state(grid, size);

    print_grid(grid, size);

    return 0;
}