//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1024

int main()
{
    int i, j, x, y, z, n, m, rain, thunder, wind;
    char **map;

    map = (char**)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        map[i] = (char *)malloc(MAX * sizeof(char));
    }

    n = 10;
    m = 10;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            map[i][j] = '.';
        }
    }

    rain = rand() % 2;
    thunder = rand() % 2;
    wind = rand() % 2;

    if (rain)
    {
        map[rand() % n][rand() % m] = 'R';
    }

    if (thunder)
    {
        map[rand() % n][rand() % m] = 'T';
    }

    if (wind)
    {
        map[rand() % n][rand() % m] = 'W';
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}