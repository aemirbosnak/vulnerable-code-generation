//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main()
{
    int x, y, size, **maze, i, j, r, c;

    // Generate random size between 5 and MAX_SIZE
    size = rand() % (MAX_SIZE - 5) + 5;

    // Allocate memory for the maze
    maze = (int *)malloc(size * size * sizeof(int));

    // Initialize the maze
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Create the maze
    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            // Probability to create a wall
            if (rand() % 20 == 0)
            {
                maze[r][c] = 1;
            }
        }
    }

    // Print the maze
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(maze);

    return 0;
}