//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 20

void draw_weather_map(int **map, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            switch (map[y][x])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("X");
                    break;
                case 3:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int **map = NULL;
    map = (int **)malloc(MAX_HEIGHT * sizeof(int *));
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        map[i] = (int *)malloc(MAX_WIDTH * sizeof(int));
    }

    srand(time(NULL));

    // Generate weather map
    for (int y = 0; y < MAX_HEIGHT; y++)
    {
        for (int x = 0; x < MAX_WIDTH; x++)
        {
            map[y][x] = rand() % 4;
        }
    }

    draw_weather_map(map, MAX_WIDTH, MAX_HEIGHT);

    // Free memory
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}