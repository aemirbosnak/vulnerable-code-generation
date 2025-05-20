//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int x, y, i, j, r, w, h;
    int **maze = NULL;

    // Allocate memory for the maze
    maze = malloc(HEIGHT * sizeof(int *) + WIDTH * sizeof(int));
    for (h = 0; h < HEIGHT; h++)
    {
        maze[h] = malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    w = WIDTH;
    h = HEIGHT;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Print the maze
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (h = 0; h < HEIGHT; h++)
    {
        free(maze[h]);
    }
    free(maze);

    return 0;
}