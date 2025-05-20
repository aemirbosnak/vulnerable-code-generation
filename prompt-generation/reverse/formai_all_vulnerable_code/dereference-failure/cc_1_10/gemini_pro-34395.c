//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
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
    int cells[WIDTH][HEIGHT];
    int open_count;
} grid_t;

// Function to create a new grid
grid_t* create_grid() {
    grid_t* grid = (grid_t*)malloc(sizeof(grid_t));
    if (grid == NULL) {
        return NULL;
    }

    // Initialize the grid cells to 0 (closed)
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid->cells[i][j] = 0;
        }
    }

    // Open cells randomly with probability P
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if ((double)rand() / RAND_MAX < P) {
                grid->cells[i][j] = 1;
                grid->open_count++;
            }
        }
    }

    return grid;
}

// Function to free the grid
void free_grid(grid_t* grid) {
    free(grid);
}

// Function to print the grid
void print_grid(grid_t* grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is open
int is_open(grid_t* grid, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return 0;
    }

    return grid->cells[x][y];
}

// Function to perform depth-first search to find a path from the top to the bottom of the grid
int dfs(grid_t* grid, int x, int y) {
    if (y == HEIGHT - 1) {
        return 1;
    }

    if (!is_open(grid, x, y)) {
        return 0;
    }

    // Mark the cell as visited
    grid->cells[x][y] = 2;

    // Recursively check the four neighboring cells
    return dfs(grid, x - 1, y) || dfs(grid, x + 1, y) || dfs(grid, x, y - 1) || dfs(grid, x, y + 1);
}

// Function to check if there is a path from the top to the bottom of the grid
int has_path(grid_t* grid) {
    for (int i = 0; i < WIDTH; i++) {
        if (dfs(grid, i, 0)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Create a new grid
    grid_t* grid = create_grid();

    printf("Grid dimensions: %d x %d\n", WIDTH, HEIGHT);
    printf("Probability of a cell being open: %.2f\n\n", P);
    printf("Grid:\n");
    print_grid(grid);

    // Check if there is a path from the top to the bottom of the grid
    int has_path_bool = has_path(grid);

    printf("\nDoes the grid have a path from the top to the bottom? ");
    if (has_path_bool) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free the grid
    free_grid(grid);

    return 0;
}