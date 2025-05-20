//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 100
#define CELL_SIZE 10

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    int alive;
    int neighbors_alive;
} Cell;

Cell** create_grid(void) {
    Cell** grid = malloc(GRID_SIZE * sizeof(Cell*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(CELL_SIZE * sizeof(Cell));
        for (int j = 0; j < CELL_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

void print_grid(Cell** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

void update_grid(Cell** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < GRID_SIZE && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < CELL_SIZE && grid[i][j + 1].alive) {
                neighbors_alive++;
            }
            grid[i][j].neighbors_alive = neighbors_alive;
            if (grid[i][j].alive && neighbors_alive < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    Cell** grid = create_grid();
    print_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    free(grid);
    return 0;
}