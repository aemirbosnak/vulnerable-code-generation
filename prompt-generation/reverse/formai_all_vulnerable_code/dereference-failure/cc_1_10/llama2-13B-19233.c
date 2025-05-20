//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int x;
    int y;
    int alive;
} Cell;

typedef struct grid {
    Cell** grid;
    int rows;
    int cols;
} Grid;

void init_grid(Grid* g) {
    g->grid = (Cell**) malloc(sizeof(Cell*) * g->rows);
    for (int i = 0; i < g->rows; i++) {
        g->grid[i] = (Cell*) malloc(sizeof(Cell) * g->cols);
        for (int j = 0; j < g->cols; j++) {
            g->grid[i][j].x = j * CELL_SIZE;
            g->grid[i][j].y = i * CELL_SIZE;
            g->grid[i][j].alive = rand() % 2;
        }
    }
}

void draw_grid(Grid* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_grid(Grid* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                if (g->grid[i][j].x + 1 < WINDOW_WIDTH && !g->grid[i][j + 1].alive) {
                    g->grid[i][j].alive = 0;
                    g->grid[i][j + 1].alive = 1;
                } else if (g->grid[i][j].x - 1 >= 0 && !g->grid[i][j - 1].alive) {
                    g->grid[i][j].alive = 0;
                    g->grid[i][j - 1].alive = 1;
                } else if (g->grid[i][j].y + 1 < WINDOW_HEIGHT && !g->grid[i + 1][j].alive) {
                    g->grid[i][j].alive = 0;
                    g->grid[i + 1][j].alive = 1;
                } else if (g->grid[i][j].y - 1 >= 0 && !g->grid[i - 1][j].alive) {
                    g->grid[i][j].alive = 0;
                    g->grid[i - 1][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Grid g;
    init_grid(&g);
    draw_grid(&g);
    update_grid(&g);
    draw_grid(&g);
    return 0;
}