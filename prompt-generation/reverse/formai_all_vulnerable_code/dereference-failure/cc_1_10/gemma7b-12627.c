//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

#define EMPTY 0
#define WALL 1
#define PLAYER 2

void createMaze(int **maze, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    int numWalls = 50;
    for (int i = 0; i < numWalls; i++)
    {
        int x = rand() % w;
        int y = rand() % h;

        if (maze[y][x] == EMPTY)
        {
            maze[y][x] = WALL;
        }
    }

    maze[0][0] = PLAYER;
}

int main()
{
    int **maze = NULL;
    maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    createMaze(maze, WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (maze[y][x])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PLAYER:
                    printf("P");
                    break;
            }
        }
        printf("\n");
    }

    free(maze);

    return 0;
}