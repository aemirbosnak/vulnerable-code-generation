//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int width;
    int height;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;

    grid->width = WIDTH;
    grid->height = HEIGHT;

    grid->grid = malloc(sizeof(cell_t*) * grid->width);

    for (i = 0; i < grid->width; i++) {
        grid->grid[i] = malloc(sizeof(cell_t) * grid->height);

        for (j = 0; j < grid->height; j++) {
            grid->grid[i][j].x = i;
            grid->grid[i][j].y = j;
            grid->grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
            int alive_neighbors = 0;

            if (i - 1 >= 0 && grid->grid[i - 1][j].alive) {
                alive_neighbors++;
            }

            if (i + 1 < grid->width && grid->grid[i + 1][j].alive) {
                alive_neighbors++;
            }

            if (j - 1 >= 0 && grid->grid[i][j - 1].alive) {
                alive_neighbors++;
            }

            if (j + 1 < grid->height && grid->grid[i][j + 1].alive) {
                alive_neighbors++;
            }

            grid->grid[i][j].alive = (alive_neighbors == 2 || alive_neighbors == 3) ? 1 : 0;
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->width; i++) {
        for (j = 0; j < grid->height; j++) {
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

    grid_t* grid = malloc(sizeof(grid_t));

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1);
    }

    free(grid);

    return 0;
}