//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void createMaze(int **maze, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            maze[i][j] = 0;
        }
    }
    maze[n - 1][m - 1] = 1;
}

void findRoute(int **maze, int x, int y)
{
    if (maze[x][y] == 1)
    {
        return;
    }
    maze[x][y] = 2;
    findRoute(maze, x - 1, y);
    findRoute(maze, x, y - 1);
    findRoute(maze, x + 1, y);
    findRoute(maze, x, y + 1);
}

int main()
{
    int **maze;
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);

    findRoute(maze, 0, 0);

    printf("The route is: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}