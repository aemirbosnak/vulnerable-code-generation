//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Maze data structure
typedef struct Maze {
    char grid[MAZE_WIDTH][MAZE_HEIGHT];
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Maze;

// Function prototypes
Maze* create_maze(void);
void print_maze(Maze* maze);
int solve_maze(Maze* maze, int x, int y, int* steps);

// Main function
int main(void) {
    // Create a maze
    Maze* maze = create_maze();

    // Print the maze
    print_maze(maze);

    // Solve the maze
    int steps = 0;
    if (solve_maze(maze, maze->start_x, maze->start_y, &steps)) {
        printf("Solved the maze in %d steps!\n", steps);
    } else {
        printf("No solution to the maze.\n");
    }

    // Free the maze
    free(maze);

    return 0;
}

// Create a maze
Maze* create_maze(void) {
    // Allocate memory for the maze
    Maze* maze = (Maze*)malloc(sizeof(Maze));

    // Initialize the maze grid
    for (int i = 0; i < MAZE_WIDTH; i++) {
        for (int j = 0; j < MAZE_HEIGHT; j++) {
            maze->grid[i][j] = '#';
        }
    }

    // Set the start and end positions
    maze->start_x = 0;
    maze->start_y = 0;
    maze->end_x = MAZE_WIDTH - 1;
    maze->end_y = MAZE_HEIGHT - 1;

    // Create a path through the maze
    int x = maze->start_x;
    int y = maze->start_y;
    while (x != maze->end_x || y != maze->end_y) {
        // Choose a random direction to move
        int direction = rand() % 4;

        // Move in the chosen direction
        switch (direction) {
            case 0:  // Up
                if (y > 0 && maze->grid[x][y - 1] == '#') {
                    maze->grid[x][y - 1] = ' ';
                    y--;
                }
                break;
            case 1:  // Right
                if (x < MAZE_WIDTH - 1 && maze->grid[x + 1][y] == '#') {
                    maze->grid[x + 1][y] = ' ';
                    x++;
                }
                break;
            case 2:  // Down
                if (y < MAZE_HEIGHT - 1 && maze->grid[x][y + 1] == '#') {
                    maze->grid[x][y + 1] = ' ';
                    y++;
                }
                break;
            case 3:  // Left
                if (x > 0 && maze->grid[x - 1][y] == '#') {
                    maze->grid[x - 1][y] = ' ';
                    x--;
                }
                break;
        }
    }

    // Return the maze
    return maze;
}

// Print the maze
void print_maze(Maze* maze) {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze->grid[j][i]);
        }
        printf("\n");
    }
}

// Solve the maze
int solve_maze(Maze* maze, int x, int y, int* steps) {
    // Check if we have reached the end of the maze
    if (x == maze->end_x && y == maze->end_y) {
        return 1;
    }

    // Mark the current position as visited
    maze->grid[x][y] = '.';

    // Increment the number of steps
    (*steps)++;

    // Recursively call solve_maze() for each possible move
    if (y > 0 && maze->grid[x][y - 1] != '#') {  // Up
        if (solve_maze(maze, x, y - 1, steps)) {
            return 1;
        }
    }
    if (x < MAZE_WIDTH - 1 && maze->grid[x + 1][y] != '#') {  // Right
        if (solve_maze(maze, x + 1, y, steps)) {
            return 1;
        }
    }
    if (y < MAZE_HEIGHT - 1 && maze->grid[x][y + 1] != '#') {  // Down
        if (solve_maze(maze, x, y + 1, steps)) {
            return 1;
        }
    }
    if (x > 0 && maze->grid[x - 1][y] != '#') {  // Left
        if (solve_maze(maze, x - 1, y, steps)) {
            return 1;
        }
    }

    // No solution found, backtrack
    maze->grid[x][y] = '#';
    return 0;
}