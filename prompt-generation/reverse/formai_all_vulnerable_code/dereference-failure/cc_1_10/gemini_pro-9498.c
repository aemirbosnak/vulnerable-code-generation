//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the maze
#define MAZE_SIZE 10

// Define the directions that can be taken when solving the maze
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the structure of a maze cell
typedef struct {
    bool visited;
    bool walls[4];
} MazeCell;

// Define the structure of the maze
typedef struct {
    MazeCell cells[MAZE_SIZE][MAZE_SIZE];
} Maze;

// Create a new maze
Maze* create_maze() {
    Maze* maze = malloc(sizeof(Maze));
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze->cells[i][j].visited = false;
            for (int k = 0; k < 4; k++) {
                maze->cells[i][j].walls[k] = true;
            }
        }
    }
    return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze* maze) {
    free(maze);
}

// Print the maze to the console
void print_maze(Maze* maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze->cells[i][j].visited) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Solve the maze using a depth-first search algorithm
bool solve_maze(Maze* maze, int x, int y) {
    // Mark the current cell as visited
    maze->cells[x][y].visited = true;

    // Check if we have reached the goal
    if (x == MAZE_SIZE - 1 && y == MAZE_SIZE - 1) {
        return true;
    }

    // Try all possible directions
    for (int i = 0; i < 4; i++) {
        // Check if the wall in the given direction is open
        if (!maze->cells[x][y].walls[i]) {
            // Move in the given direction
            switch (i) {
                case NORTH:
                    if (solve_maze(maze, x - 1, y)) {
                        return true;
                    }
                    break;
                case EAST:
                    if (solve_maze(maze, x, y + 1)) {
                        return true;
                    }
                    break;
                case SOUTH:
                    if (solve_maze(maze, x + 1, y)) {
                        return true;
                    }
                    break;
                case WEST:
                    if (solve_maze(maze, x, y - 1)) {
                        return true;
                    }
                    break;
            }
        }
    }

    // If no path was found, mark the current cell as unvisited and return false
    maze->cells[x][y].visited = false;
    return false;
}

// Main function
int main() {
    // Create a new maze
    Maze* maze = create_maze();

    // Solve the maze
    bool solved = solve_maze(maze, 0, 0);

    // Print the maze
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}