//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    int **grid;
} Maze;

// Create a new maze
Maze* createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the memory allocated for a maze
void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

// Print a maze to the console
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Solve a maze using a depth-first search
int solveMaze(Maze *maze, int x, int y) {
    // Check if we have reached the end of the maze
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // Mark the current cell as visited
    maze->grid[y][x] = 2;

    // Try all possible moves from the current cell
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Check if the next move is valid
        if (nextX >= 0 && nextX < maze->width && nextY >= 0 && nextY < maze->height && maze->grid[nextY][nextX] == 0) {
            // Try the next move
            if (solveMaze(maze, nextX, nextY)) {
                return 1;
            }
        }
    }

    // No valid moves from the current cell, so backtrack
    maze->grid[y][x] = 0;
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze *maze = createMaze(10, 10);

    // Set the maze walls
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (i == 0 || i == maze->height - 1 || j == 0 || j == maze->width - 1) {
                maze->grid[i][j] = 1;
            }
        }
    }

    // Print the maze
    printMaze(maze);

    // Solve the maze
    int solution = solveMaze(maze, 0, 0);

    // Print the solution
    if (solution) {
        printf("Maze solved!\n");
    } else {
        printf("Maze unsolvable.\n");
    }

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}