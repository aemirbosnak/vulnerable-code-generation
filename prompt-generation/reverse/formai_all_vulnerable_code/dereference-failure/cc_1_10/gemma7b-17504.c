//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void maze_route_finder(int **maze, int x, int y)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int i, j;

    if (maze[x][y] == 2)
    {
        return;
    }

    maze[x][y] = 2;

    for (i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && maze[nx][ny] == 0)
        {
            maze_route_finder(maze, nx, ny);
        }
    }

    return;
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

    maze[2][2] = 2;
    maze_route_finder(maze, 2, 2);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", maze[i][j]);
        }

        printf("\n");
    }

    return 0;
}