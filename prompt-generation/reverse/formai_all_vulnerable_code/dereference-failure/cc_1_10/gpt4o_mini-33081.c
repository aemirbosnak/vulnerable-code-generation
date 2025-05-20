//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5 // Size of the maze (N x N)

// Function prototypes
void printMaze(int** maze, int n);
bool isSafe(int** maze, int x, int y, bool** visited);
bool solveMaze(int** maze, int x, int y, int** solution);
bool findPath(int** maze);

int main() {
    // Dynamic allocation of the maze
    int** maze = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        maze[i] = (int*)malloc(N * sizeof(int));
    }

    // Initialize the maze
    int tempMaze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };
    
    // Copy tempMaze to maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maze[i][j] = tempMaze[i][j];
        }
    }

    printf("Maze:\n");
    printMaze(maze, N);

    if (!findPath(maze)) {
        printf("No path exists\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}

void printMaze(int** maze, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Check if x, y is valid index for N*N maze
bool isSafe(int** maze, int x, int y, bool** visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(int** maze, int x, int y, int** solution) {
    // If (x, y) is the bottom-right corner
    if (x == N-1 && y == N-1) {
        solution[x][y] = 1;
        printMaze(solution, N);
        return true;
    }

    // Check if current position is valid
    if (isSafe(maze, x, y, solution)) {
        // Mark x, y as part of solution path
        solution[x][y] = 1;

        // Move forward in x direction
        if (solveMaze(maze, x + 1, y, solution)) {
            return true;
        }

        // If moving in x direction doesn't work then move down in y direction
        if (solveMaze(maze, x, y + 1, solution)) {
            return true;
        }

        // If none of the above movements work then backtrack
        solution[x][y] = 0;
        return false;
    }
    return false;
}

bool findPath(int** maze) {
    // Solution path
    int** solution = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        solution[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            solution[i][j] = 0; // Initialize all to 0
        }
    }

    if (!solveMaze(maze, 0, 0, solution)) {
        printf("No solution found!\n");
        return false;
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(solution[i]);
    }
    free(solution);

    return true;
}