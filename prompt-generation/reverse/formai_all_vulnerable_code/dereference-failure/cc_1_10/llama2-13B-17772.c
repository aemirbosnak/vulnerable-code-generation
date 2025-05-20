//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int state; // 0 for dead, 1 for alive
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].state = (rand() % 2) ? 1 : 0; // Initialize cells randomly
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the game of life rules
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            int neighbors = count_neighbors(grid, i, j);

            if (grid[i][j].state == 1 && neighbors < 2) {
                // If a alive cell has less than two alive neighbors, it dies
                grid[i][j].state = 0;
            } else if (grid[i][j].state == 0 && neighbors >= 3) {
                // If a dead cell has three or more alive neighbors, it comes to life
                grid[i][j].state = 1;
            } else {
                // If a cell is already in the desired state, do nothing
                grid[i][j].neighbors = neighbors;
            }
        }
    }
}

// Function to count the number of alive neighbors of a cell
int count_neighbors(cell_t** grid, int i, int j) {
    int count = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue; // Don't count the current cell
            if (grid[i + k][j + l].state == 1) count++;
        }
    }

    return count;
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    cell_t** grid = malloc(WIDTH * HEIGHT * sizeof(cell_t*));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        // Print the current state of the grid
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                printf("%d ", grid[i][j].state);
            }
            printf("\n");
        }
        printf("\n");
    }

    free(grid);

    return 0;
}