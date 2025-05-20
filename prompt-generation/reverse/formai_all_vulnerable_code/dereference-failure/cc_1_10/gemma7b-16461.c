//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h)
{
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            maze[y][x] = EMPTY_CHAR;
        }
    }

    // Generate walls
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(x == 0)
            {
                maze[y][x] = WALL_CHAR;
            }
            else if(x == w - 1)
            {
                maze[y][x] = WALL_CHAR;
            }
            else if(y == 0)
            {
                maze[y][x] = WALL_CHAR;
            }
            else if(y == h - 1)
            {
                maze[y][x] = WALL_CHAR;
            }
        }
    }

    // Create passages
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(rand() % 20 == 0)
            {
                maze[y][x] = EMPTY_CHAR;
            }
        }
    }
}

int main()
{
    int **maze = NULL;
    int w, h;

    printf("Enter the width of the maze: ");
    scanf("%d", &w);

    printf("Enter the height of the maze: ");
    scanf("%d", &h);

    maze = (int **)malloc(h * sizeof(int *) + h);
    for(int i = 0; i < h; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int) + w);
    }

    generateMaze(maze, w, h);

    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    return 0;
}