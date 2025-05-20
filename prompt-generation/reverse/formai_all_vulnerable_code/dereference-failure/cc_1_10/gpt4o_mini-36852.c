//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define VISITED '.'

// Maze dimensions
int rows, cols;

// Directions for movement
int direction[4][2] = {
    {0, 2},   // Down
    {0, -2},  // Up
    {2, 0},   // Right
    {-2, 0}   // Left
};

// Function to check if the position is within bounds
int is_in_bounds(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Function to print the maze
void print_maze(char **maze) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
}

// Recursive function to generate the maze using DFS
void generate_maze(char **maze, int x, int y) {
    int dir_order[4] = {0, 1, 2, 3};
    
    // Shuffle directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = dir_order[i];
        dir_order[i] = dir_order[j];
        dir_order[j] = temp;
    }

    // Visit each direction
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[dir_order[i]][0];
        int ny = y + direction[dir_order[i]][1];

        if (is_in_bounds(nx, ny) && maze[nx][ny] == WALL) {
            maze[nx][ny] = PATH;  // make the path
            maze[x + direction[dir_order[i]][0] / 2][y + direction[dir_order[i]][1] / 2] = PATH; // remove wall
            generate_maze(maze, nx, ny);  // recursively generate from the new position
        }
    }
}

// Main function to set up the maze and start generation
int main() {
    srand(time(NULL));  // Seed for randomness

    // Define maze size (make sure to have odd dimensions)
    rows = 21; 
    cols = 21;

    // Allocate memory for the maze
    char **maze = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (char *)malloc(cols * sizeof(char));
    }

    // Initialize maze with walls
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = WALL;
        }
    }

    // Start point
    maze[1][1] = PATH;

    // Generate the maze
    generate_maze(maze, 1, 1);

    // Print the generated maze
    print_maze(maze);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}