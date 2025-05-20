//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY_SPACE ' '
#define WALL 'W'
#define PLAYER 'P'

void generateMaze(int **maze, int width, int height)
{
    srand(time(NULL));
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            maze[y][x] = EMPTY_SPACE;
        }
    }

    int numWalls = (width * height) / 5;
    for (int i = 0; i < numWalls; i++)
    {
        int x = rand() % width;
        int y = rand() % height;
        if (maze[y][x] == EMPTY_SPACE)
        {
            maze[y][x] = WALL;
        }
    }

    maze[0][0] = PLAYER;
    maze[0][1] = WALL;
    maze[height - 1][width - 1] = WALL;
}

int main()
{
    int **maze = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generateMaze(maze, WIDTH, HEIGHT);

    // Print the maze
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    return 0;
}