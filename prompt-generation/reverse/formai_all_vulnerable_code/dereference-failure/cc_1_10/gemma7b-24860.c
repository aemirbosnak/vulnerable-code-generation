//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h)
{
    int x, y;

    // Allocate memory for the maze
    maze = malloc(w * h * sizeof(int));
    for (x = 0; x < w * h; x++)
    {
        maze[x] = malloc(sizeof(int));
        maze[x][0] = 0;
    }

    // Generate random walls
    srand(time(NULL));
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (rand() % 2 == 0)
            {
                maze[x][y] = WALL_CHAR;
            }
        }
    }

    // Mark the start and end points
    maze[0][0] = EMPTY_CHAR;
    maze[w - 1][h - 1] = EMPTY_CHAR;
}

int main()
{
    int **maze;
    generate_maze(&maze, MAZE_WIDTH, MAZE_HEIGHT);

    // Print the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    return 0;
}