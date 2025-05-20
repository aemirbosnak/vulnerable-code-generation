//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENG 10

void generateMaze(int **maze, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            maze[x][y] = rand() % 2;
        }
    }
}

void drawMaze(int **maze, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (maze[x][y] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{
    int size = 10;
    int **maze = NULL;

    maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    generateMaze(maze, size);
    drawMaze(maze, size);

    return 0;
}