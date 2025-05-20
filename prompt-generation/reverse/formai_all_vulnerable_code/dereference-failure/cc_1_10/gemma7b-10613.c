//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the maze
    char **maze = (char**)malloc(MAZE_HEIGHT * sizeof(char*));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (char*)malloc(MAZE_WIDTH * sizeof(char));
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            maze[i][j] = EMPTY_CHAR;
        }
    }

    // Generate the walls
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            if (rand() % 2 == 0)
            {
                maze[i][j] = WALL_CHAR;
            }
        }
    }

    // Place the player
    maze[20][20] = PLAYER_CHAR;

    // Print the maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}