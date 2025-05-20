//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h)
{
    int x, y;
    srand(time(NULL));

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = EMPTY_CHAR + rand() % 2;
        }
    }

    maze[0][0] = WALL_CHAR;
    maze[w - 1][h - 1] = WALL_CHAR;
}

int main()
{
    int **maze;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int **)malloc(w * sizeof(int *) + w * h * sizeof(int));

    generateMaze(maze, w, h);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}