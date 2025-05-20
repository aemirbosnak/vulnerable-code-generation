//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

void generateMaze(int **maze, int w, int h)
{
    srand(time(NULL));

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    int numWalls = (w * h) / 5;
    for (int i = 0; i < numWalls; i++)
    {
        int x = rand() % w;
        int y = rand() % h;

        if (maze[y][x] == EMPTY)
        {
            maze[y][x] = WALL;
        }
    }

    maze[0][0] = START;
    maze[h - 1][w - 1] = END;
}

int main()
{
    int **maze = NULL;
    maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}