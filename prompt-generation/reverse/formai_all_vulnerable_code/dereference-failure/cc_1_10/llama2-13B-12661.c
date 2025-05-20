//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the rules of the Game of Life
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // Stay alive if there are 2 or 3 alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1;  // Born if there are 3 alive neighbors
            } else {
                grid[i][j].alive = 0;  // Die if not alive and there are no alive neighbors
            }
        }
    }
}

int main() {
    // Create the grid
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }
    init_grid(grid, WIDTH, HEIGHT);

    // Update the grid for a certain number of generations
    for (int gen = 0; gen < 100; gen++) {
        update_grid(grid, WIDTH, HEIGHT);
        usleep(1000);  // Pause for 1 second
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}