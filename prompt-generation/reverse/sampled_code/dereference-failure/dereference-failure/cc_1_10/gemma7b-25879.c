//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: authentic
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

#define WALL 1
#define EMPTY 0

int main()
{
    int x, y;
    int **maze = NULL;

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

    // Randomly place walls
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (rand() % 20 == 0)
            {
                maze[y][x] = WALL;
            }
        }
    }

    // Print the maze
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (y = 0; y < HEIGHT; y++)
    {
        free(maze[y]);
    }
    free(maze);

    return 0;
}