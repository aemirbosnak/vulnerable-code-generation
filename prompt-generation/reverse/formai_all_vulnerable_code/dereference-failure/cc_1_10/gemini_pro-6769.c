//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
    int rows;
    int cols;
    char** grid;
} Maze;

// Create a new maze
Maze* createMaze(int rows, int cols) {
    Maze* maze = malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(sizeof(char) * cols);
    }
    return maze;
}

// Free the memory allocated for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

// Print the maze to the console
void printMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Solve the maze using a recursive backtracking algorithm
int solveMaze(Maze* maze, int row, int col) {
    // Check if we have reached the end of the maze
    if (row == maze->rows - 1 && col == maze->cols - 1) {
        return 1;
    }

    // Check if the current cell is a wall
    if (maze->grid[row][col] == '#') {
        return 0;
    }

    // Mark the current cell as visited
    maze->grid[row][col] = 'V';

    // Try all possible moves from the current cell
    int result = 0;
    if (row > 0) {
        result = solveMaze(maze, row - 1, col);
    }
    if (result == 0 && col < maze->cols - 1) {
        result = solveMaze(maze, row, col + 1);
    }
    if (result == 0 && row < maze->rows - 1) {
        result = solveMaze(maze, row + 1, col);
    }
    if (result == 0 && col > 0) {
        result = solveMaze(maze, row, col - 1);
    }

    // If we found a solution, return 1
    if (result == 1) {
        return 1;
    }

    // If we didn't find a solution, unmark the current cell as visited
    maze->grid[row][col] = ' ';

    // Return 0 to indicate that we didn't find a solution
    return 0;
}

// Main function
int main() {
    // Create a new maze
    Maze* maze = createMaze(5, 5);

    // Set the maze grid
    maze->grid[0][0] = 'S';
    maze->grid[0][1] = '#';
    maze->grid[0][2] = '#';
    maze->grid[0][3] = '#';
    maze->grid[0][4] = 'E';
    maze->grid[1][0] = '#';
    maze->grid[1][1] = ' ';
    maze->grid[1][2] = ' ';
    maze->grid[1][3] = ' ';
    maze->grid[1][4] = '#';
    maze->grid[2][0] = '#';
    maze->grid[2][1] = ' ';
    maze->grid[2][2] = '#';
    maze->grid[2][3] = ' ';
    maze->grid[2][4] = '#';
    maze->grid[3][0] = '#';
    maze->grid[3][1] = ' ';
    maze->grid[3][2] = '#';
    maze->grid[3][3] = ' ';
    maze->grid[3][4] = '#';
    maze->grid[4][0] = '#';
    maze->grid[4][1] = ' ';
    maze->grid[4][2] = '#';
    maze->grid[4][3] = ' ';
    maze->grid[4][4] = '#';

    // Print the maze to the console
    printMaze(maze);

    // Solve the maze
    int result = solveMaze(maze, 0, 0);

    // Print the result
    if (result == 1) {
        printf("Maze solved!\n");
    } else {
        printf("No solution found.\n");
    }

    // Free the memory allocated for the maze
    freeMaze(maze);

    return 0;
}