//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void createMaze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = 0;
        }
    }

    maze[n - 1][m - 1] = 1;
}

int main()
{
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);

    int x, y;
    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int found = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (maze[x][y] == 1)
            {
                found = 1;
                break;
            }

            x += dx[i];
            y += dy[j];
        }
    }

    if (found)
    {
        printf("Congratulations! You have found the end of the maze.\n");
    }
    else
    {
        printf("Sorry, you have not found the end of the maze.\n");
    }

    return 0;
}