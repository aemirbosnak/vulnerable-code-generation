//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the rules of life
void update_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < size && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < size && grid[i][j + 1].alive) {
                neighbors_alive++;
            }

            // Update the cell's state based on the rules of life
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive >= 1) {
                grid[i][j].alive = 0; // Die if there are too few alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Born if there are too many alive neighbors
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    int size = 20; // Size of the grid
    cell_t** grid = malloc(size * size * sizeof(cell_t)); // Allocate memory for the grid

    init_grid(grid, size); // Initialize the grid with random values

    for (int i = 0; i < 100; i++) {
        update_grid(grid, size); // Update the grid based on the rules of life
        print_grid(grid, size); // Print the current state of the grid
        printf("Generation %d\n", i + 1);
        sleep(1); // Pause for 1 second to allow the grid to evolve
    }

    free(grid); // Free the memory allocated for the grid

    return 0;
}