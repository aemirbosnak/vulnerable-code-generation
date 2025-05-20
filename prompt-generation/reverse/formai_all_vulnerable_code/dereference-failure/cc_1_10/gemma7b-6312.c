//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

void generateMaze(int **maze, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            maze[r][c] = rand() % 2;
        }
    }
}

void printMaze(int **maze, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **maze = NULL;
    int w = MAZE_WIDTH;
    int h = MAZE_HEIGHT;

    maze = (int **)malloc(h * sizeof(int *) + h);
    for (int r = 0; r < h; r++)
    {
        maze[r] = (int *)malloc(w * sizeof(int) + w);
    }

    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    for (int r = 0; r < h; r++)
    {
        free(maze[r]);
    }
    free(maze);

    return 0;
}