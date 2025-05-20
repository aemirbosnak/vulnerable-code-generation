//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

// Structure to represent a grid cell
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} Cell;

// Function to create a grid of size nx x ny
void create_grid(int nx, int ny, Cell **grid) {
    int i, j;

    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            grid[i][j] = (Cell) {0, 0};
        }
    }
}

// Function to iterate over the grid and apply the game of life rules
void apply_rules(Cell **grid, int nx, int ny) {
    int i, j;

    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            // Check the current cell and its neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors < 2 || grid[i][j].neighbors > 3)) {
                // If the cell is alive and has too few or too many neighbors, it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && grid[i][j].neighbors == 3) {
                // If the cell is dead and has exactly 3 alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }

            // Update the neighbors count for the current cell
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors++;
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    int nx = 20;
    int ny = 20;
    Cell **grid = malloc(nx * sizeof(Cell *));
    for (int i = 0; i < nx; i++) {
        grid[i] = malloc(ny * sizeof(Cell));
    }

    create_grid(nx, ny, grid);

    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid, nx, ny);

        // Print the current state of the grid
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                printf("%d ", grid[i][j].alive);
            }
            printf("\n");
        }
    }

    return 0;
}