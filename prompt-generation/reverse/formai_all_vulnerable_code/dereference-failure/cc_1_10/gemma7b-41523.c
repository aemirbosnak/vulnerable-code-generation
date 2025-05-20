//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 0
#define EMPTY 1
#define PATH 2

int main()
{
    int **maze = NULL;
    int x, y, seed;

    // Allocate memory for the maze
    maze = (int**)malloc(HEIGHT * sizeof(int*));
    for (y = 0; y < HEIGHT; y++)
    {
        maze[y] = (int*)malloc(WIDTH * sizeof(int));
    }

    // Generate the seed
    seed = time(NULL);
    srand(seed);

    // Generate the maze
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    // Create the walls
    maze[0][0] = maze[0][WIDTH - 1] = WALL;
    maze[HEIGHT - 1][0] = maze[HEIGHT - 1][WIDTH - 1] = WALL;

    // Create the path
    maze[1][1] = PATH;
    maze[1][2] = PATH;
    maze[2][2] = PATH;
    maze[3][2] = PATH;

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