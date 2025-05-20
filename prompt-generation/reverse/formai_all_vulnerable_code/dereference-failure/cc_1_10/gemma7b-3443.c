//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10

void createMaze(int **maze, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        maze[x] = (int *)malloc(size * sizeof(int));
        for (y = 0; y < size; y++)
        {
            maze[x][y] = 0;
        }
    }
}

void generateMaze(int **maze, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (x == 0 || y == 0)
            {
                maze[x][y] = 1;
            }
            else if (rand() % 2 == 0)
            {
                maze[x][y] = 1;
            }
        }
    }
}

void printMaze(int **maze, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    createMaze(&maze, MAZE_SIZE);
    generateMaze(maze, MAZE_SIZE);
    printMaze(maze, MAZE_SIZE);

    return 0;
}