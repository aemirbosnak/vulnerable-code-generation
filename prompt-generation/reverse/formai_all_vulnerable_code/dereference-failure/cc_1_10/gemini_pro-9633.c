//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
    int **maze;
    int width;
    int height;
} Maze;

// Create a new maze
Maze *createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->maze = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->maze[i] = malloc(sizeof(int) * width);
    }
    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Find a path through the maze using a recursive backtracking algorithm
int findPath(Maze *maze, int x, int y) {
    // Check if we are at the exit of the maze
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // Check if we are at a valid position in the maze
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return 0;
    }

    // Check if the current position is a wall
    if (maze->maze[y][x] == 1) {
        return 0;
    }

    // Mark the current position as visited
    maze->maze[y][x] = 2;

    // Try all possible moves from the current position
    if (findPath(maze, x + 1, y)) {
        return 1;
    }
    if (findPath(maze, x - 1, y)) {
        return 1;
    }
    if (findPath(maze, x, y + 1)) {
        return 1;
    }
    if (findPath(maze, x, y - 1)) {
        return 1;
    }

    // If no valid moves were found, backtrack by marking the current position as unvisited
    maze->maze[y][x] = 0;
    return 0;
}

// Main function
int main() {
    // Create a maze
    Maze *maze = createMaze(10, 10);

    // Initialize the maze with walls and open spaces
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (i == 0 || i == maze->height - 1 || j == 0 || j == maze->width - 1) {
                maze->maze[i][j] = 1;
            } else {
                maze->maze[i][j] = 0;
            }
        }
    }

    // Print the maze to the console
    printMaze(maze);

    // Find a path through the maze
    int success = findPath(maze, 0, 0);

    // Print the result
    if (success) {
        printf("A path was found through the maze.\n");
    } else {
        printf("No path was found through the maze.\n");
    }

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}