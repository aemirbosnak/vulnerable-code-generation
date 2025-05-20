//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
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

// Function to iterate through the grid and update cell values
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors_alive++;
            }
            // Update the cell value based on the number of alive neighbors
            grid[i][j].alive = (neighbors_alive == 2) || (grid[i][j].alive && neighbors_alive == 3);
            // Update the number of alive neighbors for the next iteration
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid
    cell_t** grid = malloc(WIDTH * sizeof(cell_t *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid);

    // Run the simulation for a few generations
    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid);
    }

    // Print the final state of the grid
    print_grid(grid);

    // Clean up memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}