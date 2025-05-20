//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
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

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid) {
    int i, j, neighbor_count;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            neighbor_count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbor_count++;
                    }
                }
            }
            // Update the cell's state based on the number of alive neighbors
            if (neighbor_count < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;
            } else if (neighbor_count > 3) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = 1;
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
    cell_t** grid = malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(sizeof(cell_t) * HEIGHT);
    }
    init_grid(grid);
    update_grid(grid);
    draw_grid(grid);
    return 0;
}