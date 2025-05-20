//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int generateMaze(int x, int y, int **maze, int **visited)
{
    if (x >= 10 || y >= 10)
    {
        return 0;
    }
    if (visited[x][y] == 1)
    {
        return 0;
    }

    visited[x][y] = 1;

    if (generateMaze(x - 1, y, maze, visited) == 0)
    {
        return 0;
    }
    if (generateMaze(x + 1, y, maze, visited) == 0)
    {
        return 0;
    }
    if (generateMaze(x, y - 1, maze, visited) == 0)
    {
        return 0;
    }
    if (generateMaze(x, y + 1, maze, visited) == 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int **maze = NULL;
    int **visited = NULL;
    int x, y;

    x = 5;
    y = 5;

    maze = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        maze[i] = (int*)malloc(y * sizeof(int));
    }

    visited = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        visited[i] = (int*)malloc(y * sizeof(int));
    }

    generateMaze(0, 0, maze, visited);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}