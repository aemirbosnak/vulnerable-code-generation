//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void generateMaze(int **maze, int size)
{
    int i, j, r, c;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }

    r = rand() % size;
    c = rand() % size;

    maze[r][c] = 1;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (maze[i][j] == 0)
            {
                if (i > 0 && maze[i - 1][j] == 1)
                    maze[i][j] = 2;
                if (j > 0 && maze[i][j - 1] == 1)
                    maze[i][j] = 2;
                if (i < size - 1 && maze[i + 1][j] == 1)
                    maze[i][j] = 2;
                if (j < size - 1 && maze[i][j + 1] == 1)
                    maze[i][j] = 2;
            }
        }
    }
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