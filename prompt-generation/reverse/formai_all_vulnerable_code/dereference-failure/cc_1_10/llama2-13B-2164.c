//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1);
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Count the number of alive neighbors
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }

            // Update the cell's state based on the number of alive neighbors
            if (grid[i][j].neighbors_alive < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;
            } else if (grid[i][j].neighbors_alive > 3) {
                grid[i][j].alive = 0;
            } else if (grid[i][j].alive && grid[i][j].neighbors_alive == 2) {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    cell_t** grid = malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }

    init_grid(grid, WIDTH, HEIGHT);

    for (int i = 0; i < 100; i++) {
        update_grid(grid, WIDTH, HEIGHT);
        // Display the current state of the grid
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                if (grid[i][j].alive) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    free(grid);

    return 0;
}