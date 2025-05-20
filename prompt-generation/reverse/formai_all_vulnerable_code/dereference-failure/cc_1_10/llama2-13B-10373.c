//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100
#define CELL_SIZE 10

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

cell_t *create_grid(void) {
    cell_t *grid = calloc(WIDTH * HEIGHT, sizeof(cell_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        grid[i].alive = rand() % 2;
        grid[i].neighbors_alive = 0;
    }
    return grid;
}

void print_grid(cell_t *grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i * HEIGHT + j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t *grid) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int alive = grid[i].alive;
        int neighbors_alive = grid[i].neighbors_alive;

        if (alive && neighbors_alive < CELL_SIZE) {
            grid[i].neighbors_alive++;
        } else if (!alive && neighbors_alive >= CELL_SIZE) {
            grid[i].neighbors_alive--;
        }

        if (grid[i].neighbors_alive == CELL_SIZE) {
            grid[i].alive = !grid[i].alive;
        }
    }
}

int main(void) {
    cell_t *grid = create_grid();
    print_grid(grid);

    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        print_grid(grid);
    }

    free(grid);
    return 0;
}