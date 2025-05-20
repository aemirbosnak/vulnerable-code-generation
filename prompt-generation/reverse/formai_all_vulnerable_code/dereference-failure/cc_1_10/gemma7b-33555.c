//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_CHAR '#'

void generate_maze(int **maze, int size)
{
    int x, y;

    // Allocate memory for the maze
    maze = malloc(size * size * sizeof(int));

    // Initialize the maze with walls
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            maze[x][y] = WALL_CHAR;
        }
    }

    // Create the maze passages
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (x > 0 && maze[x - 1][y] != WALL_CHAR)
                maze[x][y] = ' ';
            if (y > 0 && maze[x][y - 1] != WALL_CHAR)
                maze[x][y] = ' ';
        }
    }

    return;
}

int main()
{
    int **maze;
    int size = MAZE_SIZE;

    generate_maze(&maze, size);

    // Print the maze
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}