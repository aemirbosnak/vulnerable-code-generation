//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
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

// Function to iterate over the grid and apply the game of life rules
void apply_rules(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
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

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // Stay alive if there are 2 or 3 alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1;  // Be born if there are 3 alive neighbors
            } else {
                grid[i][j].alive = 0;  // Die if there are fewer than 2 or more than 3 alive neighbors
            }
        }
    }
}

// Main function
int main() {
    cell_t** grid = malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }

    init_grid(grid);

    for (int generation = 0; generation < 100; generation++) {
        apply_rules(grid);

        // Print the current state of the grid
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    free(grid);
    return 0;
}