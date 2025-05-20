//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Change the size of the grid here

void print_grid(int** grid, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(grid[i][j] == 0)
                printf("\u25FB "); // Print a white square
            else
                printf("\u25FC "); // Print a black square
        }
        printf("\n");
    }
}

int** create_grid(int size)
{
    int** grid = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++)
        grid[i] = (int*)calloc(size, sizeof(int));
    return grid;
}

void percolate(int** grid, int size)
{
    int i = 0;
    while(!grid[size - 1][i]) // Find top site connected to bottom site
    {
        i++;
        if(i == size) // Grid is not percolating
            return;
    }
    grid[0][i] = 1; // Connect top and bottom sites
    for(int j = 0; j < size; j++)
    {
        if(grid[0][j] && grid[1][j]) // Connect neighboring sites
            grid[0][j] = grid[size - 1][j] = 1;
    }
    print_grid(grid, size);
}

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int** grid = create_grid(SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            double p = (double)rand() / RAND_MAX; // Generate a random number
            if(p < 0.5) // Fill site with probability 0.5
                grid[i][j] = 1;
        }
    }
    print_grid(grid, SIZE);
    printf("\nPercolating...\n\n");
    percolate(grid, SIZE);
    for(int i = 0; i < SIZE; i++)
        free(grid[i]);
    free(grid);
    return 0;
}