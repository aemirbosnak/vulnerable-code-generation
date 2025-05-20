//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PATH 2

void generateMaze(int **maze, int w, int h)
{
    int i, j;
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create walls
    maze[0][0] = WALL;
    maze[0][1] = WALL;
    maze[1][0] = WALL;
    maze[1][1] = WALL;
    maze[h - 1][w - 1] = WALL;
    maze[h - 1][w - 2] = WALL;

    // Create the path
    maze[2][2] = PATH;
    maze[2][3] = PATH;
    maze[3][2] = PATH;
    maze[3][3] = PATH;
}

int main()
{
    int **maze;
    maze = (int **)malloc(HEIGHT * sizeof(int *));
    for(int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            switch(maze[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf("o");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}