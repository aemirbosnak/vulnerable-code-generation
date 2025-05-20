//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has 2 or 3 alive neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors_alive >= 2 && grid[i][j].neighbors_alive <= 3)) {
                // Keep the cell alive in the next generation
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive and has less than 2 alive neighbors, die
                if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                    grid[i][j].alive = 0;
                }
                // If the cell is alive and has more than 3 alive neighbors, die
                else if (grid[i][j].alive && grid[i][j].neighbors_alive > 3) {
                    grid[i][j].alive = 0;
                }
            }
            // Increment the number of alive neighbors for the current cell
            grid[i][j].neighbors_alive = count_alive_neighbors(grid, i, j);
        }
    }
}

// Function to count the number of alive neighbors for a cell
int count_alive_neighbors(cell_t** grid, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) {
                continue;  // Don't count the current cell
            }
            if (grid[i + k][j + l].alive) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cell_t** grid = malloc(WIDTH * sizeof(cell_t *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid);

    int generations = 100;
    for (int i = 0; i < generations; i++) {
        apply_rules(grid);
        printf("Generation %d\n", i + 1);
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                if (grid[i][j].alive) {
                    printf("*");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }

    free(grid);
    return 0;
}