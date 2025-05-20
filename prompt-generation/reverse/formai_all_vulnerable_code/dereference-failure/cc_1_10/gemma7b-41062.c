//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void findMazeRoute(int **maze, int x, int y, int **visited, int targetX, int targetY) {
    if (x == targetX && y == targetY) {
        printf("Path found!");
        return;
    }

    if (visited[x][y] == 1) {
        return;
    }

    visited[x][y] = 1;

    // Explore up
    if (maze[x][y - 1] == 0 && visited[x][y - 1] == 0) {
        findMazeRoute(maze, x, y - 1, visited, targetX, targetY);
    }

    // Explore right
    if (maze[x + 1][y] == 0 && visited[x + 1][y] == 0) {
        findMazeRoute(maze, x + 1, y, visited, targetX, targetY);
    }

    // Explore down
    if (maze[x][y + 1] == 0 && visited[x][y + 1] == 0) {
        findMazeRoute(maze, x, y + 1, visited, targetX, targetY);
    }

    // Explore left
    if (maze[x - 1][y] == 0 && visited[x - 1][y] == 0) {
        findMazeRoute(maze, x - 1, y, visited, targetX, targetY);
    }
}

int main() {
    int maze[] = {
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    int visited[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}
                           };

    int targetX = 2;
    int targetY = 2;

    findMazeRoute(maze, 0, 0, visited, targetX, targetY);

    return 0;
}