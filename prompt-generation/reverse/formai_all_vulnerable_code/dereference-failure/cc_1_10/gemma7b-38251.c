//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

void draw_maze(int **maze, int size)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (maze[y][x] == 1)
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
}

int main()
{
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 10;
    int **maze = malloc(size * sizeof(int *) + 1);
    for (int i = 0; i < size; i++)
    {
        maze[i] = malloc(size * sizeof(int) + 1);
    }

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            maze[y][x] = rand() % 2;
        }
    }

    draw_maze(maze, size);

    free(maze);

    return 0;
}