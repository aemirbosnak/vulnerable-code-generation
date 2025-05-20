//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a cell in the maze
typedef struct {
    int x, y; // Coordinates of the cell
    bool visited; // Flag to indicate if the cell has been visited
} Cell;

// Structure to represent the maze
typedef struct {
    int width, height; // Dimensions of the maze
    Cell** cells; // Array of cells representing the maze
} Maze;

// Create a new maze with the given dimensions
Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    // Allocate memory for the cells
    maze->cells = malloc(sizeof(Cell*) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(Cell) * width);
    }

    // Initialize the cells
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->cells[i][j].x = j;
            maze->cells[i][j].y = i;
            maze->cells[i][j].visited = false;
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j].visited) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Find a path from the start cell to the end cell in the maze using a recursive backtracking algorithm
bool findPath(Maze* maze, Cell* start, Cell* end) {
    // Mark the current cell as visited
    start->visited = true;

    // Check if the current cell is the end cell
    if (start->x == end->x && start->y == end->y) {
        return true;
    }

    // Try all possible moves from the current cell
    for (int i = 0; i < 4; i++) {
        int dx = 0, dy = 0;
        switch (i) {
            case 0: dx = -1; dy = 0; break; // Move left
            case 1: dx = 1; dy = 0; break; // Move right
            case 2: dx = 0; dy = -1; break; // Move up
            case 3: dx = 0; dy = 1; break; // Move down
        }

        // Check if the move is valid
        int nx = start->x + dx;
        int ny = start->y + dy;
        if (nx >= 0 && nx < maze->width && ny >= 0 && ny < maze->height && !maze->cells[ny][nx].visited) {
            // Recursively call findPath on the next cell
            if (findPath(maze, &maze->cells[ny][nx], end)) {
                return true;
            }
        }
    }

    // If no path was found, mark the current cell as unvisited and return false
    start->visited = false;
    return false;
}

// Main function
int main() {
    // Create a new maze
    Maze* maze = createMaze(10, 10);

    // Set the start and end cells
    Cell start = {0, 0};
    Cell end = {9, 9};

    // Find a path from the start cell to the end cell
    bool pathFound = findPath(maze, &start, &end);

    // Print the maze
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}