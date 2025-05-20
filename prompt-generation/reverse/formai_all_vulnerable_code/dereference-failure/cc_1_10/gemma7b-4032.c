//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGHT 50
#define MAX_WIDTH 50

void generateMaze(int **maze, int l, int w)
{
    int i, j, k, r, x, y;
    srand(time(NULL));

    // Allocate memory for the maze
    maze = (int **)malloc(l * sizeof(int *));
    for(i = 0; i < l; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int));
    }

    // Generate the maze
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    // Create the walls of the maze
    for(k = 0; k < 4; k++)
    {
        r = rand() % l;
        x = rand() % w;

        switch(k)
        {
            case 0:
                maze[r][x] = 1;
                break;
            case 1:
                maze[r][x] = 1;
                break;
            case 2:
                maze[r][x] = 1;
                break;
            case 3:
                maze[r][x] = 1;
                break;
        }
    }
}

int main()
{
    int **maze;
    int l = MAX_LENGHT;
    int w = MAX_WIDTH;

    generateMaze(maze, l, w);

    // Display the maze
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}