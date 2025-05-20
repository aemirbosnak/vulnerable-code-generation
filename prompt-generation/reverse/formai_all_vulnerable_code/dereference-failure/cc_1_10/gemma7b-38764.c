//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **maze = NULL;
    int x, y, i, j, seed, wall_num = 0;

    // Allocate memory for the maze
    maze = malloc(WIDTH * HEIGHT * sizeof(int));
    if (maze == NULL)
    {
        return 1;
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Generate the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Print the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Count the number of walls
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (maze[i][j] == 1)
            {
                wall_num++;
            }
        }
    }

    // Print the number of walls
    printf("The number of walls is: %d\n", wall_num);

    // Free the memory allocated for the maze
    free(maze);

    return 0;
}