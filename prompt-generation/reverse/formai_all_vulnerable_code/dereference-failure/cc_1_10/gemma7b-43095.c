//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define FILLED 1

void draw_map(int **map)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == FILLED)
            {
                printf("%c ", '*');
            }
            else
            {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }
}

int main()
{
    int **map = (int **)malloc(HEIGHT * sizeof(int *));
    for (int y = 0; y < HEIGHT; y++)
    {
        map[y] = (int *)malloc(WIDTH * sizeof(int));
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = EMPTY;
        }
    }

    // Percolation simulation
    for (int iteration = 0; iteration < 10; iteration++)
    {
        // Randomly fill some cells
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        map[y][x] = FILLED;

        // Spread water
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT && map[new_y][new_x] == EMPTY)
            {
                map[new_y][new_x] = FILLED;
            }
        }
    }

    draw_map(map);

    free(map);

    return 0;
}