//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 21
#define HEIGHT 21

#define EMPTY 0
#define WALL 1
#define PATH 2

int main()
{
    int **maze = (int **)malloc(HEIGHT * sizeof(int *)), *maze_row, i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Generate the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create the walls
    maze[0][0] = maze[0][WIDTH - 1] = WALL;
    maze[HEIGHT - 1][0] = maze[HEIGHT - 1][WIDTH - 1] = WALL;

    // Create the path
    maze[5][5] = PATH;

    // Print the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}