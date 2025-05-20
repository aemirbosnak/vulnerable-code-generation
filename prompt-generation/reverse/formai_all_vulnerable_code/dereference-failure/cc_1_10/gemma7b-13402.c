//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

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

    maze[0][0] = START;
    maze[w - 1][h - 1] = END;

    return;
}

int main()
{
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

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

    free(maze);

    return 0;
}