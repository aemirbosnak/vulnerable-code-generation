//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: genius
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generate_maze(int **maze, int w, int h)
{
    int x, y;

    // Allocate memory for the maze
    maze = malloc(h * sizeof(int *));
    for (y = 0; y < h; y++)
    {
        maze[y] = malloc(w * sizeof(int));
    }

    // Initialize the maze with walls
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            maze[y][x] = WALL_CHAR;
        }
    }

    // Create a random path
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (rand() % 2 == 0)
            {
                maze[y][x] = EMPTY_CHAR;
            }
        }
    }
}

int main()
{
    int **maze;
    int w, h;

    w = WIDTH;
    h = HEIGHT;

    generate_maze(&maze, w, h);

    // Print the maze
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            printf("%c ", maze[h][w]);
        }
        printf("\n");
    }

    return 0;
}