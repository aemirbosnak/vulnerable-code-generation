//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *cells;
    int width;
    int height;
} Grid;

void init_grid(Grid *grid, int width, int height) {
    grid->width = width;
    grid->height = height;
    grid->cells = malloc(sizeof(Point) * width * height);
}

void free_grid(Grid *grid) {
    free(grid->cells);
}

void set_cell(Grid *grid, int x, int y, int value) {
    if (x < 0 || x >= grid->width || y < 0 || y >= grid->height) {
        return;
    }
    grid->cells[y * grid->width + x].x = x;
    grid->cells[y * grid->width + x].y = y;
}

int get_cell(Grid *grid, int x, int y) {
    if (x < 0 || x >= grid->width || y < 0 || y >= grid->height) {
        return 0;
    }
    return grid->cells[y * grid->width + x].x != 0;
}

int count_neighbors(Grid *grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            count += get_cell(grid, x + i, y + j);
        }
    }
    return count;
}

void update_grid(Grid *grid) {
    Grid new_grid;
    init_grid(&new_grid, grid->width, grid->height);
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            int neighbors = count_neighbors(grid, i, j);
            int cell = get_cell(grid, i, j);
            if (cell && (neighbors == 2 || neighbors == 3)) {
                set_cell(&new_grid, i, j, 1);
            } else if (!cell && neighbors == 3) {
                set_cell(&new_grid, i, j, 1);
            }
        }
    }
    free_grid(grid);
    *grid = new_grid;
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%d ", get_cell(grid, j, i));
        }
        printf("\n");
    }
}

int main() {
    Grid grid;
    init_grid(&grid, 10, 10);
    set_cell(&grid, 3, 2, 1);
    set_cell(&grid, 4, 2, 1);
    set_cell(&grid, 5, 2, 1);
    set_cell(&grid, 4, 3, 1);
    set_cell(&grid, 4, 4, 1);
    print_grid(&grid);
    update_grid(&grid);
    print_grid(&grid);
    free_grid(&grid);
    return 0;
}