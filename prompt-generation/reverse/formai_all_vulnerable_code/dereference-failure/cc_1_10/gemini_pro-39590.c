//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Maze data structure
typedef struct {
    char** cells;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Maze;

// Create a new maze
Maze* create_maze() {
    Maze* maze = malloc(sizeof(Maze));
    maze->cells = malloc(sizeof(char*) * MAZE_HEIGHT);
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze->cells[i] = malloc(sizeof(char) * MAZE_WIDTH);
    }

    // Initialize the maze cells
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (x == 0 || y == 0 || x == MAZE_WIDTH - 1 || y == MAZE_HEIGHT - 1) {
                maze->cells[y][x] = '#'; // Wall
            } else {
                maze->cells[y][x] = ' '; // Open space
            }
        }
    }

    // Set the starting and ending positions
    maze->start_x = 1;
    maze->start_y = 1;
    maze->end_x = MAZE_WIDTH - 2;
    maze->end_y = MAZE_HEIGHT - 2;

    return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze* maze) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Print the maze to the console
void print_maze(Maze* maze) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("%c", maze->cells[y][x]);
        }
        printf("\n");
    }
}

// Find the path from the starting position to the ending position using a depth-first search
bool find_path(Maze* maze, int x, int y) {
    // Check if we have reached the ending position
    if (x == maze->end_x && y == maze->end_y) {
        return true;
    }

    // Check if we are outside the maze or have hit a wall
    if (x < 0 || x >= MAZE_WIDTH || y < 0 || y >= MAZE_HEIGHT || maze->cells[y][x] == '#') {
        return false;
    }

    // Mark the current cell as visited
    maze->cells[y][x] = '.';

    // Try all possible moves from the current cell
    if (find_path(maze, x + 1, y)) {
        return true;
    }
    if (find_path(maze, x - 1, y)) {
        return true;
    }
    if (find_path(maze, x, y + 1)) {
        return true;
    }
    if (find_path(maze, x, y - 1)) {
        return true;
    }

    // No path found from this cell
    return false;
}

int main() {
    // Create a new maze
    Maze* maze = create_maze();

    // Print the maze to the console
    printf("Initial maze:\n");
    print_maze(maze);

    // Find the path from the starting position to the ending position
    bool found = find_path(maze, maze->start_x, maze->start_y);

    // Print the maze with the path marked
    printf("\nMaze with path:\n");
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}