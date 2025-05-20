//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PLAYER 2

void generate_maze(int **maze, int w, int h)
{
    int i, j;
    srand(time(NULL));

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (rand() % 2 == 0)
            {
                maze[i][j] = WALL;
            }
        }
    }

    maze[0][0] = PLAYER;
}

int main()
{
    int **maze;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int));
    }

    generate_maze(maze, w, h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}