//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct {
    int alive;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE][CELL_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->cells[i][j].alive = (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1);
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                if (i % 2 == 0 && j % 2 == 0) {
                    // Neighbors to the north, south, east, and west are alive
                    if (i - 1 >= 0 && grid->cells[i - 1][j].alive &&
                            i + 1 < GRID_SIZE && grid->cells[i + 1][j].alive &&
                            j - 1 >= 0 && grid->cells[i][j - 1].alive &&
                            j + 1 < CELL_SIZE && grid->cells[i][j + 1].alive) {
                        grid->cells[i][j].alive = 1;
                    } else {
                        grid->cells[i][j].alive = 0;
                    }
                } else if (i % 2 == 1 && j % 2 == 1) {
                    // Neighbors to the northeast, southeast, southwest, and northwest are alive
                    if (i - 1 >= 0 && grid->cells[i - 1][j].alive &&
                            i + 1 < GRID_SIZE && grid->cells[i + 1][j].alive &&
                            j - 1 >= 0 && grid->cells[i][j - 1].alive &&
                            j + 1 < CELL_SIZE && grid->cells[i][j + 1].alive) {
                        grid->cells[i][j].alive = 1;
                    } else {
                        grid->cells[i][j].alive = 0;
                    }
                } else {
                    grid->cells[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("X");
            } else {
                printf(".");
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
        sleep(1);
    }

    free(grid);

    return 0;
}