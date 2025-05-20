//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void generateMaze(int **maze, int w, int h)
{
    int i, j, r, seed = time(NULL);
    srand(seed);

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int **maze, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
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
    for (int i = 0; i < h; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int) + w);
    }

    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    free(maze);

    return 0;
}