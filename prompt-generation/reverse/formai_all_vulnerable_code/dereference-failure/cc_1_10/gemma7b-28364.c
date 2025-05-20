//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return;
}

void generateMaze(int **maze, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    return;
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

    return;
}

int main()
{
    int size = MAX_SIZE;
    int **maze = NULL;

    createMaze(maze, size);
    generateMaze(maze, size);
    printMaze(maze, size);

    return 0;
}