//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell {
    int x, y;
    int state;
} Cell;

Cell** create_grid(int size) {
    Cell** grid = malloc(size * sizeof(Cell*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].state = 0;
        }
    }
    return grid;
}

void print_grid(Cell** grid) {
    for (int i = 0; i < MAX_CELLS; i++) {
        for (int j = 0; j < MAX_CELLS; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }
}

int count_neighbors(Cell** grid, int x, int y) {
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (x + dx >= 0 && x + dx < MAX_CELLS && y + dy >= 0 && y + dy < MAX_CELLS) {
                if (grid[x + dx][y + dy].state == 1) {
                    neighbors++;
                }
            }
        }
    }
    return neighbors;
}

void update_cells(Cell** grid) {
    for (int i = 0; i < MAX_CELLS; i++) {
        for (int j = 0; j < MAX_CELLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (neighbors < 2) {
                grid[i][j].state = 0;
            } else if (neighbors == 2) {
                grid[i][j].state = 1;
            } else if (neighbors > 3) {
                grid[i][j].state = 0;
            }
        }
    }
}

int main() {
    Cell** grid = create_grid(MAX_CELLS);
    grid[5][5].state = 1;
    grid[5][6].state = 1;
    grid[6][5].state = 1;
    grid[6][6].state = 1;
    print_grid(grid);
    update_cells(grid);
    print_grid(grid);

    free(grid);
    return 0;
}