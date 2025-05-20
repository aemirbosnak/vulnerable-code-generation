//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void findRoute(int **maze, int x, int y, int targetX, int targetY)
{
    if (x == targetX && y == targetY)
    {
        return;
    }

    if (maze[x][y] == 0)
    {
        return;
    }

    maze[x][y] = 0;

    findRoute(maze, x - 1, y, targetX, targetY);
    findRoute(maze, x + 1, y, targetX, targetY);
    findRoute(maze, x, y - 1, targetX, targetY);
    findRoute(maze, x, y + 1, targetX, targetY);
}

int main()
{
    int maze[MAX][MAX] = {{1, 0, 1, 0, 1},
                              {0, 1, 1, 0, 0},
                              {1, 1, 1, 0, 1},
                              {0, 0, 0, 0, 0},
                              {1, 1, 1, 0, 1}};

    int targetX = 2;
    int targetY = 2;

    findRoute(maze, 0, 0, targetX, targetY);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("O ");
            }
        }

        printf("\n");
    }

    return 0;
}