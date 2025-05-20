//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the map
    int **map = (int *)malloc(MAP_SIZE * MAP_SIZE * sizeof(int));
    for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++)
    {
        map[i] = rand() % 2;
    }

    // Percolation
    for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++)
    {
        if (map[i] == 1)
        {
            int x = i % MAP_SIZE;
            int y = i / MAP_SIZE;

            // Check if the neighbor is also wet
            if (map[x - 1] == 1)
            {
                map[i] = 2;
            }
            if (map[x + 1] == 1)
            {
                map[i] = 2;
            }
            if (map[y - 1] == 1)
            {
                map[i] = 2;
            }
            if (map[y + 1] == 1)
            {
                map[i] = 2;
            }
        }
    }

    // Print the map
    for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++)
    {
        printf("%d ", map[i]);
    }

    // Free the memory
    free(map);

    return 0;
}