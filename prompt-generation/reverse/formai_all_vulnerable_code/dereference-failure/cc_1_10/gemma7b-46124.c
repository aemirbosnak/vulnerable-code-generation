//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void createMaze(int **maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }
}

void generateMaze(int **maze, int size)
{
    int x, y;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x = rand() % size;
            y = rand() % size;
            if (maze[x][y] == 0)
            {
                maze[x][y] = 1;
            }
        }
    }
}

void printMaze(int **maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX_SIZE;
    int **maze = NULL;

    createMaze(&maze, size);
    generateMaze(maze, size);
    printMaze(maze, size);

    return 0;
}