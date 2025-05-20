//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void solveMaze(int **maze, int x, int y, int **visited, int targetX, int targetY) {
    // Base case
    if (x == targetX && y == targetY) {
        printf("Path found!\n");
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Check the four directions
    if (maze[x - 1][y] && !visited[x - 1][y]) {
        solveMaze(maze, x - 1, y, visited, targetX, targetY);
    }
    if (maze[x][y - 1] && !visited[x][y - 1]) {
        solveMaze(maze, x, y - 1, visited, targetX, targetY);
    }
    if (maze[x + 1][y] && !visited[x + 1][y]) {
        solveMaze(maze, x + 1, y, visited, targetX, targetY);
    }
    if (maze[x][y + 1] && !visited[x][y + 1]) {
        solveMaze(maze, x, y + 1, visited, targetX, targetY);
    }
}

int main() {
    int **maze = NULL;
    int x, y, targetX, targetY;

    // Create a maze
    maze = (int **)malloc(5 * sizeof(int *));
    for (x = 0; x < 5; x++) {
        maze[x] = (int *)malloc(5 * sizeof(int));
    }

    // Set the maze
    maze[2][2] = 1;
    maze[2][3] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;
    maze[4][2] = 1;
    maze[4][3] = 1;

    // Set the target position
    targetX = 4;
    targetY = 3;

    // Create a visited array
    int **visited = NULL;
    visited = (int **)malloc(5 * sizeof(int *));
    for (x = 0; x < 5; x++) {
        visited[x] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the visited array
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            visited[x][y] = 0;
        }
    }

    // Solve the maze
    solveMaze(maze, 2, 2, visited, targetX, targetY);

    return 0;
}