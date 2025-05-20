//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand(time(&t));

    int mapSize = rand() % 10 + 10;
    int numObjects = rand() % 20 + 5;

    // Create a map
    int **map = (int**)malloc(mapSize * sizeof(int *));
    for (int i = 0; i < mapSize; i++)
    {
        map[i] = (int*)malloc(mapSize * sizeof(int));
    }

    // Place objects randomly
    for (int i = 0; i < numObjects; i++)
    {
        int x = rand() % mapSize;
        int y = rand() % mapSize;
        map[x][y] = 1;
    }

    // Travel the map
    int x = 0;
    int y = 0;
    int direction = rand() % 4;

    while (map[x][y] != -1)
    {
        switch (direction)
        {
            case 0:
                x--;
                break;
            case 1:
                y++;
                break;
            case 2:
                x++;
                break;
            case 3:
                y--;
                break;
        }

        if (map[x][y] == 1)
        {
            printf("You found an object!\n");
            map[x][y] = -1;
        }
    }

    // Free the map
    for (int i = 0; i < mapSize; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}