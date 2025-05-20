//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    char **grid;
} Maze;

// Load a maze from a file
Maze* loadMaze(char *filename) {
    Maze *maze = malloc(sizeof(Maze));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the maze dimensions
    fscanf(file, "%d %d\n", &maze->width, &maze->height);

    // Allocate memory for the maze grid
    maze->grid = malloc(sizeof(char *) * maze->height);
    for (int i = 0; i < maze->height; i++) {
        maze->grid[i] = malloc(sizeof(char) * maze->width);
    }

    // Read the maze grid
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            fscanf(file, "%c", &maze->grid[i][j]);
        }
        fscanf(file, "\n");
    }

    fclose(file);

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
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Find a path through a maze using a recursive depth-first search
bool findPath(Maze *maze, int x, int y) {
    // Check if we have reached the goal
    if (maze->grid[y][x] == 'G') {
        return true;
    }

    // Mark the current cell as visited
    maze->grid[y][x] = 'V';

    // Try all possible directions
    if (x > 0 && maze->grid[y][x - 1] != 'W') {
        if (findPath(maze, x - 1, y)) {
            return true;
        }
    }
    if (y > 0 && maze->grid[y - 1][x] != 'W') {
        if (findPath(maze, x, y - 1)) {
            return true;
        }
    }
    if (x < maze->width - 1 && maze->grid[y][x + 1] != 'W') {
        if (findPath(maze, x + 1, y)) {
            return true;
        }
    }
    if (y < maze->height - 1 && maze->grid[y + 1][x] != 'W') {
        if (findPath(maze, x, y + 1)) {
            return true;
        }
    }

    // If no path was found, mark the current cell as unvisited
    maze->grid[y][x] = 'U';

    return false;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a maze file was specified
    if (argc != 2) {
        printf("Usage: %s <maze file>\n", argv[0]);
        return 1;
    }

    // Load the maze from the file
    Maze *maze = loadMaze(argv[1]);

    // Find a path through the maze
    bool pathFound = findPath(maze, 0, 0);

    // Print the maze with the path
    printMaze(maze);

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}