//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 1024

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} Cell;

// Function to initialize the game of life grid
void initGrid(Cell** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the game of life rules
void applyRules(Cell** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) neighbors++;
                }
            }

            // Apply the rules
            if (grid[i][j].alive && neighbors < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors >= 3) {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    // Create the game of life grid
    Cell** grid = (Cell**) malloc(WIDTH * HEIGHT * sizeof(Cell*));
    initGrid(grid);

    // Apply the game of life rules for 10 generations
    for (int generation = 0; generation < 10; generation++) {
        applyRules(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    free(grid);
    return 0;
}