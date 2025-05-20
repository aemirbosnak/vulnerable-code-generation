//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the maze
typedef struct {
    int x;
    int y;
    int visited;
} Cell;

// Structure to represent the maze
typedef struct {
    int width;
    int height;
    Cell **cells;
} Maze;

// Function to create a new maze
Maze *createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(Cell *) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            maze->cells[i][j].x = j;
            maze->cells[i][j].y = i;
            maze->cells[i][j].visited = 0;
        }
    }
    return maze;
}

// Function to free the memory allocated for the maze
void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Function to print the maze
void printMaze(Maze *maze) {
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

// Function to find a path from the start cell to the end cell in the maze
int findPath(Maze *maze, Cell *start, Cell *end) {
    // Check if the start and end cells are valid
    if (start->x < 0 || start->x >= maze->width ||
        start->y < 0 || start->y >= maze->height ||
        end->x < 0 || end->x >= maze->width ||
        end->y < 0 || end->y >= maze->height) {
        return 0;
    }

    // Check if the start and end cells are the same
    if (start->x == end->x && start->y == end->y) {
        return 1;
    }

    // Mark the start cell as visited
    maze->cells[start->y][start->x].visited = 1;

    // Check if there is a path to the north of the current cell
    if (start->y > 0 && !maze->cells[start->y - 1][start->x].visited) {
        if (findPath(maze, &maze->cells[start->y - 1][start->x], end)) {
            return 1;
        }
    }

    // Check if there is a path to the east of the current cell
    if (start->x < maze->width - 1 && !maze->cells[start->y][start->x + 1].visited) {
        if (findPath(maze, &maze->cells[start->y][start->x + 1], end)) {
            return 1;
        }
    }

    // Check if there is a path to the south of the current cell
    if (start->y < maze->height - 1 && !maze->cells[start->y + 1][start->x].visited) {
        if (findPath(maze, &maze->cells[start->y + 1][start->x], end)) {
            return 1;
        }
    }

    // Check if there is a path to the west of the current cell
    if (start->x > 0 && !maze->cells[start->y][start->x - 1].visited) {
        if (findPath(maze, &maze->cells[start->y][start->x - 1], end)) {
            return 1;
        }
    }

    // Unmark the start cell as visited
    maze->cells[start->y][start->x].visited = 0;

    // No path found
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze *maze = createMaze(10, 10);

    // Set the start and end cells
    Cell start = {0, 0};
    Cell end = {9, 9};

    // Find a path from the start cell to the end cell
    int pathFound = findPath(maze, &start, &end);

    // Print the maze
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    // Return 0 if a path was found, or 1 if no path was found
    return !pathFound;
}