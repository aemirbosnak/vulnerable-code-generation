//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct {
    int alive;
    int x;
    int y;
} cell_t;

cell_t** generate_grid(void) {
    cell_t** grid = malloc(GRID_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(CELL_SIZE * sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].x = i * CELL_SIZE + j;
            grid[i][j].y = i;
        }
    }
    return grid;
}

void draw_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int m = -1; m <= 1; m++) {
                    if (k == 0 && m == 0) {
                        continue;
                    }
                    int x = i + k;
                    int y = j + m;
                    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                        if (grid[x][y].alive) {
                            alive_neighbors++;
                        }
                    }
                }
            }
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    cell_t** grid = generate_grid();
    draw_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }
    free(grid);
    return 0;
}