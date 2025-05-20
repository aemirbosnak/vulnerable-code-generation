//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int maze_route(int x, int y, int **maze, int **visited, int target_x, int target_y)
{
    if (x == target_x && y == target_y)
    {
        return 1;
    }

    if (visited[x][y] || maze[x][y] == 0)
    {
        return 0;
    }

    visited[x][y] = 1;

    // Recursively explore the north, south, east, west directions
    if (maze[x - 1][y] && maze_route(x - 1, y, maze, visited, target_x, target_y))
    {
        return 1;
    }
    if (maze[x + 1][y] && maze_route(x + 1, y, maze, visited, target_x, target_y))
    {
        return 1;
    }
    if (maze[x][y - 1] && maze_route(x, y - 1, maze, visited, target_x, target_y))
    {
        return 1;
    }
    if (maze[x][y + 1] && maze_route(x, y + 1, maze, visited, target_x, target_y))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int maze[] = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1 }
    };

    int visited[] = {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    int target_x = 2;
    int target_y = 2;

    if (maze_route(0, 0, maze, visited, target_x, target_y))
    {
        printf("Path found!\n");
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}