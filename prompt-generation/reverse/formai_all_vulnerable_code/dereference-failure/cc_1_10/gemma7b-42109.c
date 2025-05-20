//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generateMaze(int **maze, int w, int h)
{
    int x, y, i, j;
    srand(time(NULL));

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = rand() % 2;
        }
    }

    // Eliminate dead ends
    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            if (maze[i][j] == 0)
            {
                // Check if the cell is a corner cell
                if (i == 0 || j == 0 || i == w - 1 || j == h - 1)
                {
                    maze[i][j] = 1;
                }
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
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}