//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void draw_maze(int **maze, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            switch (maze[r][c])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("#");
                    break;
                case 2:
                    printf("$");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX_SIZE;
    int **maze = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        maze[i] = (int *)malloc(size * sizeof(int));
    }

    srand(time(NULL));

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            maze[r][c] = rand() % 3;
        }
    }

    draw_maze(maze, size);

    free(maze);

    return 0;
}