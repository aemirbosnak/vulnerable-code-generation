//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WIDTH (100 / CELL_SIZE)
#define HEIGHT (100 / CELL_SIZE)

typedef struct {
    int alive;
} cell_t;

cell_t **grid;

void init_grid(void) {
    int i, j;

    grid = malloc(WIDTH * sizeof(cell_t *));
    for (i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = 1 - (i % 2) + (j % 2);
        }
    }
}

void update_grid(void) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) neighbors++;
            if (i + 1 < WIDTH && grid[i + 1][j].alive) neighbors++;
            if (j - 1 >= 0 && grid[i][j - 1].alive) neighbors++;
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) neighbors++;

            if (neighbors == 2 || neighbors == 3) {
                grid[i][j].alive = 1 - grid[i][j].alive;
            } else if (neighbors == 0) {
                grid[i][j].alive = 0;
            }
        }
    }
}

void draw_grid(void) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    init_grid();

    for (int i = 0; i < 100; i++) {
        update_grid();
        draw_grid();
    }

    return 0;
}