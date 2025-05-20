//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

typedef int bool;
#define true 1
#define false 0

typedef struct {
    int rows;
    int cols;
    int **grid;
} grid;

grid* create_grid(int rows, int cols) {
    grid *gr = malloc(sizeof(grid));
    gr->rows = rows;
    gr->cols = cols;
    gr->grid = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        gr->grid[i] = malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            gr->grid[i][j] = false;
        }
    }
    return gr;
}

void set_cell(grid *gr, int row, int col, bool alive) {
    if (row < 0 || row >= gr->rows || col < 0 || col >= gr->cols) {
        return;
    }
    gr->grid[row][col] = alive;
}

int count_neighbors(grid *gr, int row, int col) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (row + i >= 0 && row + i < gr->rows && col + j >= 0 && col + j < gr->cols) {
                neighbors += gr->grid[row + i][col + j];
            }
        }
    }
    return neighbors;
}

void update_grid(grid *gr) {
    grid *new_grid = create_grid(gr->rows, gr->cols);
    for (int i = 0; i < gr->rows; i++) {
        for (int j = 0; j < gr->cols; j++) {
            int neighbors = count_neighbors(gr, i, j);
            if (gr->grid[i][j]) {
                new_grid->grid[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                new_grid->grid[i][j] = (neighbors == 3);
            }
        }
    }
    for (int i = 0; i < gr->rows; i++) {
        free(gr->grid[i]);
    }
    free(gr->grid);
    gr->grid = new_grid->grid;
    free(new_grid);
}

void print_grid(grid *gr) {
    for (int i = 0; i < gr->rows; i++) {
        for (int j = 0; j < gr->cols; j++) {
            printf("%c", gr->grid[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

void run_game(grid *gr, int generations) {
    for (int i = 0; i < generations; i++) {
        update_grid(gr);
    }
}

void free_grid(grid *gr) {
    for (int i = 0; i < gr->rows; i++) {
        free(gr->grid[i]);
    }
    free(gr->grid);
    free(gr);
}

int main() {
    int rows = 50;
    int cols = 50;
    grid *gr = create_grid(rows, cols);
    // Set up the initial state of the grid
    set_cell(gr, 10, 10, true);
    set_cell(gr, 10, 11, true);
    set_cell(gr, 10, 12, true);
    set_cell(gr, 11, 10, true);
    set_cell(gr, 11, 12, true);
    set_cell(gr, 12, 10, true);
    set_cell(gr, 12, 11, true);
    set_cell(gr, 12, 12, true);
    // Run the game for a number of generations
    run_game(gr, 100);
    // Print the final state of the grid
    print_grid(gr);
    // Free the grid
    free_grid(gr);
    return 0;
}