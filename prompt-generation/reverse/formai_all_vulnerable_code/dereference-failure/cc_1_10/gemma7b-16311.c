//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define the simulation parameters
    int width = 10;
    int height = 10;
    int num_rain_drops = 10;

    // Create the grid of weather cells
    int **cells = (int *)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        cells[i] = (int *)malloc(width * sizeof(int));
    }

    // Initialize the weather cells
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Simulate the rain falling
    for (int i = 0; i < num_rain_drops; i++)
    {
        int x = rand() % width;
        int y = rand() % height;
        cells[y][x] = 1;
    }

    // Print the weather cells
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}