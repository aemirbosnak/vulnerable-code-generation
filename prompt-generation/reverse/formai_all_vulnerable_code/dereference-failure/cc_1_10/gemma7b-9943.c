//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void generateMaze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }
}

int findPath(int **maze, int n, int m, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return 0;
    }

    if (maze[x][y] == 1)
    {
        return 0;
    }

    maze[x][y] = 1;

    if (findPath(maze, n, m, x - 1, y) || findPath(maze, n, m, x, y - 1) || findPath(maze, n, m, x + 1, y) || findPath(maze, n, m, x, y + 1))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    generateMaze(maze, n, m);

    int x, y;
    printf("Enter the starting x-coordinate: ");
    scanf("%d", &x);
    printf("Enter the starting y-coordinate: ");
    scanf("%d", &y);

    if (findPath(maze, n, m, x, y) == 1)
    {
        printf("Path found!");
    }
    else
    {
        printf("No path found!");
    }

    return 0;
}