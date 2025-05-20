//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define VISITED 2
#define START 3
#define END 4

void drawMaze(int **maze, int w, int h)
{
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            switch(maze[y][x])
            {
                case WALL:
                    printf("%c ", '#');
                    break;
                case EMPTY:
                    printf("%c ", '.');
                    break;
                case VISITED:
                    printf("%c ", '*');
                    break;
                case START:
                    printf("%c ", 'S');
                    break;
                case END:
                    printf("%c ", 'E');
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    maze = (int**)malloc(HEIGHT * sizeof(int *));
    for(int i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    srand(time(NULL));

    // Generate the maze
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    int numWalls = 50;
    for(int i = 0; i < numWalls; i++)
    {
        maze[rand() % HEIGHT][rand() % WIDTH] = WALL;
    }

    // Designate the start and end points
    maze[0][0] = START;
    maze[HEIGHT - 1][WIDTH - 1] = END;

    // Draw the maze
    drawMaze(maze, WIDTH, HEIGHT);

    return 0;
}