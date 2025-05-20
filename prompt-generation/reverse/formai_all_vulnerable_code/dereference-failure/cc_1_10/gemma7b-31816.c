//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void generateMaze(int n, int m)
{
    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Generate the maze
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                maze[i][j] = 1;
            }
            else if (rand() % 2 == 0)
            {
                maze[i][j] = 1;
            }
        }
    }

    // Print the maze
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(maze[i]);
    }
    free(maze);
}

int main()
{
    generateMaze(5, 5);
    return 0;
}