//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 100
#define CELL_SIZE 10

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].alive = (rand() % 2) ? 1 : 0;
            grid[i * GRID_SIZE + j].neighbors = 0;
        }
    }
}

// Function to update the grid based on the current state
void update_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Calculate the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || j + l < 0 || i + k >= GRID_SIZE || j + l >= GRID_SIZE) {
                        continue;
                    }
                    if (grid[(i + k) * GRID_SIZE + (j + l)].alive) {
                        neighbors++;
                    }
                }
            }

            // Update the cell's state based on the number of alive neighbors
            if (grid[i * GRID_SIZE + j].alive && neighbors < 2) {
                grid[i * GRID_SIZE + j].alive = 0;
            } else if (!grid[i * GRID_SIZE + j].alive && neighbors >= 3) {
                grid[i * GRID_SIZE + j].alive = 1;
            }

            // Increment the number of alive neighbors for the next iteration
            grid[i * GRID_SIZE + j].neighbors = neighbors;
        }
    }
}

// Function to display the grid
void display_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t* grid = (cell_t*) malloc(GRID_SIZE * GRID_SIZE * sizeof(cell_t));
    init_grid(grid);

    int generations = 0;
    while (1) {
        update_grid(grid);
        generations++;

        // Display the grid after each generation
        display_grid(grid);

        // Ask the user if they want to continue
        printf("Do you want to continue (y/n)? ");
        char input = getchar();
        if (input == 'n' || input == 'N') {
            break;
        }
    }

    free(grid);
    return 0;
}