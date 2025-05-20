//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    char alive;
} cell_t;

typedef struct grid {
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

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->cells[i * CELL_HEIGHT + j].alive) {
                if (i % 2 == 0 && j % 2 == 0) {
                    grid->cells[i * CELL_HEIGHT + j].alive = 0;
                } else if (i % 2 == 1 && j % 2 == 1) {
                    grid->cells[i * CELL_HEIGHT + j].alive = 1;
                }
            }
        }
    }
}

int main() {
    grid_t *grid = (grid_t *)malloc(sizeof(grid_t));
    init_grid(grid);

    while (1) {
        draw_grid(grid);
        update_grid(grid);
        printf("Press enter to continue...\n");
        getchar();
    }

    free(grid);
    return 0;
}