//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 20

// Define the probability of a cell being open
#define PROBABILITY 0.5

// Define the data structure for a cell
typedef struct {
    int is_open;
    int is_visited;
    int num_open_neighbors;
} cell_t;

// Define the data structure for the grid
typedef struct {
    cell_t cells[GRID_SIZE][GRID_SIZE];
} grid_t;

// Create a new grid
grid_t* create_grid() {
    grid_t* grid = malloc(sizeof(grid_t));
    if (grid == NULL) {
        return NULL;
    }

    // Initialize the cells
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].is_open = rand() < PROBABILITY * RAND_MAX;
            grid->cells[i][j].is_visited = 0;
            grid->cells[i][j].num_open_neighbors = 0;
        }
    }

    return grid;
}

// Destroy a grid
void destroy_grid(grid_t* grid) {
    free(grid);
}

// Print the grid
void print_grid(grid_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid->cells[i][j].is_open ? 'O' : 'X');
        }
        printf("\n");
    }
}

// Count the number of open neighbors of a cell
int count_open_neighbors(grid_t* grid, int i, int j) {
    int count = 0;

    // Check the cells above, below, left, and right of the cell
    if (i > 0 && grid->cells[i - 1][j].is_open) {
        count++;
    }
    if (i < GRID_SIZE - 1 && grid->cells[i + 1][j].is_open) {
        count++;
    }
    if (j > 0 && grid->cells[i][j - 1].is_open) {
        count++;
    }
    if (j < GRID_SIZE - 1 && grid->cells[i][j + 1].is_open) {
        count++;
    }

    return count;
}

// Perform a depth-first search on the grid
void dfs(grid_t* grid, int i, int j) {
    // Mark the cell as visited
    grid->cells[i][j].is_visited = 1;

    // Count the number of open neighbors
    grid->cells[i][j].num_open_neighbors = count_open_neighbors(grid, i, j);

    // If the cell has at least one open neighbor, visit the neighbor
    if (grid->cells[i][j].num_open_neighbors > 0) {
        // Visit the neighbor
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
}

// Check if the grid percolates
int percolates(grid_t* grid) {
    // Perform a depth-first search on the grid starting from the top row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid->cells[i][0].is_open) {
            dfs(grid, i, 0);
        }
    }

    // Check if any of the cells in the bottom row are visited
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid->cells[i][GRID_SIZE - 1].is_visited) {
            return 1;
        }
    }

    // The grid does not percolate
    return 0;
}

// Main function
int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    grid_t* grid = create_grid();

    // Print the grid
    printf("Initial grid:\n");
    print_grid(grid);

    // Check if the grid percolates
    int does_percolate = percolates(grid);

    // Print the result
    printf("\n");
    if (does_percolate) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    // Destroy the grid
    destroy_grid(grid);

    return 0;
}