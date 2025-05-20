//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void createMaze(int **maze, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }
    maze[size - 1][size - 1] = 1;
}

int main()
{
    int size = MAX_SIZE;
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    createMaze(maze, size);

    int x = 0, y = 0;
    maze[x][y] = 2;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int found = 0;
    while (!found)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < size && ny < size && maze[nx][ny] == 0)
            {
                x = nx;
                y = ny;
                maze[x][y] = 2;
                if (x == size - 1 && y == size - 1)
                {
                    found = 1;
                }
            }
        }
    }

    printf("The solution to the maze is:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}