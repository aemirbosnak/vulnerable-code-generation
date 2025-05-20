//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void find_route(int **maze, int x, int y)
{
    if (x < 0 || x >= MAX || y < 0 || y >= MAX)
    {
        return;
    }

    if (maze[x][y] == 2)
    {
        return;
    }

    maze[x][y] = 2;

    find_route(maze, x - 1, y);
    find_route(maze, x + 1, y);
    find_route(maze, x, y - 1);
    find_route(maze, x, y + 1);
}

int main()
{
    int maze[MAX][MAX] = {{1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
                              {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
                              {1, 0, 0, 1, 1, 1, 0, 0, 1, 1},
                              {1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
                              {1, 0, 0, 0, 0, 1, 0, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    find_route(maze, 0, 0);

    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}