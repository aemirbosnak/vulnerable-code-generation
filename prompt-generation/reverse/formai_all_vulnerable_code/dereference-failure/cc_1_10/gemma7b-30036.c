//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

#define WALL 1
#define EMPTY 0

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
            if (x == 0 || y == 0 || x == w - 1 || y == h - 1)
            {
                maze[x][y] = WALL;
            }
            else
            {
                maze[x][y] = EMPTY;
            }
        }
    }

    return;
}

int main()
{
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

    maze = (int **)malloc(w * sizeof(int *));
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