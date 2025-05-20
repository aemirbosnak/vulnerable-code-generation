//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the dimensions of the maze.
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions of movement.
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

// Define the structure of a maze cell.
typedef struct {
    bool visited;
    bool wall[4]; // North, East, South, West
} maze_cell_t;

// Create a new maze.
maze_cell_t** create_maze() {
    // Allocate memory for the maze.
    maze_cell_t** maze = (maze_cell_t**)malloc(sizeof(maze_cell_t*) * MAZE_HEIGHT);
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze[i] = (maze_cell_t*)malloc(sizeof(maze_cell_t) * MAZE_WIDTH);
    }

    // Initialize the maze cells.
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j].visited = false;
            for (int k = 0; k < 4; k++) {
                maze[i][j].wall[k] = true;
            }
        }
    }

    // Return the maze.
    return maze;
}

// Free the memory allocated for the maze.
void free_maze(maze_cell_t** maze) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);
}

// Print the maze to the console.
void print_maze(maze_cell_t** maze) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j].visited) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Find a path through the maze using a depth-first search.
bool find_path(maze_cell_t** maze, int x, int y) {
    // Check if the current cell has been visited.
    if (maze[y][x].visited) {
        return false;
    }

    // Mark the current cell as visited.
    maze[y][x].visited = true;

    // Check if the current cell is the exit.
    if (x == MAZE_WIDTH - 1 && y == MAZE_HEIGHT - 1) {
        return true;
    }

    // Try each of the possible directions of movement.
    for (int i = 0; i < 4; i++) {
        // Check if the wall in the current direction is present.
        if (maze[y][x].wall[i]) {
            continue;
        }

        // Move in the current direction.
        switch (i) {
            case NORTH:
                if (find_path(maze, x, y - 1)) {
                    return true;
                }
                break;
            case EAST:
                if (find_path(maze, x + 1, y)) {
                    return true;
                }
                break;
            case SOUTH:
                if (find_path(maze, x, y + 1)) {
                    return true;
                }
                break;
            case WEST:
                if (find_path(maze, x - 1, y)) {
                    return true;
                }
                break;
        }
    }

    // No path was found, so backtrack.
    maze[y][x].visited = false;
    return false;
}

// Main function.
int main() {
    // Create a new maze.
    maze_cell_t** maze = create_maze();

    // Print the maze to the console.
    printf("Initial maze:\n");
    print_maze(maze);

    // Find a path through the maze.
    bool path_found = find_path(maze, 0, 0);

    // Print the maze with the path highlighted.
    printf("Maze with path:\n");
    print_maze(maze);

    // Free the memory allocated for the maze.
    free_maze(maze);

    return 0;
}