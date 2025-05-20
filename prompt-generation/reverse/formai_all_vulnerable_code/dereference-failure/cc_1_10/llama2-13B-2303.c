//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define SPEED 5

typedef struct {
    int x;
    int y;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE][GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].x = i * CELL_SIZE;
            grid->cells[i][j].y = j * CELL_SIZE;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int alive = 1;

            if (grid->cells[i][j].x < CELL_SIZE / 2) {
                alive = grid->cells[i][j].x > CELL_SIZE / 2;
            }

            if (grid->cells[i][j].y < CELL_SIZE / 2) {
                alive = grid->cells[i][j].y > CELL_SIZE / 2;
            }

            if (alive) {
                grid->cells[i][j].x += SPEED;
            } else {
                grid->cells[i][j].x -= SPEED;
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid->cells[i][j].x);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    while (1) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1);
    }

    return 0;
}