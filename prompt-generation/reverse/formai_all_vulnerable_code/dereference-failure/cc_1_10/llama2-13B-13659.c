//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to iterate over the grid and update the state of each cell
void update_grid(cell_t** grid) {
    int i, j, k;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            k = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) k++;
            if (i + 1 < WIDTH && grid[i + 1][j].alive) k++;
            if (j - 1 >= 0 && grid[i][j - 1].alive) k++;
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) k++;

            // Update the cell's state based on the number of alive neighbors
            if (k < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;
                printf("Cell %d, %d died due to loneliness!\n", i, j);
            } else if (k > 3) {
                grid[i][j].alive = 0;
                printf("Cell %d, %d overpopulated and died!\n", i, j);
            } else {
                grid[i][j].alive = 1;
                printf("Cell %d, %d is alive and thriving!\n", i, j);
            }
        }
    }
}

int main() {
    cell_t** grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    init_grid(grid);

    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid);
    }

    free(grid);
    return 0;
}