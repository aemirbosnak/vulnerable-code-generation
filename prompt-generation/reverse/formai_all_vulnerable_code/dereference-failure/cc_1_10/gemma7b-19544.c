//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h)
{
    int x, y;

    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            maze[x][y] = EMPTY_CHAR;
        }
    }

    // Generate random walls
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (rand() % 20 == 0)
            {
                maze[x][y] = WALL_CHAR;
            }
        }
    }
}

int main()
{
    int **maze;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int *)malloc(w * h * sizeof(int));
    maze[0] = (int *)malloc(w * sizeof(int));

    generate_maze(maze, w, h);

    // Print the maze
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    free(maze[0]);
    free(maze);

    return 0;
}