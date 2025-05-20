//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void generate_maze(int **maze, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            maze[r][c] = rand() % 2;
        }
    }
}

void print_maze(int **maze, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }
}

int find_route(int **maze, int size, int x, int y)
{
    if (x < 0 || x >= size || y < 0 || y >= size)
    {
        return 0;
    }
    if (maze[x][y] == 1)
    {
        return 0;
    }
    maze[x][y] = 1;
    if (find_route(maze, size, x - 1, y) || find_route(maze, size, x, y - 1) || find_route(maze, size, x + 1, y) || find_route(maze, size, x, y + 1))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int size = 5;
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    generate_maze(maze, size);
    print_maze(maze, size);

    find_route(maze, size, 0, 0);

    print_maze(maze, size);

    free(maze);

    return 0;
}