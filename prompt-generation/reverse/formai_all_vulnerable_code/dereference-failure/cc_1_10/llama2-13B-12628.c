//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a grid cell
typedef struct {
    int alive;   // Whether the cell is alive (1) or dead (0)
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the Game of Life rules
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors++;
            }

            // Apply the Game of Life rules
            if (grid[i][j].alive && neighbors >= 2 && neighbors <= 3) {
                grid[i][j].alive = 1;
            } else if (!grid[i][j].alive && neighbors == 3) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }

    init_grid(grid);

    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        draw_grid(grid);

        // Sleep for a bit to slow down the simulation
        sleep(1);
    }

    free(grid);
    return 0;
}