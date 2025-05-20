//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct {
    int alive;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            grid->cells[i * CELL_HEIGHT + j].alive = 1;
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->cells[i * CELL_HEIGHT + j].alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void apply_rules(grid_t *grid) {
    int i, j, neighbor_count;

    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            neighbor_count = 0;

            if (i - 1 >= 0 && grid->cells[i - 1 * CELL_HEIGHT + j].alive) {
                neighbor_count++;
            }
            if (i + 1 < CELL_WIDTH && grid->cells[i + 1 * CELL_HEIGHT + j].alive) {
                neighbor_count++;
            }
            if (j - 1 >= 0 && grid->cells[i * CELL_HEIGHT + j - 1].alive) {
                neighbor_count++;
            }
            if (j + 1 < CELL_HEIGHT && grid->cells[i * CELL_HEIGHT + j + 1].alive) {
                neighbor_count++;
            }

            if (grid->cells[i * CELL_HEIGHT + j].alive && neighbor_count < 2) {
                grid->cells[i * CELL_HEIGHT + j].alive = 0;
            } else if (!grid->cells[i * CELL_HEIGHT + j].alive && neighbor_count >= 2) {
                grid->cells[i * CELL_HEIGHT + j].alive = 1;
            }
        }
    }
}

int main() {
    grid_t *grid = calloc(1, sizeof(grid_t));

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
        draw_grid(grid);
    }

    free(grid);

    return 0;
}