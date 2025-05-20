//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

// Function to create the grid and initialize the cell states
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
        }
    }
}

// Function to update the cell states based on the Game of Life rules
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, keep it alive
            if (grid[i][j].alive && (grid[i][j].alive == grid[i][j + 1].alive && grid[i][j].alive == grid[i + 1][j].alive) ||
                    (grid[i][j].alive && grid[i][j].alive == grid[i - 1][j].alive && grid[i + 1][j].alive)) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Create the grid
    cell_t** grid = malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }

    // Initialize the grid
    init_grid(grid);

    // Update the grid for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}