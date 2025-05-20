//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

void generateMaze(int **maze, int w, int h)
{
    int x, y, i, j;
    srand(time(NULL));

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = EMPTY;
        }
    }

    // Create walls
    for (i = 0; i < 10; i++)
    {
        x = rand() % w;
        y = rand() % h;
        maze[x][y] = WALL;
    }

    // Create the path
    x = rand() % w;
    y = rand() % h;
    maze[x][y] = PATH;
}

int main()
{
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

    maze = (int *)malloc(w * h * sizeof(int));
    generateMaze(maze, w, h);

    // Print the maze
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}