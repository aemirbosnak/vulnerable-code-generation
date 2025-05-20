//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

struct Grid {
    unsigned int width;
    unsigned int height;
    bool **cells;
};

struct Grid *create_grid(unsigned int width, unsigned int height) {
    struct Grid *grid = malloc(sizeof(struct Grid));
    assert(grid != NULL);

    grid->width = width;
    grid->height = height;
    grid->cells = malloc(sizeof(bool *) * height);
    assert(grid->cells != NULL);

    for (unsigned int i = 0; i < height; i++) {
        grid->cells[i] = malloc(sizeof(bool) * width);
        assert(grid->cells[i] != NULL);
    }

    return grid;
}

void destroy_grid(struct Grid *grid) {
    for (unsigned int i = 0; i < grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}

static inline void set_cell(struct Grid *grid, unsigned int x, unsigned int y, bool alive) {
    assert(x < grid->width && y < grid->height);
    grid->cells[y][x] = alive;
}

static inline bool get_cell(struct Grid *grid, unsigned int x, unsigned int y) {
    assert(x < grid->width && y < grid->height);
    return grid->cells[y][x];
}

unsigned int count_living_neighbors(struct Grid *grid, unsigned int x, unsigned int y) {
    unsigned int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (get_cell(grid, x + i, y + j)) {
                count++;
            }
        }
    }
    return count;
}

void update_grid(struct Grid *grid) {
    struct Grid *new_grid = create_grid(grid->width, grid->height);

    for (unsigned int i = 0; i < grid->height; i++) {
        for (unsigned int j = 0; j < grid->width; j++) {
            unsigned int living_neighbors = count_living_neighbors(grid, j, i);

            if (get_cell(grid, j, i)) {
                if (living_neighbors == 2 || living_neighbors == 3) {
                    set_cell(new_grid, j, i, true);
                } else {
                    set_cell(new_grid, j, i, false);
                }
            } else {
                if (living_neighbors == 3) {
                    set_cell(new_grid, j, i, true);
                } else {
                    set_cell(new_grid, j, i, false);
                }
            }
        }
    }

    destroy_grid(grid);
    grid = new_grid;
}

void print_grid(struct Grid *grid) {
    for (unsigned int i = 0; i < grid->height; i++) {
        for (unsigned int j = 0; j < grid->width; j++) {
            printf("%c", get_cell(grid, j, i) ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    struct Grid *grid = create_grid(80, 25);

    // Initialize the grid with a glider
    set_cell(grid, 1, 2, true);
    set_cell(grid, 2, 3, true);
    set_cell(grid, 3, 1, true);
    set_cell(grid, 3, 2, true);
    set_cell(grid, 3, 3, true);

    while (true) {
        update_grid(grid);
        print_grid(grid);
        printf("\nPress any key to continue, or 'q' to quit: ");
        int c = getchar();
        if (c == 'q') {
            break;
        }
    }

    destroy_grid(grid);

    return 0;
}