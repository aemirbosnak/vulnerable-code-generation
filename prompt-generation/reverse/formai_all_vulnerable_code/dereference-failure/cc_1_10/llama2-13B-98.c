//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

void create_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int alive_neighbors = 0;

            // Check north neighbor
            if (i > 0 && grid[i - 1][j].alive) {
                alive_neighbors++;
            }

            // Check south neighbor
            if (i < GRID_SIZE - 1 && grid[i + 1][j].alive) {
                alive_neighbors++;
            }

            // Check west neighbor
            if (j > 0 && grid[i][j - 1].alive) {
                alive_neighbors++;
            }

            // Check east neighbor
            if (j < GRID_SIZE - 1 && grid[i][j + 1].alive) {
                alive_neighbors++;
            }

            // Update cell state based on number of alive neighbors
            if (alive_neighbors < 2) {
                grid[i][j].alive = 0;
            } else if (alive_neighbors > 3) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = 1;
            }
        }
    }
}

void draw_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    cell_t** grid = malloc(GRID_SIZE * sizeof(cell_t *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(cell_t));
    }

    create_grid(grid);

    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", generation + 1);
        sleep(1);
    }

    free(grid);

    return 0;
}