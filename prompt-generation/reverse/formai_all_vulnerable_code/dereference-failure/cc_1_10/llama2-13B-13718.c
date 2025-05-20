//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

// Define the grid structure
typedef struct grid_t {
    int **grid;
    int size;
} grid_t;

// Initialize the grid
void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        grid->grid[i] = calloc(WIDTH, sizeof(int));
        for (j = 0; j < WIDTH; j++) {
            grid->grid[i][j] = 0;
        }
    }
    grid->size = HEIGHT * WIDTH;
}

// Draw the grid
void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

// Update the grid
void update_grid(grid_t *grid) {
    int i, j, alive_neighbors = 0;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int x = grid->grid[i][j];
            if (x == 1) {
                // Count the number of alive neighbors
                alive_neighbors += count_alive_neighbors(grid, i, j);
            }
        }
    }
    // Apply the rules
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int x = grid->grid[i][j];
            if (x == 1 && alive_neighbors >= 2) {
                // Survive
                grid->grid[i][j] = 1;
            } else if (x == 0 && alive_neighbors == 3) {
                // Born
                grid->grid[i][j] = 1;
            } else {
                // Die
                grid->grid[i][j] = 0;
            }
            alive_neighbors = 0;
        }
    }
}

// Count the number of alive neighbors
int count_alive_neighbors(grid_t *grid, int i, int j) {
    int alive_neighbors = 0;
    int k, l;
    for (k = -1; k <= 1; k++) {
        for (l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;
            int x = grid->grid[i + k][j + l];
            if (x == 1) alive_neighbors++;
        }
    }
    return alive_neighbors;
}

int main() {
    // Initialize the grid
    grid_t *grid = calloc(1, sizeof(grid_t));
    init_grid(grid);

    // Draw the grid
    draw_grid(grid);

    // Update the grid for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    // Draw the final grid
    draw_grid(grid);

    return 0;
}