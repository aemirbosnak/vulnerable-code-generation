//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    srand(time(NULL));

    int **maze = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            maze[y][x] = rand() % 2;
        }
    }

    // Draw the maze
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (maze[y][x] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}