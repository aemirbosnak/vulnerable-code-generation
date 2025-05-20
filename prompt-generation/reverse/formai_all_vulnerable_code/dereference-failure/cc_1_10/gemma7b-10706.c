//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

int main()
{
    srand(time(NULL));

    int **maze = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        maze[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create walls
    maze[10][10] = WALL;
    maze[10][12] = WALL;
    maze[12][10] = WALL;
    maze[12][12] = WALL;

    // Create the path
    maze[5][5] = PATH;
    maze[5][6] = PATH;
    maze[6][5] = PATH;
    maze[6][6] = PATH;

    // Draw the maze
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            switch (maze[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf(".");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}