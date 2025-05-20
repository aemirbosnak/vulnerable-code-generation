//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            grid->cells[i * CELL_HEIGHT + j].alive = (rand() % 2) == 0;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && grid->cells[i - 1].alive) {
                neighbors++;
            }
            if (i + 1 < CELL_WIDTH && grid->cells[i + 1].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid->cells[i * CELL_HEIGHT + j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < CELL_HEIGHT && grid->cells[i * CELL_HEIGHT + j + 1].alive) {
                neighbors++;
            }
            grid->cells[i * CELL_HEIGHT + j].alive = (grid->cells[i * CELL_HEIGHT + j].alive && neighbors >= 2) ||
                                                       (grid->cells[i * CELL_HEIGHT + j].alive && neighbors == 0 && i == CELL_WIDTH / 2 && j == CELL_HEIGHT / 2);
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

int main() {
    srand(time(NULL));
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i);
    }

    free(grid);
    return 0;
}