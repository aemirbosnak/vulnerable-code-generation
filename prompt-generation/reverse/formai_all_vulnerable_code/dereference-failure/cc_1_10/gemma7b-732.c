//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void find_route(int x, int y, int **maze, int **visited, int target_x, int target_y)
{
    if (x == target_x && y == target_y)
    {
        printf("Congratulations! You have found the target.\n");
        return;
    }

    if (visited[x][y] == 1)
    {
        return;
    }

    visited[x][y] = 1;

    if (maze[x][y] == 1)
    {
        return;
    }

    find_route(x - 1, y, maze, visited, target_x, target_y);
    find_route(x + 1, y, maze, visited, target_x, target_y);
    find_route(x, y - 1, maze, visited, target_x, target_y);
    find_route(x, y + 1, maze, visited, target_x, target_y);
}

int main()
{
    int maze[] = {
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    int visited[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int target_x = 2;
    int target_y = 2;

    find_route(0, 0, maze, visited, target_x, target_y);

    return 0;
}