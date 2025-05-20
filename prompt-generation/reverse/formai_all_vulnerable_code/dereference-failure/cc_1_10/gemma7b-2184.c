//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

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
    maze[0][h - 1] = WALL_CHAR;
    maze[w - 1][0] = WALL_CHAR;
    maze[w - 1][h - 1] = WALL_CHAR;
}

int main()
{
    int **maze;
    int w, h;

    w = MAP_WIDTH;
    h = MAP_HEIGHT;

    maze = (int *)malloc(w * h * sizeof(int));
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