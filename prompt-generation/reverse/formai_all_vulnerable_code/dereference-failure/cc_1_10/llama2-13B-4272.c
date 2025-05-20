//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int width;
    int height;
} grid_t;

void create_grid(grid_t* g) {
    g->grid = (cell_t**) malloc(GRID_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        g->grid[i] = (cell_t*) malloc(GRID_SIZE * sizeof(cell_t));
        for (int j = 0; j < GRID_SIZE; j++) {
            g->grid[i][j].alive = 0;
            g->grid[i][j].born = 0;
        }
    }
    g->width = GRID_SIZE;
    g->height = GRID_SIZE;
}

void update_grid(grid_t* g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (g->grid[i][j].alive) {
                // Check for neighbors
                int count = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) continue;
                        if (g->grid[i + k][j + l].alive) count++;
                    }
                }
                // Update alive status based on neighbors
                if (count < 2 && count > 0) {
                    g->grid[i][j].alive = 1;
                } else if (count == 2 || count == 3) {
                    g->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (g->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    grid_t* g = (grid_t*) malloc(sizeof(grid_t));
    create_grid(g);

    for (int i = 0; i < 100; i++) {
        update_grid(g);
        draw_grid(g);
    }

    return 0;
}