//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int maze_finder(int x, int y, int **maze, int **visited, int target_x, int target_y)
{
    // Base case: If the target position is reached, return 1
    if (x == target_x && y == target_y)
    {
        return 1;
    }

    // If the position has already been visited or the wall is encountered, return 0
    if (visited[x][y] || maze[x][y] == 0)
    {
        return 0;
    }

    // Mark the position as visited
    visited[x][y] = 1;

    // Recursively explore the four directions: up, down, right, left
    if (maze_finder(x - 1, y, maze, visited, target_x, target_y) ||
        maze_finder(x + 1, y, maze, visited, target_x, target_y) ||
        maze_finder(x, y - 1, maze, visited, target_x, target_y) ||
        maze_finder(x, y + 1, maze, visited, target_x, target_y))
    {
        return 1;
    }

    // If no path is found, return 0
    return 0;
}

int main()
{
    int maze[] = {{1, 0, 1, 0, 1},
                   {0, 1, 0, 1, 0},
                   {1, 0, 1, 0, 1},
                   {0, 1, 0, 1, 0},
                   {1, 0, 1, 0, 1}};

    int visited[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int target_x = 2;
    int target_y = 2;

    maze_finder(0, 0, maze, visited, target_x, target_y);

    return 0;
}