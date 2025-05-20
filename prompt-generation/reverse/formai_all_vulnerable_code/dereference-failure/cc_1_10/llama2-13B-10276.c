//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int next;    // The next state of the cell (0 for death, 1 for birth)
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t **grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].next = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check for alive neighbors
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

            // Apply the rules
            if (grid[i][j].alive && alive_neighbors < 2 && alive_neighbors > 0) {
                grid[i][j].next = 1; // Birth
            } else if (!grid[i][j].alive && alive_neighbors >= 2) {
                grid[i][j].next = 1; // Death
            } else {
                grid[i][j].next = 0; // Stay the same
            }
        }
    }
}

int main() {
    cell_t **grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    generate_grid(grid);

    for (int i = 0; i < 10; i++) {
        apply_rules(grid);
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < WIDTH; k++) {
                if (grid[k][j].next) {
                    printf("Cell at (%d, %d) is born!\n", k, j);
                } else {
                    printf("Cell at (%d, %d) dies.\n", k, j);
                }
            }
        }
        printf("\n");
    }

    free(grid);
    return 0;
}