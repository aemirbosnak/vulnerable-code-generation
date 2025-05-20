//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze structure
typedef struct Maze {
    int width;
    int height;
    char** maze;
} Maze;

// Create a new maze
Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->maze = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        maze->maze[i] = malloc(sizeof(char) * width);
    }
    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->maze[i][j]);
        }
        printf("\n");
    }
}

// Check if the given position is valid
bool isValidPosition(Maze* maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->maze[y][x] != '#';
}

// Find the path from the start to the end of the maze using a depth-first search
bool findPath(Maze* maze, int x, int y, int endX, int endY) {
    // Check if we have reached the end of the maze
    if (x == endX && y == endY) {
        return true;
    }

    // Mark the current position as visited
    maze->maze[y][x] = '*';

    // Try to move in each of the four directions
    if (isValidPosition(maze, x + 1, y) && findPath(maze, x + 1, y, endX, endY)) {
        return true;
    }
    if (isValidPosition(maze, x - 1, y) && findPath(maze, x - 1, y, endX, endY)) {
        return true;
    }
    if (isValidPosition(maze, x, y + 1) && findPath(maze, x, y + 1, endX, endY)) {
        return true;
    }
    if (isValidPosition(maze, x, y - 1) && findPath(maze, x, y - 1, endX, endY)) {
        return true;
    }

    // If we cannot move in any direction, backtrack
    maze->maze[y][x] = ' ';
    return false;
}

// Main function
int main() {
    // Create a new maze
    Maze* maze = createMaze(10, 10);

    // Set the maze data
    maze->maze[0][0] = 'S'; // Start
    maze->maze[0][9] = 'E'; // End
    for (int i = 1; i < 9; i++) {
        maze->maze[i][0] = '#';
        maze->maze[i][9] = '#';
    }
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            maze->maze[i][j] = '.';
        }
    }

    // Print the maze
    printMaze(maze);

    // Find the path from the start to the end of the maze
    bool foundPath = findPath(maze, 0, 0, 9, 9);

    // Print the maze again with the path marked
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}