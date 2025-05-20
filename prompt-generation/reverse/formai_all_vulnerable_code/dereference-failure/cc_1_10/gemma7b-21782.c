//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 11

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the maze
    int **maze = malloc(MAZE_HEIGHT * sizeof(int *));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = malloc(MAZE_WIDTH * sizeof(int));
    }

    // Generate the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            maze[y][x] = rand() % 2 ? WALL_CHAR : EMPTY_CHAR;
        }
    }

    // Place the player in the maze
    maze[5][5] = PLAYER_CHAR;

    // Draw the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}