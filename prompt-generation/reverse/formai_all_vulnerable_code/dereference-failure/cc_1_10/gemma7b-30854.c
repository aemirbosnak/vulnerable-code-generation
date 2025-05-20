//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void dfs(int **maze, int x, int y)
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

    dfs(maze, x - 1, y);
    dfs(maze, x + 1, y);
    dfs(maze, x, y - 1);
    dfs(maze, x, y + 1);
}

int main()
{
    int i, j, k, l, x, y;
    int **maze = NULL;

    maze = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        maze[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            maze[i][j] = 0;
        }
    }

    x = rand() % MAX;
    y = rand() % MAX;

    maze[x][y] = 1;

    dfs(maze, x, y);

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}