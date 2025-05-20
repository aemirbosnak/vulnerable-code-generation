//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void printMaze(int **maze, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int **maze = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(n * sizeof(int));
    }

    maze[2][2] = 1;
    maze[2][3] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;
    maze[4][2] = 1;

    printMaze(maze, n);

    int x = 0, y = 0, direction = 0;
    int target_x = 2, target_y = 3;

    while(x != target_x || y != target_y)
    {
        switch(direction)
        {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        if(maze[x][y] == 1)
        {
            direction = (direction + 1) % 4;
        }
    }

    printMaze(maze, n);

    free(maze);

    return 0;
}