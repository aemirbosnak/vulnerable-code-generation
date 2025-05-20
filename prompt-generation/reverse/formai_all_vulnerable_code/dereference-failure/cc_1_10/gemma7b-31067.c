//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

void generate_maze(int **maze, int w, int h)
{
    srand(time(NULL));
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            maze[r][c] = EMPTY;
        }
    }

    int num_walls = (w * h) / 5;
    for (int i = 0; i < num_walls; i++)
    {
        int r = rand() % h;
        int c = rand() % w;
        if (maze[r][c] == EMPTY)
        {
            maze[r][c] = WALL;
        }
    }
}

int main()
{
    int **maze = NULL;
    maze = (int**)malloc(MAZE_HEIGHT * sizeof(int *));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    generate_maze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    for (int r = 0; r < MAZE_HEIGHT; r++)
    {
        for (int c = 0; c < MAZE_WIDTH; c++)
        {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }

    return 0;
}