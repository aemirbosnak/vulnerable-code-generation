//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct {
    int alive;
    int next_alive;
} cell_t;

cell_t* create_grid(void) {
    cell_t* grid = calloc(GRID_SIZE, sizeof(cell_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].alive = rand() % 2;
            grid[i * GRID_SIZE + j].next_alive = grid[i * GRID_SIZE + j].alive;
        }
    }
    return grid;
}

void update_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].next_alive == 1) {
                if (grid[i * GRID_SIZE + j].alive == 0) {
                    grid[i * GRID_SIZE + j].alive = 1;
                } else if (grid[i * GRID_SIZE + j].alive == 1) {
                    grid[i * GRID_SIZE + j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive == 1) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    cell_t* grid = create_grid();
    update_grid(grid);
    draw_grid(grid);
    return 0;
}