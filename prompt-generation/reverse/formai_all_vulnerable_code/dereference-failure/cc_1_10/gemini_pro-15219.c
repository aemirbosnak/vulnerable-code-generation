//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a cell in the maze
typedef struct Cell {
    int x;
    int y;
    bool visited;
} Cell;

// Structure to represent the maze
typedef struct Maze {
    Cell cells[MAX_SIZE][MAX_SIZE];
    int width;
    int height;
} Maze;

// Function to create a new maze
Maze* createMaze(int width, int height) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    // Initialize all cells to be unvisited
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i][j].visited = false;
        }
    }

    return maze;
}

// Function to print the maze
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            if (maze->cells[i][j].visited) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to find a path through the maze using a depth-first search
bool findPath(Maze* maze, Cell* start, Cell* end) {
    // Mark the starting cell as visited
    start->visited = true;

    // Check if the starting cell is the ending cell
    if (start->x == end->x && start->y == end->y) {
        return true;
    }

    // Recursively check each of the four neighboring cells
    if (start->x > 0 && !maze->cells[start->x - 1][start->y].visited && findPath(maze, &maze->cells[start->x - 1][start->y], end)) {
        return true;
    }
    if (start->x < maze->width - 1 && !maze->cells[start->x + 1][start->y].visited && findPath(maze, &maze->cells[start->x + 1][start->y], end)) {
        return true;
    }
    if (start->y > 0 && !maze->cells[start->x][start->y - 1].visited && findPath(maze, &maze->cells[start->x][start->y - 1], end)) {
        return true;
    }
    if (start->y < maze->height - 1 && !maze->cells[start->x][start->y + 1].visited && findPath(maze, &maze->cells[start->x][start->y + 1], end)) {
        return true;
    }

    // If no path was found, mark the starting cell as unvisited and return false
    start->visited = false;
    return false;
}

int main() {
    // Create a new maze
    Maze* maze = createMaze(10, 10);

    // Set the starting and ending cells
    Cell start = {0, 0};
    Cell end = {9, 9};

    // Find a path through the maze
    bool foundPath = findPath(maze, &start, &end);

    // Print the maze
    printMaze(maze);

    // Print a message indicating whether a path was found
    if (foundPath) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}