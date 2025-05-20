//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

cell_t *create_grid(void) {
    cell_t *grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        grid[i].alive = (rand() % 2) == 0;
        grid[i].born = 0;
    }
    return grid;
}

void update_grid(cell_t *grid) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (grid[i].alive && grid[i].born < 2) {
            grid[i].born++;
        }
        if (!grid[i].alive && grid[i].born > 0) {
            grid[i].alive = 1;
        }
        if (grid[i].alive && grid[i].born == 2) {
            grid[i].alive = 0;
        }
    }
}

void print_grid(cell_t *grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i * HEIGHT + j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    cell_t *grid = create_grid();
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    free(grid);
    return 0;
}