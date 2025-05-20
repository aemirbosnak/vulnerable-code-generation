//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void drawMaze(int **maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c ", maze[i][j] ? '#': '.');
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int m = 5;
    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
    }

    // Build the maze
    maze[2][2] = 1;
    maze[2][3] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;

    drawMaze(maze, n, m);

    // Find the route
    int x = 0, y = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int found = 0;

    while (!found)
    {
        // Move in a direction
        int i = dx[rand() % 4];
        int j = dy[rand() % 4];

        // If the cell is not a wall and the route has not been found
        if (maze[x + i][y + j] == 0 && maze[x + i][y + j] != 2)
        {
            // Mark the cell as visited
            maze[x + i][y + j] = 2;

            // Move to the next cell
            x += i;
            y += j;

            // If the route has been found
            if (x == n - 1 && y == m - 1)
            {
                found = 1;
            }
        }
    }

    drawMaze(maze, n, m);

    free(maze);

    return 0;
}