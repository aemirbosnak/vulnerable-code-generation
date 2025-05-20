//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the maze walls
#define WALL_NORTH 1
#define WALL_EAST 2
#define WALL_SOUTH 4
#define WALL_WEST 8

// Define the maze cell states
#define CELL_VISITED 1
#define CELL_IN_PATH 2

// Define the directions
#define DIR_NORTH 0
#define DIR_EAST 1
#define DIR_SOUTH 2
#define DIR_WEST 3

// Define the maze structure
typedef struct {
    int walls; // The walls of the cell
    int state; // The state of the cell
} cell;

// Define the maze structure
typedef struct {
    cell cells[MAZE_WIDTH][MAZE_HEIGHT]; // The cells of the maze
    int start_x; // The starting x-coordinate of the maze
    int start_y; // The starting y-coordinate of the maze
    int end_x; // The ending x-coordinate of the maze
    int end_y; // The ending y-coordinate of the maze
} maze;

// Create a new maze
maze* create_maze() {
    // Allocate memory for the maze
    maze* m = (maze*)malloc(sizeof(maze));

    // Initialize the maze cells
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            m->cells[i][j].walls = WALL_NORTH | WALL_EAST | WALL_SOUTH | WALL_WEST;
            m->cells[i][j].state = CELL_VISITED;
        }
    }

    // Set the starting and ending coordinates of the maze
    m->start_x = 0;
    m->start_y = 0;
    m->end_x = MAZE_WIDTH - 1;
    m->end_y = MAZE_HEIGHT - 1;

    // Return the maze
    return m;
}

// Free the memory allocated for the maze
void free_maze(maze* m) {
    // Free the memory allocated for the maze cells
    free(m->cells);

    // Free the memory allocated for the maze
    free(m);
}

// Print the maze
void print_maze(maze* m) {
    // Print the top wall of the maze
    printf("+");
    for (int i = 0; i < MAZE_WIDTH; i++) {
        printf("---+");
    }
    printf("\n");

    // Print the maze cells
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < MAZE_WIDTH; j++) {
            // Print the left wall of the cell
            if (m->cells[i][j].walls & WALL_WEST) {
                printf("   |");
            } else {
                printf("    ");
            }

            // Print the bottom wall of the cell
            if (m->cells[i][j].walls & WALL_SOUTH) {
                printf("---+");
            } else {
                printf("   +");
            }
        }
        printf("\n");
    }
}

// Find the shortest path through the maze
bool find_path(maze* m, int x, int y) {
    // Check if the cell is the ending cell
    if (x == m->end_x && y == m->end_y) {
        return true;
    }

    // Mark the cell as visited
    m->cells[x][y].state = CELL_VISITED;

    // Try all four directions
    for (int i = 0; i < 4; i++) {
        int new_x = x;
        int new_y = y;

        // Get the next cell in the direction
        switch (i) {
            case DIR_NORTH:
                new_y--;
                break;
            case DIR_EAST:
                new_x++;
                break;
            case DIR_SOUTH:
                new_y++;
                break;
            case DIR_WEST:
                new_x--;
                break;
        }

        // Check if the cell is valid
        if (new_x >= 0 && new_x < MAZE_WIDTH && new_y >= 0 && new_y < MAZE_HEIGHT && m->cells[new_x][new_y].state != CELL_VISITED) {
            // Recursively find the path from the next cell
            if (find_path(m, new_x, new_y)) {
                // Mark the cell as in the path
                m->cells[x][y].state = CELL_IN_PATH;

                // Return true to indicate that a path has been found
                return true;
            }
        }
    }

    // If no path was found, return false
    return false;
}

// Main function
int main() {
    // Create a new maze
    maze* m = create_maze();

    // Find the shortest path through the maze
    if (find_path(m, m->start_x, m->start_y)) {
        // Print the maze with the path
        print_maze(m);
    } else {
        // Print an error message
        printf("No path found.\n");
    }

    // Free the memory allocated for the maze
    free_maze(m);

    return 0;
}