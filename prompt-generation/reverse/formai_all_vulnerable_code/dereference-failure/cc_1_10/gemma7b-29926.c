//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

void drawMaze(int **maze, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (maze[y][x] == 1)
            {
                printf("O ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int **maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            maze[y][x] = rand() % 2;
        }
    }

    drawMaze(maze, WIDTH, HEIGHT);

    free(maze);

    return 0;
}