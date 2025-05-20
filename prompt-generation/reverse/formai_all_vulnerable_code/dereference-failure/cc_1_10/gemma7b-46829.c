//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void printMaze(int **maze, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **maze = NULL;
    int r = 5;
    int c = 5;

    maze = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        maze[i] = (int *)malloc(c * sizeof(int));
    }

    // Generate the maze
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            maze[i][j] = rand() % MAX;
        }
    }

    printMaze(maze, r, c);

    // Find the route
    int x = 0;
    int y = 0;
    int target_x = 2;
    int target_y = 2;

    while (x != target_x || y != target_y)
    {
        // Calculate the direction
        int dx = rand() % 2 - 1;
        int dy = rand() % 2 - 1;

        // Move in that direction
        x += dx;
        y += dy;

        // If the cell is not a wall, set it to 2
        if (maze[x][y] != 1)
        {
            maze[x][y] = 2;
        }
    }

    printMaze(maze, r, c);

    return 0;
}