//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30
#define NUM_NEIGHBORS 4
#define DROP_PROBABILITY 0.5
#define BOUNDARY_PROBABILITY 0.0
#define BOUNDARY_DROP_PROBABILITY 1.0
#define NUM_DROPS 1000

int rows, cols;
int **grid;
int num_filled;

void init_grid() {
    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    num_filled = 0;
}

void percolate() {
    for (int i = 0; i < NUM_DROPS; i++) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (grid[r][c] == 0) {
            grid[r][c] = 1;
            num_filled++;
            if (r > 0 && grid[r - 1][c] == 0) {
                grid[r - 1][c] = 1;
            }
            if (r < rows - 1 && grid[r + 1][c] == 0) {
                grid[r + 1][c] = 1;
            }
            if (c > 0 && grid[r][c - 1] == 0) {
                grid[r][c - 1] = 1;
            }
            if (c < cols - 1 && grid[r][c + 1] == 0) {
                grid[r][c + 1] = 1;
            }
        }
    }
}

void print_grid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    init_grid();
    percolate();
    print_grid();
    return 0;
}