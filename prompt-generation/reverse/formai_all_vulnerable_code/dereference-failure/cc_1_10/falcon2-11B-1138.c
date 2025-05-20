//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 1000
#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int x;
    int y;
    int alive;
} cell_t;

typedef struct {
    int num_cells;
    int *rows;
    int *cols;
    cell_t *cells;
} grid_t;

void print_grid(const grid_t *grid) {
    printf("%d %d\n", grid->rows[0], grid->cols[0]);
    for (int i = 1; i < grid->rows[0]; i++) {
        printf("%d %d\n", grid->rows[i], grid->cols[i]);
    }
}

void setup_grid(grid_t *grid) {
    grid->num_cells = MAX_CELLS;
    grid->rows = (int*)malloc(grid->num_cells * sizeof(int));
    grid->cols = (int*)malloc(grid->num_cells * sizeof(int));
    grid->cells = (cell_t*)malloc(grid->num_cells * sizeof(cell_t));
    for (int i = 0; i < grid->num_cells; i++) {
        grid->rows[i] = i;
        grid->cols[i] = i;
        grid->cells[i].x = i % MAX_ROWS;
        grid->cells[i].y = i / MAX_ROWS;
        grid->cells[i].alive = 0;
    }
}

void free_grid(grid_t *grid) {
    free(grid->rows);
    free(grid->cols);
    free(grid->cells);
}

int main() {
    grid_t grid;
    setup_grid(&grid);
    print_grid(&grid);
    free_grid(&grid);
    return 0;
}