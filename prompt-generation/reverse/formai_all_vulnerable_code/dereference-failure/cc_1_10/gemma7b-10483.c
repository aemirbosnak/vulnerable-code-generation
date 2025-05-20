//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void findRoute(int **maze, int x, int y)
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
    findRoute(maze, x - 1, y);
    findRoute(maze, x + 1, y);
    findRoute(maze, x, y - 1);
    findRoute(maze, x, y + 1);
}

int main()
{
    int maze[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    maze[3][2] = 1;
    maze[4][2] = 1;
    maze[5][2] = 1;
    maze[6][2] = 1;

    findRoute(maze, 3, 2);

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