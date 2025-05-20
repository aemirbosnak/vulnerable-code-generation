//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE][GRID_SIZE];
} grid_t;

void initialize_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].alive = (i + j) % 2;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int alive_neighbors = 0;

            // Count the number of alive neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid->cells[i + k][j + l].alive) alive_neighbors++;
                }
            }

            // Apply the Game of Life rules
            if (grid->cells[i][j].alive && alive_neighbors < 2 && alive_neighbors > 0) {
                grid->cells[i][j].alive = 0; // die of loneliness
            } else if (grid->cells[i][j].alive && alive_neighbors >= 2 && alive_neighbors < 4) {
                grid->cells[i][j].alive = 1; // survive
            } else {
                grid->cells[i][j].alive = 0; // die of overcrowding
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t *grid = malloc(sizeof(grid_t));
    initialize_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }

    free(grid);

    return 0;
}