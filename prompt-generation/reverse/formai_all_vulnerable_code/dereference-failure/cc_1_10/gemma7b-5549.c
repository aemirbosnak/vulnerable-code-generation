//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct Maze {
    int rows;
    int cols;
    int **grid;
} Maze;

// Create a maze
Maze *createMaze(int rows, int cols) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) {
        maze->grid[r] = (int *)malloc(cols * sizeof(int));
    }
    return maze;
}

// Print the maze
void printMaze(Maze *maze) {
    for (int r = 0; r < maze->rows; r++) {
        for (int c = 0; c < maze->cols; c++) {
            printf("%d ", maze->grid[r][c]);
        }
        printf("\n");
    }
}

// Find the route in the maze
int findRoute(Maze *maze, int x, int y) {
    // If the position is out of bounds or the cell is blocked, return -1
    if (x < 0 || x >= maze->rows || y < 0 || y >= maze->cols || maze->grid[x][y] == 1) {
        return -1;
    }

    // If the position is the goal, return 0
    if (maze->grid[x][y] == 2) {
        return 0;
    }

    // Mark the position as visited and move to the next cell
    maze->grid[x][y] = 3;

    // Find the route in the four directions
    int direction[] = {0, 1, 0, -1};
    for (int d = 0; d < 4; d++) {
        int nx = x + direction[d];
        int ny = y + direction[d];
        if (findRoute(maze, nx, ny) == 0) {
            return 0;
        }
    }

    // If no route is found, return -1
    return -1;
}

int main() {
    // Create a maze
    Maze *maze = createMaze(5, 5);

    // Print the maze
    printMaze(maze);

    // Find the route in the maze
    findRoute(maze, 0, 0);

    // Print the maze after finding the route
    printMaze(maze);

    return 0;
}