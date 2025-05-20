//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check the current cell's neighbors
            if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                // If the cell is alive and has fewer than two alive neighbors, it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && grid[i][j].neighbors_alive >= 2) {
                // If the cell is dead and has two or more alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }
            // Update the number of alive neighbors for the current cell
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid = malloc(WIDTH * sizeof(cell_t *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid);
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
        print_grid(grid);
        printf("Generation %d\n", i);
    }
    free(grid);
    return 0;
}