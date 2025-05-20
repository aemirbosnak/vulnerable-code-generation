//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void generateMaze(int **maze, int x, int y)
{
    int i, j, r, c;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            maze[i][j] = 0;
        }
    }

    r = rand() % MAX;
    c = rand() % MAX;

    maze[r][c] = 1;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (maze[i][j] == 0)
            {
                if (i - 1 >= 0 && maze[i - 1][j] == 1)
                {
                    maze[i][j] = 2;
                }
                else if (i + 1 < x && maze[i + 1][j] == 1)
                {
                    maze[i][j] = 2;
                }
                else if (j - 1 >= 0 && maze[i][j - 1] == 1)
                {
                    maze[i][j] = 2;
                }
                else if (j + 1 < y && maze[i][j + 1] == 1)
                {
                    maze[i][j] = 2;
                }
            }
        }
    }
}

int main()
{
    int x = 10, y = 10;
    int **maze = NULL;

    maze = (int **)malloc(x * sizeof(int *) + y * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        maze[i] = (int *)malloc(y * sizeof(int));
    }

    generateMaze(maze, x, y);

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