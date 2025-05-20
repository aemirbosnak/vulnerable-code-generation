//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, z;
    time_t t;
    t = time(NULL);
    srand(t);

    // Create a 5x5 maze
    int **maze = (int **)malloc(5 * sizeof(int *));
    for (x = 0; x < 5; x++)
    {
        maze[x] = (int *)malloc(5 * sizeof(int));
        for (y = 0; y < 5; y++)
        {
            maze[x][y] = 0;
        }
    }

    // Generate the maze
    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            if (rand() % 2)
            {
                maze[x][y] = 1;
            }
        }
    }

    // Print the maze
    for (x = 0; x < 5; x++)
    {
        for (y = 0; y < 5; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < 5; x++)
    {
        free(maze[x]);
    }
    free(maze);

    return 0;
}