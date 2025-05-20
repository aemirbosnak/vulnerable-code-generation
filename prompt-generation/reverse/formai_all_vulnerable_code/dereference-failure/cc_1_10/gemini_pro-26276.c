//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    char** grid;
} Maze;

// Create a new maze
Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    // Allocate memory for the grid
    maze->grid = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(sizeof(char) * width);
    }

    // Initialize the grid to all walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = '#';
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Check if the given coordinates are within the bounds of the maze
int isValid(Maze* maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height;
}

// Check if the given coordinates are a wall
int isWall(Maze* maze, int x, int y) {
    return maze->grid[y][x] == '#';
}

// Find the path through the maze using a depth-first search
int findPath(Maze* maze, int startX, int startY, int endX, int endY) {
    // Create a stack to store the coordinates of the path
    int stack[maze->width * maze->height][2];
    int top = -1;

    // Push the starting coordinates onto the stack
    stack[++top][0] = startX;
    stack[top][1] = startY;

    // While the stack is not empty
    while (top >= 0) {
        // Pop the top coordinates from the stack
        int x = stack[top][0];
        int y = stack[top--][1];

        // Check if the current coordinates are the end coordinates
        if (x == endX && y == endY) {
            return 1;
        }

        // Check if the current coordinates are a wall
        if (isWall(maze, x, y)) {
            continue;
        }

        // Mark the current coordinates as visited
        maze->grid[y][x] = '*';

        // Push the adjacent coordinates onto the stack
        if (isValid(maze, x + 1, y) && !isWall(maze, x + 1, y)) {
            stack[++top][0] = x + 1;
            stack[top][1] = y;
        }
        if (isValid(maze, x - 1, y) && !isWall(maze, x - 1, y)) {
            stack[++top][0] = x - 1;
            stack[top][1] = y;
        }
        if (isValid(maze, x, y + 1) && !isWall(maze, x, y + 1)) {
            stack[++top][0] = x;
            stack[top][1] = y + 1;
        }
        if (isValid(maze, x, y - 1) && !isWall(maze, x, y - 1)) {
            stack[++top][0] = x;
            stack[top][1] = y - 1;
        }
    }

    // No path was found
    return 0;
}

int main() {
    // Create a new maze
    Maze* maze = createMaze(10, 10);

    // Set the starting and ending coordinates
    int startX = 0;
    int startY = 0;
    int endX = 9;
    int endY = 9;

    // Find the path through the maze
    if (findPath(maze, startX, startY, endX, endY)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Print the maze to the console
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}