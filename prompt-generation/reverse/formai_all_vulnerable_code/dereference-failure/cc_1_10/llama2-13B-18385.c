//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int width, height;
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        grid->grid[i] = malloc(HEIGHT * sizeof(cell_t));
        for (j = 0; j < HEIGHT; j++) {
            grid->grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid->grid[i][j].born = 0;
        }
    }
    grid->width = WIDTH;
    grid->height = HEIGHT;
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid->grid[i][j].alive) {
                if (rand() % 2) {
                    grid->grid[i][j].alive = 0;
                } else {
                    grid->grid[i][j].born = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid->grid[i][j].alive) {
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

    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1);
    }

    return 0;
}