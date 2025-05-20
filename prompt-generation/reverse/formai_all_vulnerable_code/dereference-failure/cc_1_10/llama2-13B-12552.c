//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>

#define GRID_SIZE 100
#define CELL_SIZE 10
#define MAX_LIFE_FORCE 100

typedef struct cell {
    int x;
    int y;
    int state;
} cell_t;

typedef struct grid {
    cell_t** cells;
    int width;
    int height;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < grid->width; i++) {
        grid->cells[i] = calloc(grid->height, sizeof(cell_t));
        for (j = 0; j < grid->height; j++) {
            grid->cells[i][j].x = i * CELL_SIZE;
            grid->cells[i][j].y = j * CELL_SIZE;
            grid->cells[i][j].state = 0; // dead
        }
    }
}

void update_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            cell_t* cell = &grid->cells[i][j];
            switch (cell->state) {
                case 0: // dead
                    if (random() % 10 < 5) {
                        cell->state = 1; // alive
                    }
                    break;
                case 1: // alive
                    if (random() % 10 < 2) {
                        cell->state = 2; // pulsating
                    } else {
                        cell->state = 0; // dead
                    }
                    break;
                case 2: // pulsating
                    cell->state = (cell->state + 1) % 3;
                    break;
            }
            if (cell->state == 2) {
                // pulsating cells have a chance to explode
                if (random() % 100 < 5) {
                    int radius = 2 * CELL_SIZE;
                    for (int k = -radius; k <= radius; k++) {
                        for (int l = -radius; l <= radius; l++) {
                            if (k * k + l * l <= radius * radius) {
                                grid->cells[i + k][j + l].state = 1; // alive
                            }
                        }
                    }
                }
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;
    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            cell_t* cell = &grid->cells[i][j];
            switch (cell->state) {
                case 0: // dead
                    printf(" . ");
                    break;
                case 1: // alive
                    printf(" ^ ");
                    break;
                case 2: // pulsating
                    printf(" ~ ");
                    break;
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
        usleep(10000); // update the grid every 10ms
    }
    return 0;
}