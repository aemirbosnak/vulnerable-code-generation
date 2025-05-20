//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

int main()
{
    int x, y, i, j;
    int **maze = NULL;

    maze = (int **)malloc(HEIGHT * sizeof(int *));
    for(i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Generate the maze
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create the walls
    maze[0][0] = WALL;
    maze[0][1] = WALL;
    maze[1][0] = WALL;
    maze[1][1] = WALL;
    maze[HEIGHT - 1][WIDTH - 1] = WALL;
    maze[HEIGHT - 1][WIDTH - 2] = WALL;

    // Create the path
    maze[2][2] = PATH;
    maze[2][3] = PATH;
    maze[3][2] = PATH;

    // Print the maze
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}