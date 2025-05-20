//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_L 10
#define MAX_W 10
#define MAX_B 10

#define EMPTY 0
#define WALL 1
#define PATH 2

void initializeMaze(int **maze, int l, int w)
{
    int i, j;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            maze[i][j] = EMPTY;
        }
    }
}

void generateMaze(int **maze, int l, int w)
{
    int i, j, r, c;
    srand(time(NULL));
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            r = rand() % MAX_B;
            c = rand() % MAX_B;
            if(maze[r][c] == EMPTY)
            {
                maze[r][c] = WALL;
            }
        }
    }
}

void printMaze(int **maze, int l, int w)
{
    int i, j;
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **maze;
    int l, w;

    printf("Enter the dimensions of the maze (l, w): ");
    scanf("%d %d", &l, &w);

    maze = (int **)malloc(l * sizeof(int *));
    for(int i = 0; i < l; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int));
    }

    initializeMaze(maze, l, w);
    generateMaze(maze, l, w);
    printMaze(maze, l, w);

    return 0;
}