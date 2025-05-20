//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

int main()
{
    int x, y, i, j;
    int **weather_map = NULL;
    weather_map = (int **)malloc(MAX_WIDTH * sizeof(int *));
    for (i = 0; i < MAX_WIDTH; i++)
    {
        weather_map[i] = (int *)malloc(MAX_HEIGHT * sizeof(int));
    }

    // Initializing the weather map
    for (x = 0; x < MAX_WIDTH; x++)
    {
        for (y = 0; y < MAX_HEIGHT; y++)
        {
            weather_map[x][y] = 0;
        }
    }

    // Simulating a storm
    weather_map[128][128] = 10;
    weather_map[128][129] = 8;
    weather_map[128][130] = 6;
    weather_map[129][128] = 7;
    weather_map[129][129] = 9;

    // Displaying the weather map
    for (x = 0; x < MAX_WIDTH; x++)
    {
        for (y = 0; y < MAX_HEIGHT; y++)
        {
            printf("%d ", weather_map[x][y]);
        }
        printf("\n");
    }

    // Freeing the memory
    for (i = 0; i < MAX_WIDTH; i++)
    {
        for (j = 0; j < MAX_HEIGHT; j++)
        {
            free(weather_map[i][j]);
        }
        free(weather_map[i]);
    }
    free(weather_map);

    return 0;
}