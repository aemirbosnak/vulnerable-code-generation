//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define WIDTH 256
#define HEIGHT 256

#define DELAY 50

int main()
{
    // Initialize the grid
    int **grid = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Percolation
    for (int t = 0; t < 1000; t++)
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is empty and the probability of occupation is high, occupy it
        if (grid[x][y] == 0 && rand() % 10 == 0)
        {
            grid[x][y] = 1;
        }
    }

    // Draw the grid
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == 1)
            {
                printf("%c", '#');
            }
            else
            {
                printf("%c", '.');
            }
        }
        printf("\n");
    }

    // Free the memory
    free(grid);

    return 0;
}