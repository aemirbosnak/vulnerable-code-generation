//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

void drawMap(int **map);

int main()
{
    int **map = NULL;
    int x, y;

    map = (int **)malloc(MAP_SIZE * sizeof(int *));
    for (x = 0; x < MAP_SIZE; x++)
    {
        map[x] = (int *)malloc(MAP_SIZE * sizeof(int));
    }

    // Initialize the map
    for (x = 0; x < MAP_SIZE; x++)
    {
        for (y = 0; y < MAP_SIZE; y++)
        {
            map[x][y] = 0;
        }
    }

    // Draw the map
    drawMap(map);

    // Free the memory
    for (x = 0; x < MAP_SIZE; x++)
    {
        free(map[x]);
    }
    free(map);

    return 0;
}

void drawMap(int **map)
{
    int x, y;

    for (x = 0; x < MAP_SIZE; x++)
    {
        for (y = 0; y < MAP_SIZE; y++)
        {
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }
}