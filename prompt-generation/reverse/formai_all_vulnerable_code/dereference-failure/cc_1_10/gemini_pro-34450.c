//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the maze
#define M 10
#define N 10

// Cell values
#define WALL -1
#define PATH 0
#define VISITED 1

// Directions
enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Maze data structure
struct maze {
    int cells[M][N];
};

// Function to create a new maze
struct maze *create_maze() {
    // Allocate memory for the maze
    struct maze *maze = malloc(sizeof(struct maze));

    // Initialize the maze cells to WALL
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            maze->cells[i][j] = WALL;
        }
    }

    // Set the starting cell to PATH
    maze->cells[0][0] = PATH;

    // Return the maze
    return maze;
}

// Function to print the maze
void print_maze(struct maze *maze) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (maze->cells[i][j] == WALL) {
                printf("#");
            } else if (maze->cells[i][j] == PATH) {
                printf(".");
            } else if (maze->cells[i][j] == VISITED) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to solve the maze using depth-first search
int solve_maze(struct maze *maze, int x, int y) {
    // Check if the cell is out of bounds or is a wall
    if (x < 0 || x >= M || y < 0 || y >= N || maze->cells[x][y] == WALL) {
        return 0;
    }

    // Check if the cell has already been visited
    if (maze->cells[x][y] == VISITED) {
        return 0;
    }

    // Mark the cell as visited
    maze->cells[x][y] = VISITED;

    // Check if the cell is the goal
    if (x == M - 1 && y == N - 1) {
        return 1;
    }

    // Recursively call solve_maze on the neighboring cells
    if (solve_maze(maze, x + 1, y) ||
        solve_maze(maze, x - 1, y) ||
        solve_maze(maze, x, y + 1) ||
        solve_maze(maze, x, y - 1)) {
        return 1;
    }

    // Backtrack by setting the cell to PATH
    maze->cells[x][y] = PATH;

    // Return 0 to indicate that the maze is not solved
    return 0;
}

// Main function
int main() {
    // Create a new maze
    struct maze *maze = create_maze();

    // Print the maze
    printf("Original maze:\n");
    print_maze(maze);

    // Solve the maze
    if (solve_maze(maze, 0, 0)) {
        printf("\nSolved maze:\n");
        print_maze(maze);
    } else {
        printf("\nMaze cannot be solved.\n");
    }

    // Free the memory allocated for the maze
    free(maze);

    return 0;
}