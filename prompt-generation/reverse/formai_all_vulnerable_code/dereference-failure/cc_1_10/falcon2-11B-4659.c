//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the maze
void printMaze(int** maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze
int** generateMaze(int rows, int cols) {
    int** maze = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the maze with 0s
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 0;
        }
    }

    // Start from a random point and generate the maze
    int x = 0;
    int y = 0;
    int** visited = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    visited[x][y] = 1;

    while (x!= rows - 1 || y!= cols - 1) {
        int nx = x + 1;
        int ny = y + 1;

        // Check if the neighbor is valid and not visited
        if (nx < rows && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
            maze[x][y] = 1;
            visited[nx][ny] = 1;
            x = nx;
        }

        nx = x - 1;
        ny = y + 1;
        if (nx >= 0 && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
            maze[x][y] = 1;
            visited[nx][ny] = 1;
            x = nx;
        }

        nx = x - 1;
        ny = y - 1;
        if (nx >= 0 && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
            maze[x][y] = 1;
            visited[nx][ny] = 1;
            x = nx;
        }

        nx = x + 1;
        ny = y - 1;
        if (nx < rows && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
            maze[x][y] = 1;
            visited[nx][ny] = 1;
            x = nx;
        }
    }

    return maze;
}

int main() {
    int rows = 10;
    int cols = 10;
    int** maze = generateMaze(rows, cols);
    printMaze(maze, rows, cols);
    free(maze);
    return 0;
}