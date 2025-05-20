//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: post-apocalyptic
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main()
{
    int x, y;
    int **weather_map = NULL;
    int seed = time(NULL);

    weather_map = (int**)malloc(MAX_HEIGHT * sizeof(int*));
    for(y = 0; y < MAX_HEIGHT; y++)
    {
        weather_map[y] = (int*)malloc(MAX_WIDTH * sizeof(int));
    }

    for(x = 0; x < MAX_WIDTH; x++)
    {
        for(y = 0; y < MAX_HEIGHT; y++)
        {
            weather_map[y][x] = rand() % 3;
        }
    }

    for(x = 0; x < MAX_WIDTH; x++)
    {
        for(y = 0; y < MAX_HEIGHT; y++)
        {
            switch(weather_map[y][x])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("x ");
                    break;
            }
        }
        printf("\n");
    }

    for(y = 0; y < MAX_HEIGHT; y++)
    {
        free(weather_map[y]);
    }
    free(weather_map);

    return 0;
}