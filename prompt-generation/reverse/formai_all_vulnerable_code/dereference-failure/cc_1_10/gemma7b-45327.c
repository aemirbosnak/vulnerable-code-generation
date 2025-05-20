//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the maze
    char **maze = (char **)malloc(MAZE_HEIGHT * sizeof(char *));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (char *)malloc(MAZE_WIDTH * sizeof(char));
    }

    // Generate the walls
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            maze[y][x] = WALL_CHAR;
        }
    }

    // Create the passageways
    for (int i = 0; i < 10; i++)
    {
        int x1 = rand() % MAZE_WIDTH;
        int y1 = rand() % MAZE_HEIGHT;
        int x2 = rand() % MAZE_WIDTH;
        int y2 = rand() % MAZE_HEIGHT;

        if (x1 == x2)
        {
            maze[y1][x1] = EMPTY_CHAR;
            maze[y2][x2] = EMPTY_CHAR;
        }
        else if (y1 == y2)
        {
            maze[y1][x1] = EMPTY_CHAR;
            maze[y2][x2] = EMPTY_CHAR;
        }
    }

    // Print the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}