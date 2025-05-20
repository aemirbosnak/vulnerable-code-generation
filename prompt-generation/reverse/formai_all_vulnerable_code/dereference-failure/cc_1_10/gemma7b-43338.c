//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h)
{
    int x, y;
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = EMPTY_CHAR;
        }
    }

    // Create walls
    maze[0][0] = WALL_CHAR;
    maze[0][h - 1] = WALL_CHAR;
    maze[w - 1][0] = WALL_CHAR;
    maze[w - 1][h - 1] = WALL_CHAR;

    // Randomly create passages
    for (x = 1; x < w - 1; x++)
    {
        for (y = 1; y < h - 1; y++)
        {
            if (rand() % 2 == 0)
            {
                maze[x][y] = EMPTY_CHAR;
            }
        }
    }
}

int main()
{
    int **maze;
    maze = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        maze[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    // Print the maze
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}