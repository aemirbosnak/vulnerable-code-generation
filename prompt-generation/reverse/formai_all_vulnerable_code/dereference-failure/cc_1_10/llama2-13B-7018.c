//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t** cells;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;

    grid->rows = WINDOW_HEIGHT / CELL_SIZE;
    grid->cols = WINDOW_WIDTH / CELL_SIZE;

    grid->cells = calloc(grid->rows, sizeof(cell_t*));

    for (i = 0; i < grid->rows; i++) {
        grid->cells[i] = calloc(grid->cols, sizeof(cell_t));

        for (j = 0; j < grid->cols; j++) {
            grid->cells[i][j].alive = 0;
        }
    }
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->cells[i][j].alive) {
                if (rand() % 2 == 0) {
                    grid->cells[i][j].alive = 1 - grid->cells[i][j].alive;
                }
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->cells[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t* grid = calloc(1, sizeof(grid_t));
    init_grid(grid);

    while (1) {
        update_grid(grid);
        draw_grid(grid);
        getch();
    }

    free(grid);

    return 0;
}