//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int next;
} cell_t;

typedef struct grid {
    cell_t** cells;
    int width;
    int height;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        grid->cells[i] = (cell_t*) calloc(GRID_SIZE, sizeof(cell_t));
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].alive = (rand() % 2) ? 1 : 0;
            grid->cells[i][j].next = (rand() % 2) ? 1 : 0;
        }
    }
    grid->width = GRID_SIZE;
    grid->height = GRID_SIZE;
}

void update_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                if (grid->cells[i][j].next == 1) {
                    grid->cells[i][j].alive = 0;
                } else {
                    grid->cells[i][j].alive = 1;
                }
                grid->cells[i][j].next = 0;
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    grid_t* grid = (grid_t*) calloc(1, sizeof(grid_t));
    init_grid(grid);
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i + 1);
    }
    free(grid);
    return 0;
}