//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the maze
typedef struct Cell {
    int x;
    int y;
    int visited;
} Cell;

// Structure to represent the maze
typedef struct Maze {
    int width;
    int height;
    Cell** cells;
} Maze;

// Function to create a new maze
Maze* createMaze(int width, int height) {
    Maze* maze = (Maze*) malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = (Cell**) malloc(sizeof(Cell*) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = (Cell*) malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            maze->cells[i][j].x = j;
            maze->cells[i][j].y = i;
            maze->cells[i][j].visited = 0;
        }
    }
    return maze;
}

// Function to free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Function to print the maze
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j].visited) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to find a path through the maze
int findPath(Maze* maze, Cell* start, Cell* end) {
    // Check if the starting cell is valid
    if (start->x < 0 || start->y < 0 || start->x >= maze->width || start->y >= maze->height) {
        return 0;
    }

    // Check if the ending cell is valid
    if (end->x < 0 || end->y < 0 || end->x >= maze->width || end->y >= maze->height) {
        return 0;
    }

    // Mark the starting cell as visited
    maze->cells[start->y][start->x].visited = 1;

    // If the starting cell is the ending cell, then we have found a path
    if (start->x == end->x && start->y == end->y) {
        return 1;
    }

    // Try to find a path to the north
    if (start->y > 0 && maze->cells[start->y - 1][start->x].visited == 0) {
        if (findPath(maze, &maze->cells[start->y - 1][start->x], end)) {
            return 1;
        }
    }

    // Try to find a path to the east
    if (start->x < maze->width - 1 && maze->cells[start->y][start->x + 1].visited == 0) {
        if (findPath(maze, &maze->cells[start->y][start->x + 1], end)) {
            return 1;
        }
    }

    // Try to find a path to the south
    if (start->y < maze->height - 1 && maze->cells[start->y + 1][start->x].visited == 0) {
        if (findPath(maze, &maze->cells[start->y + 1][start->x], end)) {
            return 1;
        }
    }

    // Try to find a path to the west
    if (start->x > 0 && maze->cells[start->y][start->x - 1].visited == 0) {
        if (findPath(maze, &maze->cells[start->y][start->x - 1], end)) {
            return 1;
        }
    }

    // No path found, backtrack
    maze->cells[start->y][start->x].visited = 0;
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze* maze = createMaze(10, 10);

    // Set the starting and ending cells
    Cell start = {0, 0};
    Cell end = {9, 9};

    // Find a path through the maze
    int foundPath = findPath(maze, &start, &end);

    // Print the maze
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}