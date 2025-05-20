//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

int main()
{
    int **maze = NULL;
    int x, y;

    // Allocate memory for the maze
    maze = malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        maze[y] = malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    // Create the walls
    maze[2][2] = WALL;
    maze[2][4] = WALL;
    maze[4][2] = WALL;
    maze[4][4] = WALL;

    // Print the maze
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(maze[y]);
    }
    free(maze);

    return 0;
}