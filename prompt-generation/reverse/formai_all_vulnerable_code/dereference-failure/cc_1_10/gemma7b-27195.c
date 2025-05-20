//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

int main()
{
    time_t t;
    srand(t);

    int **maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for(int h = 0; h < MAZE_HEIGHT; h++)
    {
        maze[h] = (int*)malloc(MAZE_WIDTH * sizeof(int));
        for(int w = 0; w < MAZE_WIDTH; w++)
        {
            maze[h][w] = 0;
        }
    }

    // Generate the maze
    for(int h = 0; h < MAZE_HEIGHT; h++)
    {
        for(int w = 0; w < MAZE_WIDTH; w++)
        {
            if(rand() % 2 == 0)
            {
                maze[h][w] = 1;
            }
        }
    }

    // Draw the maze
    for(int h = 0; h < MAZE_HEIGHT; h++)
    {
        for(int w = 0; w < MAZE_WIDTH; w++)
        {
            if(maze[h][w] == 1)
            {
                printf("%c ", '#');
            }
            else
            {
                printf("%c ", '.');
            }
        }
        printf("\n");
    }

    free(maze);

    return 0;
}