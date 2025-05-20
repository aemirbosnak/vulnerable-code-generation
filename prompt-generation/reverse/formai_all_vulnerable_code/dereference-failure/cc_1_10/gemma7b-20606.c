//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void generateMaze(int **maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }
}

void findRoute(int **maze, int size, int x, int y)
{
    if (x < 0 || x >= size || y < 0 || y >= size || maze[x][y] == 1)
    {
        return;
    }

    maze[x][y] = 2;

    findRoute(maze, size, x - 1, y);
    findRoute(maze, size, x + 1, y);
    findRoute(maze, size, x, y - 1);
    findRoute(maze, size, x, y + 1);

    return;
}

int main()
{
    int size = MAX_SIZE;
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    generateMaze(maze, size);
    findRoute(maze, size, 0, 0);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}