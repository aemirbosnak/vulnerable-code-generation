//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            maze[y][x] = EMPTY_CHAR;
        }
    }

    int num_walls = rand() % (w * h);
    for (int i = 0; i < num_walls; i++)
    {
        int x = rand() % w;
        int y = rand() % h;
        maze[y][x] = WALL_CHAR;
    }
}

int main()
{
    int **maze = NULL;
    int w = MAZE_WIDTH;
    int h = MAZE_HEIGHT;

    maze = (int **)malloc(h * sizeof(int *) + h);
    for (int i = 0; i < h; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int) + w);
    }

    generate_maze(maze, w, h);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    return 0;
}