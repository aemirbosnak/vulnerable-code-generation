//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generate_maze(int **maze, int w, int h)
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            if (rand() % 2)
            {
                maze[i][j] = WALL;
            }
        }
    }

    maze[0][0] = PATH;
    maze[w - 1][h - 1] = PATH;
}

int main()
{
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

    maze = (int *)malloc(w * h * sizeof(int));
    generate_maze(maze, w, h);

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            switch (maze[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf("o");
                    break;
            }
        }
        printf("\n");
    }

    free(maze);

    return 0;
}