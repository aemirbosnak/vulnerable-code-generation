//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdlib.h>
#include <time.h>

void generateMaze(int size)
{
    int **maze = malloc(size * size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the maze
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = rand() % 2;
            }
        }
    }

    // Print the maze
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);
}

int main()
{
    generateMaze(5);
    return 0;
}