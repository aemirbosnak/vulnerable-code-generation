//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40

void generate_maze(int **maze, int w, int h)
{
    int i, j;
    srand(time(NULL));

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }
}

void draw_maze(int **maze, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (maze[i][j] == 0)
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
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

    maze = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        maze[i] = (int*)malloc(w * sizeof(int));
    }

    generate_maze(maze, w, h);
    draw_maze(maze, w, h);

    free(maze);

    return 0;
}