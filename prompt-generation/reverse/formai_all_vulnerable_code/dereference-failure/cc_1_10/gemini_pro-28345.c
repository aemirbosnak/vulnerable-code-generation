//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdlib.h>
#include <stdio.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    char** grid;
} Maze;

// Create a new maze with the given width and height
Maze* create_maze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(sizeof(char) * width);
    }
    return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

// Print the maze to the console
void print_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

// Solve the maze using a recursive backtracking algorithm
int solve_maze(Maze* maze, int x, int y) {
    // Check if we have reached the end of the maze
    if (x == maze->width - 1 && y == maze->height - 1) {
        return 1;
    }

    // Check if the current cell is a wall
    if (maze->grid[y][x] == '#') {
        return 0;
    }

    // Mark the current cell as visited
    maze->grid[y][x] = '.';

    // Try to move in all four directions
    if (solve_maze(maze, x + 1, y)) {
        return 1;
    }
    if (solve_maze(maze, x - 1, y)) {
        return 1;
    }
    if (solve_maze(maze, x, y + 1)) {
        return 1;
    }
    if (solve_maze(maze, x, y - 1)) {
        return 1;
    }

    // If we cannot move in any direction, backtrack
    maze->grid[y][x] = '#';
    return 0;
}

int main() {
    // Create a new maze
    Maze* maze = create_maze(10, 10);

    // Initialize the maze grid
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->grid[i][j] = '#';
        }
    }

    // Create a path through the maze
    maze->grid[0][0] = '.';
    maze->grid[0][1] = '.';
    maze->grid[0][2] = '.';
    maze->grid[0][3] = '.';
    maze->grid[0][4] = '.';
    maze->grid[0][5] = '.';
    maze->grid[0][6] = '.';
    maze->grid[0][7] = '.';
    maze->grid[0][8] = '.';
    maze->grid[0][9] = '.';
    maze->grid[1][0] = '.';
    maze->grid[2][0] = '.';
    maze->grid[3][0] = '.';
    maze->grid[4][0] = '.';
    maze->grid[5][0] = '.';
    maze->grid[6][0] = '.';
    maze->grid[7][0] = '.';
    maze->grid[8][0] = '.';
    maze->grid[9][0] = '.';
    maze->grid[9][1] = '.';
    maze->grid[9][2] = '.';
    maze->grid[9][3] = '.';
    maze->grid[9][4] = '.';
    maze->grid[9][5] = '.';
    maze->grid[9][6] = '.';
    maze->grid[9][7] = '.';
    maze->grid[9][8] = '.';
    maze->grid[9][9] = '.';

    // Print the maze to the console
    print_maze(maze);

    // Solve the maze
    int solved = solve_maze(maze, 0, 0);

    // Print the solution to the console
    if (solved) {
        printf("The maze was solved!\n");
    } else {
        printf("The maze could not be solved.\n");
    }

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}