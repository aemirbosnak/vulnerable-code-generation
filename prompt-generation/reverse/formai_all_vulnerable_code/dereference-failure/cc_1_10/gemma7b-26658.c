//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void maze_finder(int **maze, int x, int y)
{
    if (maze[x][y] == 2)
    {
        printf("Congratulations! You have reached the treasure!\n");
        return;
    }
    else if (maze[x][y] == 1)
    {
        return;
    }
    else
    {
        maze[x][y] = 1;
        maze_finder(maze, x - 1, y);  // Left
        maze_finder(maze, x, y - 1);  // Up
        maze_finder(maze, x + 1, y);  // Right
        maze_finder(maze, x, y + 1);  // Down
    }
}

int main()
{
    int maze[MAX][MAX] = {{1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
                           1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
                           1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
                           1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
                           1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
                        };

    maze_finder(maze, 0, 0);

    return 0;
}