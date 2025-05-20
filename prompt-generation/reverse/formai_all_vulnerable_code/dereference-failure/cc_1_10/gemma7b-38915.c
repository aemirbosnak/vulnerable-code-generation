//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void findRoute(int **maze, int x, int y)
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
    findRoute(maze, x - 1, y);
    findRoute(maze, x + 1, y);
    findRoute(maze, x, y - 1);
    findRoute(maze, x, y + 1);
}

int main()
{
    int **maze = NULL;
    int x, y;

    // Allocate memory for the maze
    maze = (int **)malloc(MAX * sizeof(int *));
    for (x = 0; x < MAX; x++)
    {
        maze[x] = (int *)malloc(MAX * sizeof(int));
    }

    // Create the maze
    maze[10][10] = 1;
    maze[10][11] = 1;
    maze[11][10] = 1;
    maze[11][11] = 1;

    // Find the route
    findRoute(maze, 0, 0);

    // Print the route
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < MAX; x++)
    {
        free(maze[x]);
    }
    free(maze);

    return 0;
}