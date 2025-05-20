//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int next;   // The next state of the cell (for the next iteration)
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].next = grid[i][j].alive;
        }
    }
}

// Function to update the grid for one iteration
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].next == 1) {
                // If the cell is alive and has two or three alive neighbors, keep it alive
                if (grid[i][j].alive && (grid[i][j].alive + grid[i][j + 1].alive + grid[i][j + 2].alive) >= 2) {
                    grid[i][j].next = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (grid[i][j].alive && grid[i][j].alive < 2) {
                        grid[i][j].next = 0;
                    }
                }
            } else {
                // If the cell is dead and has three alive neighbors, come to life
                if (!grid[i][j].alive && (grid[i][j].alive + grid[i][j + 1].alive + grid[i][j + 2].alive) >= 3) {
                    grid[i][j].next = 1;
                }
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
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid;
    srand(time(NULL));

    // Initialize the grid with random values
    init_grid(&grid);

    // Update the grid for 100 iterations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    // Draw the final state of the grid
    draw_grid(grid);

    return 0;
}