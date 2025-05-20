//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
/*
 * Ada Lovelace's Percolation Simulator
 *
 * This program simulates the percolation process in a 2D grid,
 * inspired by the elegance and imagination of Ada Lovelace.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH  10
#define HEIGHT 10

/* Define grid structure and related functions */
typedef struct {
    bool **grid;
    int width;
    int height;
} PercolationGrid;

bool is_valid_index(PercolationGrid *grid, int x, int y);
void print_grid(PercolationGrid *grid);
void initialize_grid(PercolationGrid *grid);
void random_site(PercolationGrid *grid);
bool site_is_connected(PercolationGrid *grid, int x, int y);
bool percolates(PercolationGrid *grid);

int main() {
    srand(time(NULL));

    PercolationGrid p_grid;
    p_grid.width = WIDTH;
    p_grid.height = HEIGHT;
    p_grid.grid = malloc(p_grid.height * sizeof(bool *));

    for (int i = 0; i < p_grid.height; i++) {
        p_grid.grid[i] = calloc(p_grid.width, sizeof(bool));
    }

    initialize_grid(&p_grid);

    int iterations = 1000;
    for (int i = 0; i < iterations; i++) {
        random_site(&p_grid);
        if (percolates(&p_grid)) {
            printf("Percolation occurred after %d iterations.\n", i + 1);
            print_grid(&p_grid);
            break;
        }
    }

    for (int i = 0; i < p_grid.height; i++) {
        free(p_grid.grid[i]);
    }
    free(p_grid.grid);

    return 0;
}

bool is_valid_index(PercolationGrid *grid, int x, int y) {
    if (x < 0 || x >= grid->width || y < 0 || y >= grid->height) {
        return false;
    }
    return true;
}

void print_grid(PercolationGrid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%-2s", grid->grid[i][j] ? " █" : " .");
        }
        printf("\n");
    }
}

void initialize_grid(PercolationGrid *grid) {
    grid->grid[0][0] = true;
}

void random_site(PercolationGrid *grid) {
    int x, y;
    do {
        x = rand() % grid->width;
        y = rand() % grid->height;
    } while (!is_valid_index(grid, x, y) || grid->grid[y][x]);

    grid->grid[y][x] = true;
}

bool site_is_connected(PercolationGrid *grid, int x, int y) {
    if (!grid->grid[y][x]) {
        return false;
    }

    bool connected = false;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int new_x = x + j;
            int new_y = y + i;

            if (is_valid_index(grid, new_x, new_y) && grid->grid[new_y][new_x]) {
                connected = true;
                break;
            }
        }

        if (connected) {
            break;
        }
    }

    return connected;
}

bool percolates(PercolationGrid *grid) {
    for (int i = 0; i < grid->height; i++) {
        if (grid->grid[i][0]) {
            bool is_connected = site_is_connected(grid, 0, i);
            if (is_connected) {
                return true;
            }
        }
    }

    return false;
}