//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void maze_route_finder(int **maze, int x, int y)
{
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    if (maze[x][y] == 2)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX && maze[nx][ny] != 1)
        {
            maze[nx][ny] = 2;
            maze_route_finder(maze, nx, ny);
        }
    }

    return;
}

int main()
{
    int maze[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    maze_route_finder(maze, 0, 0);

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