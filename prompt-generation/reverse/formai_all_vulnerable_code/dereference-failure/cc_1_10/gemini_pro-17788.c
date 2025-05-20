//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

// Maze structure
struct Maze {
    char grid[MAZE_SIZE][MAZE_SIZE];
    int start_row;
    int start_col;
    int end_row;
    int end_col;
};

// Function to create a new maze
struct Maze* create_maze() {
    struct Maze* maze = (struct Maze*) malloc(sizeof(struct Maze));
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze->grid[i][j] = '#';
        }
    }
    maze->start_row = 0;
    maze->start_col = 0;
    maze->end_row = MAZE_SIZE - 1;
    maze->end_col = MAZE_SIZE - 1;
    return maze;
}

// Function to print the maze
void print_maze(struct Maze* maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid (not a wall)
bool is_valid_cell(struct Maze* maze, int row, int col) {
    return (row >= 0 && row < MAZE_SIZE && col >= 0 && col < MAZE_SIZE && maze->grid[row][col] != '#');
}

// Function to find a path from the start to the end of the maze using a recursive backtracking algorithm
bool find_path(struct Maze* maze, int row, int col) {
    // Check if we have reached the end of the maze
    if (row == maze->end_row && col == maze->end_col) {
        return true;
    }

    // Mark the current cell as visited
    maze->grid[row][col] = '*';

    // Try all possible moves from the current cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Check if the move is valid
            if (is_valid_cell(maze, row + i, col + j)) {
                // Recursively call the find_path function to try the move
                if (find_path(maze, row + i, col + j)) {
                    return true;
                }
            }
        }
    }

    // If no valid moves were found, mark the current cell as unvisited and return false
    maze->grid[row][col] = '#';
    return false;
}

int main() {
    // Create a new maze
    struct Maze* maze = create_maze();

    // Print the maze before solving it
    printf("Maze before solving:\n");
    print_maze(maze);

    // Find a path from the start to the end of the maze
    bool path_found = find_path(maze, maze->start_row, maze->start_col);

    // Print the maze after solving it
    printf("Maze after solving:\n");
    print_maze(maze);

    // Free the memory allocated for the maze
    free(maze);

    return 0;
}