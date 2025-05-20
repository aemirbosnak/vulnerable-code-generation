//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 50
#define HEIGHT 50

#define MAX_WATER 10

int main()
{
    int **water = NULL;
    int i, j, k;
    water = (int **)malloc(HEIGHT * sizeof(int *) + HEIGHT);
    for (i = 0; i < HEIGHT; i++)
    {
        water[i] = (int *)malloc(WIDTH * sizeof(int) + WIDTH);
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            water[i][j] = 0;
        }
    }

    // Percolation Simulation

    for (k = 0; k < MAX_WATER; k++)
    {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        if (water[y][x] == 0)
        {
            water[y][x] = 1;
        }
    }

    // Displaying the Water Distribution

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", water[i][j]);
        }
        printf("\n");
    }

    return 0;
}