//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void find_route(int **maze, int x, int y)
{
    if (x < 0 || x >= MAX || y < 0 || y >= MAX)
    {
        return;
    }

    if (maze[x][y] == 1)
    {
        return;
    }

    maze[x][y] = 1;

    find_route(maze, x - 1, y);  // Left
    find_route(maze, x + 1, y);  // Right
    find_route(maze, x, y - 1);  // Down
    find_route(maze, x, y + 1);  // Up

    return;
}

int main()
{
    int **maze = NULL;
    int x, y;

    maze = (int **)malloc(MAX * MAX * sizeof(int));
    for (x = 0; x < MAX; x++)
    {
        maze[x] = (int *)malloc(MAX * sizeof(int));
        for (y = 0; y < MAX; y++)
        {
            maze[x][y] = 0;
        }
    }

    maze[2][2] = 1;
    maze[3][3] = 1;

    find_route(maze, 0, 0);

    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}