//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

cell_t** create_grid(void) {
    cell_t** grid = calloc(GRID_SIZE, sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

void update_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) alive_neighbors++;
                }
            }
            grid[i][j].neighbors_alive = alive_neighbors;
            if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && grid[i][j].neighbors_alive == 3) {
                grid[i][j].alive = 1;
            }
        }
    }
}

void print_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (grid[i][j].alive) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}

int main(void) {
    cell_t** grid = create_grid();
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}