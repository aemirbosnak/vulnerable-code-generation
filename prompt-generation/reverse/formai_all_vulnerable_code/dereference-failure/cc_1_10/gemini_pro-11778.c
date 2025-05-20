//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Maze cell types
#define CELL_EMPTY 0
#define CELL_WALL 1
#define CELL_VISITED 2

// Direction constants
#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3

// Maze structure
typedef struct {
    int cells[WIDTH][HEIGHT];
    int width;
    int height;
} Maze;

// Stack structure for storing visited cells
typedef struct {
    int x;
    int y;
} Stack;

// Create a new maze
Maze* create_maze(int width, int height) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    // Initialize all cells to walls
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i][j] = CELL_WALL;
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
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            if (maze->cells[i][j] == CELL_WALL) {
                printf("#");
            } else if (maze->cells[i][j] == CELL_EMPTY) {
                printf(" ");
            } else if (maze->cells[i][j] == CELL_VISITED) {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Check if a cell is valid (within the maze and not a wall)
int is_valid_cell(Maze* maze, int x, int y) {
    return (x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->cells[x][y] != CELL_WALL);
}

// Get a random direction
int get_random_direction() {
    return rand() % 4;
}

// Generate a maze using the recursive backtracking algorithm
Maze* generate_maze(int width, int height) {
    srand(time(NULL));

    // Create a new maze
    Maze* maze = create_maze(width, height);

    // Create a stack to store visited cells
    Stack stack[WIDTH * HEIGHT];
    int top = 0;

    // Start at the top-left corner
    int x = 0;
    int y = 0;

    // While there are still unvisited cells
    while (top > 0 || !is_valid_cell(maze, x, y)) {
        // If the current cell is unvisited
        if (maze->cells[x][y] == CELL_WALL) {
            // Mark the cell as visited
            maze->cells[x][y] = CELL_VISITED;

            // Push the current cell onto the stack
            stack[top].x = x;
            stack[top].y = y;
            top++;
        }

        // Get a random direction
        int direction = get_random_direction();

        // Try to move in the chosen direction
        switch (direction) {
            case DIR_UP:
                if (is_valid_cell(maze, x, y - 1)) {
                    y--;
                }
                break;
            case DIR_RIGHT:
                if (is_valid_cell(maze, x + 1, y)) {
                    x++;
                }
                break;
            case DIR_DOWN:
                if (is_valid_cell(maze, x, y + 1)) {
                    y++;
                }
                break;
            case DIR_LEFT:
                if (is_valid_cell(maze, x - 1, y)) {
                    x--;
                }
                break;
        }

        // If the current cell is a dead end, pop it from the stack
        if (!is_valid_cell(maze, x, y)) {
            top--;
            x = stack[top].x;
            y = stack[top].y;
        }
    }

    // Return the generated maze
    return maze;
}

// Main function
int main() {
    // Generate a new maze
    Maze* maze = generate_maze(WIDTH, HEIGHT);

    // Print the maze to the console
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}