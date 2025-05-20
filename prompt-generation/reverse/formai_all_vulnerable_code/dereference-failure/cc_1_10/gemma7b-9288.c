//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int x, y, i, j, wall_num = 0, seed = 12;
    int **maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    srand(seed);

    // Generate walls randomly
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (rand() % 2 == 0)
            {
                maze[i][j] = 1;
                wall_num++;
            }
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

    printf("Total number of walls: %d\n", wall_num);

    // Free memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}