//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t **grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid) {
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

            // Apply the rules
            if (grid[i][j].alive && neighbors == 2) {
                grid[i][j].alive = 1; // Stay alive if there are 2 alive neighbors
            } else if (grid[i][j].alive && neighbors == 3) {
                grid[i][j].alive = 0; // Die if there are 3 alive neighbors
            } else {
                grid[i][j].alive = 0; // Stay alive if there are less than 2 alive neighbors
            }
        }
    }
}

int main() {
    cell_t **grid = (cell_t **) malloc(WIDTH * HEIGHT * sizeof(cell_t *));
    init_grid(grid);

    // Game loop
    for (int generation = 0; generation < 100; generation++) {
        apply_rules(grid);
        printf("Generation %d: \n", generation);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf("O"); // Represent alive cells as 'O'
                } else {
                    printf("."); // Represent dead cells as '.'
                }
            }
            printf("\n");
        }
    }

    free(grid);
    return 0;
}