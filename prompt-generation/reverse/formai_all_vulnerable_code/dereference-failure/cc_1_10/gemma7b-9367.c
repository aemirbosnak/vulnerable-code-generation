//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **grid = NULL;
    int **water = NULL;
    int x, y, i, j, seed, occupied = 0;

    seed = time(NULL);
    srand(seed);

    grid = (int**)malloc(WIDTH * sizeof(int*));
    water = (int**)malloc(WIDTH * sizeof(int*));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int*)malloc(HEIGHT * sizeof(int));
        water[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            water[i][j] = 0;
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for (i = 0; i < WIDTH * HEIGHT; i++)
    {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        if (grid[y][x] == 0 && water[y][x] == 0)
        {
            water[y][x] = 1;
            occupied++;
        }
    }

    // Print the results
    printf("Number of occupied cells: %d\n", occupied);

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", water[i][j]);
        }
        printf("\n");
    }

    free(grid);
    free(water);

    return 0;
}