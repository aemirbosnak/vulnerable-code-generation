//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            int alive = grid[i][j].alive;
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                        if (grid[x][y].alive) neighbors_alive++;
                    }
                }
            }
            grid[i][j].neighbors_alive = neighbors_alive;
            if (alive && neighbors_alive < 2) {
                grid[i][j].alive = 0;
            } else if (!alive && neighbors_alive == 3) {
                grid[i][j].alive = 1;
            }
        }
    }
}

void print_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    cell_t** grid = create_grid();
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}