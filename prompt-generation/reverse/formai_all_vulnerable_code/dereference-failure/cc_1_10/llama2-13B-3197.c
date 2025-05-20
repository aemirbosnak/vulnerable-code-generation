//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) neighbors++;
            if (i + 1 < WIDTH && grid[i + 1][j].alive) neighbors++;
            if (j - 1 >= 0 && grid[i][j - 1].alive) neighbors++;
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) neighbors++;

            // Apply the rules
            if (grid[i][j].alive && neighbors >= 2 && neighbors <= 3) {
                grid[i][j].alive = 1; // Stay alive if 2-3 alive neighbors
            } else if (grid[i][j].alive && neighbors == 0) {
                grid[i][j].alive = 0; // Die if no alive neighbors
            } else if (grid[i][j].alive && neighbors >= 4) {
                grid[i][j].alive = 0; // Die if too many alive neighbors
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
                    printf("X ");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Sleep for a bit to make it look like the game is running smoothly
        sleep(1);
    }

    free(grid);
    return 0;
}