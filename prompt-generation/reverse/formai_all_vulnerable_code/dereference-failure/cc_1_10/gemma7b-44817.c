//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void generateMaze(int **maze, int n, int m);
void printMaze(int **maze, int n, int m);

int main()
{
    int n, m;
    int **maze;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    generateMaze(maze, n, m);
    printMaze(maze, n, m);

    return 0;
}

void generateMaze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = rand() % MAX;
        }
    }
}

void printMaze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}