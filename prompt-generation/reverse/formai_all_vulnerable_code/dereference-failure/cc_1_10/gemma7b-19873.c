//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

void draw_maze(int **maze, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (maze[i][j] == WALL)
            {
                printf("W");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int **maze = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        maze[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;

    maze[x][y] = WALL;

    draw_maze(maze, WIDTH, HEIGHT);

    free(maze);

    return 0;
}