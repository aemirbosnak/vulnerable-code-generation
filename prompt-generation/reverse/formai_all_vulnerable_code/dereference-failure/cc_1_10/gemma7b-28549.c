//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 10x10 grid
    int **maze = malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        maze[i] = malloc(10 * sizeof(int));
        for (int j = 0; j < 10; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Dig a random path
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rand() % 2 == 0)
            {
                maze[i][j] = 1;
            }
        }
    }

    // Draw the maze
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("%c", '#');
            }
            else
            {
                printf("%c", '.');
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}