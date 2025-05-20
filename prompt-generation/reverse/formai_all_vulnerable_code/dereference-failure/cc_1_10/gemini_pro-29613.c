//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maze struct
typedef struct {
    int width;
    int height;
    int **grid;
} Maze;

// Create a new maze
Maze *createMaze(int width, int height) {
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

// Solve a maze using a recursive backtracking algorithm
int solveMaze(Maze *maze, int x, int y) {
    // Check if we are at the end of the maze
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // Check if we can move in the current direction
    if (maze->grid[y][x] == 0) {
        return 0;
    }

    // Try all possible moves
    int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];

        // Check if the new move is valid
        if (newX >= 0 && newX < maze->width && newY >= 0 && newY < maze->height && maze->grid[newY][newX] == 1) {
            // Recursively solve the maze from the new position
            if (solveMaze(maze, newX, newY)) {
                // If the maze was solved, return true
                return 1;
            }
        }
    }

    // If no valid moves were found, return false
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze *maze = createMaze(10, 10);

    // Initialize the maze with some walls
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->grid[i][j] = rand() % 2;
        }
    }

    // Print the maze to the console
    printf("Maze:\n");
    printMaze(maze);

    // Solve the maze
    int solved = solveMaze(maze, 0, 0);

    // Print the solution to the console
    if (solved) {
        printf("Solved!\n");
    } else {
        printf("No solution found.\n");
    }

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}