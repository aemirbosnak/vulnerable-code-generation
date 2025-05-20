//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE 100

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE][GRID_SIZE];
} grid_t;

// Initialize the grid with random alive cells
void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].alive = rand() % 2;
        }
    }
}

// Draw the grid
void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Update the grid based on the rules of the Game of Life
void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Check the alive neighbors of the current cell
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid->cells[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }

            // Update the current cell based on the number of alive neighbors
            if (alive_neighbors < 2) {
                grid->cells[i][j].alive = 0;
            } else if (alive_neighbors > 3) {
                grid->cells[i][j].alive = 0;
            } else {
                grid->cells[i][j].alive = 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the grid
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    // Draw the grid
    draw_grid(grid);

    // Update the grid repeatedly
    while (1) {
        update_grid(grid);
        draw_grid(grid);
        usleep(10000);
    }

    return 0;
}