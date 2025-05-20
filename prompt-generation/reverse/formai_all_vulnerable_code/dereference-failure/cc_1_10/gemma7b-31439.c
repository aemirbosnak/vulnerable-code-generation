//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main()
{
    int **map = NULL;
    int width, height;
    int x, y;

    // Initialize the map
    width = MAX_WIDTH;
    height = MAX_HEIGHT;
    map = (int **)malloc(height * sizeof(int *));
    for (y = 0; y < height; y++)
    {
        map[y] = (int *)malloc(width * sizeof(int));
        for (x = 0; x < width; x++)
        {
            map[y][x] = 0;
        }
    }

    // Simulate the percolation
    srand(time(NULL));
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            if (map[y][x] == 0)
            {
                map[y][x] = rand() % 2;
            }
        }
    }

    // Print the map
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            printf("%d ", map[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (y = 0; y < height; y++)
    {
        free(map[y]);
    }
    free(map);

    return 0;
}