//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell;

// Function to create the grid and initialize cells
void init_grid(cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1);  // Initialization based on the position of the cell
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell** grid) {
    int i, j, neighbor_count;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            neighbor_count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;  // Don't count the current cell
                    if (grid[i + k][j + l].alive) {
                        neighbor_count++;
                    }
                }
            }
            // Apply the rules based on the number of alive neighbors
            if (grid[i][j].alive && neighbor_count < 2) {
                grid[i][j].alive = 0;  // If the cell is alive and has less than two alive neighbors, it dies
            } else if (!grid[i][j].alive && neighbor_count >= 2) {
                grid[i][j].alive = 1;  // If the cell is dead and has two or more alive neighbors, it comes to life
            }
            grid[i][j].neighbors_alive = neighbor_count;
        }
    }
}

// Main function
int main() {
    cell** grid = (cell**) malloc(sizeof(cell*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell*) malloc(sizeof(cell) * HEIGHT);
    }
    init_grid(grid);

    // Apply the Game of Life rules for a few generations
    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid);
        printf("Generation %d: ", generation);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                printf("%d ", grid[i][j].alive);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}