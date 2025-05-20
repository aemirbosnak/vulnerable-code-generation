//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    int alive;
    int next_alive;
} Cell;

Cell* create_grid(void) {
    Cell* grid = malloc(GRID_SIZE * GRID_SIZE * sizeof(Cell));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].alive = (i % 2 == 0) && (j % 2 == 0);
            grid[i * GRID_SIZE + j].next_alive = grid[i * GRID_SIZE + j].alive;
        }
    }
    return grid;
}

void update_grid(Cell* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int alive_neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1 * GRID_SIZE + j].alive) alive_neighbors++;
            if (i + 1 < GRID_SIZE && grid[i + 1 * GRID_SIZE + j].alive) alive_neighbors++;
            if (j - 1 >= 0 && grid[i * GRID_SIZE + j - 1].alive) alive_neighbors++;
            if (j + 1 < GRID_SIZE && grid[i * GRID_SIZE + j + 1].alive) alive_neighbors++;
            if (alive_neighbors >= 2 && alive_neighbors <= 3) {
                grid[i * GRID_SIZE + j].next_alive = 1;
            } else {
                grid[i * GRID_SIZE + j].next_alive = 0;
            }
        }
    }
}

void draw_grid(Cell* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    Cell* grid = create_grid();
    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        draw_grid(grid);
    }
    return 0;
}