//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL 1
#define EMPTY 0

int main()
{
    int **maze = NULL;
    int i, j, r, seed;

    // Allocate memory for the maze
    maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Generate the maze
    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        for (j = 0; j < MAZE_WIDTH; j++)
        {
            maze[i][j] = EMPTY;
            r = rand() % 2;
            if (r == 0)
            {
                maze[i][j] = WALL;
            }
        }
    }

    // Print the maze
    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        for (j = 0; j < MAZE_WIDTH; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}