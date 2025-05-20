//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a grid cell
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to create a grid of size n x n
cell_t** create_grid(int n) {
    cell_t** grid = (cell_t**) malloc(n * sizeof(cell_t*));
    for (int i = 0; i < n; i++) {
        grid[i] = (cell_t*) malloc(n * sizeof(cell_t));
        for (int j = 0; j < n; j++) {
            grid[i][j].alive = (i == j) ? 1 : 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

// Function to print the grid
void print_grid(cell_t** grid) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to update the grid
void update_grid(cell_t** grid) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= 10 || j + l < 0 || j + l >= 10) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }
            grid[i][j].neighbors_alive = alive_neighbors;
            if (grid[i][j].alive && alive_neighbors < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && alive_neighbors >= 2) {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    cell_t** grid = create_grid(10);
    update_grid(grid);
    print_grid(grid);
    return 0;
}