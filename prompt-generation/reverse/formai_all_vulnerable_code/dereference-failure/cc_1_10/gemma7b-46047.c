//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 15

#define EMPTY 0
#define WALL 1
#define PLAYER 2

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the maze
    int **maze = (int**)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Generate the maze
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    // Create the walls
    maze[0][0] = WALL;
    maze[0][WIDTH - 1] = WALL;
    maze[HEIGHT - 1][WIDTH - 1] = WALL;
    maze[HEIGHT - 1][0] = WALL;

    // Place the player
    maze[HEIGHT - 1][WIDTH / 2] = PLAYER;

    // Print the maze
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (maze[y][x])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PLAYER:
                    printf("P");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}