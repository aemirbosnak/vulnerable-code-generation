//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int births; // Number of times the cell has given birth
    int deaths; // Number of times the cell has died
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].births = 0;
            grid[i][j].deaths = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t **grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Calculate the number of alive neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }

            // Update the cell's state based on the rules of the Game of Life
            if (grid[i][j].alive && alive_neighbors < 2 && alive_neighbors > 0) {
                grid[i][j].alive = 0; // Die of loneliness
            } else if (grid[i][j].alive && alive_neighbors >= 2 && alive_neighbors <= 3) {
                grid[i][j].alive = 1; // Reproduce with 2-3 alive neighbors
            } else {
                grid[i][j].alive = 0; // Die of overcrowding
            }

            // Update the cell's birth and death counts
            if (grid[i][j].alive) {
                grid[i][j].births++;
            } else {
                grid[i][j].deaths++;
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t **grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid = (cell_t **)malloc(sizeof(cell_t *) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t *)malloc(sizeof(cell_t) * HEIGHT);
    }

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    print_grid(grid);

    return 0;
}