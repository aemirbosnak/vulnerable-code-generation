//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Data structure to represent the grid
typedef struct {
    int open;
    int visited;
} cell_t;

// Function to create a new grid
cell_t** create_grid() {
    // Allocate memory for the grid
    cell_t** grid = malloc(sizeof(cell_t*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(sizeof(cell_t) * WIDTH);
    }

    // Initialize the grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].open = (rand() < RAND_MAX * P);
            grid[i][j].visited = 0;
        }
    }

    return grid;
}

// Function to free the grid
void free_grid(cell_t** grid) {
    // Free the memory allocated for each row
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }

    // Free the memory allocated for the grid
    free(grid);
}

// Function to print the grid
void print_grid(cell_t** grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j].open ? 'O' : 'X');
        }
        printf("\n");
    }
}

// Function to check if a cell is open
int is_open(cell_t** grid, int x, int y) {
    return grid[y][x].open;
}

// Function to check if a cell has been visited
int is_visited(cell_t** grid, int x, int y) {
    return grid[y][x].visited;
}

// Function to set a cell to visited
void set_visited(cell_t** grid, int x, int y) {
    grid[y][x].visited = 1;
}

// Function to perform a depth-first search on the grid
int dfs(cell_t** grid, int x, int y) {
    // Check if the cell is out of bounds
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return 0;
    }

    // Check if the cell is not open
    if (!is_open(grid, x, y)) {
        return 0;
    }

    // Check if the cell has been visited
    if (is_visited(grid, x, y)) {
        return 0;
    }

    // Set the cell to visited
    set_visited(grid, x, y);

    // Recursively call dfs on the neighboring cells
    return dfs(grid, x - 1, y) || dfs(grid, x + 1, y) || dfs(grid, x, y - 1) || dfs(grid, x, y + 1);
}

// Function to check if the grid percolates
int percolates(cell_t** grid) {
    // Perform a depth-first search from the top row
    for (int i = 0; i < WIDTH; i++) {
        if (dfs(grid, i, 0)) {
            return 1;
        }
    }

    // Perform a depth-first search from the bottom row
    for (int i = 0; i < WIDTH; i++) {
        if (dfs(grid, i, HEIGHT - 1)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    cell_t** grid = create_grid();

    // Print the grid
    print_grid(grid);

    // Check if the grid percolates
    int does_percolate = percolates(grid);

    // Print the result
    printf("Does the grid percolate? %s\n", does_percolate ? "Yes" : "No");

    // Free the grid
    free_grid(grid);

    return 0;
}