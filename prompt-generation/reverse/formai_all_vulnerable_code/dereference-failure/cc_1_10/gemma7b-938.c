//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void findMazeRoute(int **maze, int x, int y, char **route)
{
    if (x < 0 || x >= MAX || y < 0 || y >= MAX || maze[x][y] == 0 || route[x][y] == 'S')
    {
        return;
    }

    route[x][y] = 'T';

    findMazeRoute(maze, x - 1, y, route);
    findMazeRoute(maze, x + 1, y, route);
    findMazeRoute(maze, x, y - 1, route);
    findMazeRoute(maze, x, y + 1, route);

    return;
}

int main()
{
    int maze[MAX][MAX] = {{1, 1, 1, 0, 1},
                              {1, 1, 0, 0, 1},
                              {1, 0, 1, 1, 1},
                              {0, 0, 0, 0, 1},
                              {1, 1, 1, 1, 1}};

    char **route = (char **)malloc(MAX * MAX * sizeof(char));
    for (int i = 0; i < MAX; i++)
    {
        route[i] = (char *)malloc(MAX * sizeof(char));
        for (int j = 0; j < MAX; j++)
        {
            route[i][j] = 'U';
        }
    }

    findMazeRoute(maze, 0, 0, route);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%c ", route[i][j]);
        }
        printf("\n");
    }

    return 0;
}