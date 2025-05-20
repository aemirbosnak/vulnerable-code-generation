//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PATH 2

void generateMaze(int **maze, int w, int h)
{
    int x, y;
    srand(time(NULL));

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = EMPTY;
        }
    }

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (rand() % 2 == 0)
            {
                maze[x][y] = WALL;
            }
        }
    }

    maze[0][0] = PATH;
    maze[w - 1][h - 1] = PATH;
}

int main()
{
    int **maze = NULL;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int **)malloc(w * sizeof(int *) + h * sizeof(int));
    for (int i = 0; i < w; i++)
    {
        maze[i] = (int *)malloc(h * sizeof(int));
    }

    generateMaze(maze, w, h);

    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}