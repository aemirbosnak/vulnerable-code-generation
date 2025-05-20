//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40
#define P 0.5

int **grid;
int num_cells;
int num_filled;

void init_grid(void) {
    int i, j;
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++) {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = 0;
        }
    }
    num_cells = HEIGHT * WIDTH;
    num_filled = 0;
}

void percolate(int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) {
        return;
    }
    if (grid[x][y] == 0) {
        grid[x][y] = 1;
        num_filled++;
    }
    if (x > 0 && grid[x - 1][y] == 0) {
        percolate(x - 1, y);
    }
    if (x < HEIGHT - 1 && grid[x + 1][y] == 0) {
        percolate(x + 1, y);
    }
    if (y > 0 && grid[x][y - 1] == 0) {
        percolate(x, y - 1);
    }
    if (y < WIDTH - 1 && grid[x][y + 1] == 0) {
        percolate(x, y + 1);
    }
}

int main(void) {
    srand(time(NULL));
    init_grid();
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (rand() % 100 < P) {
                percolate(y, x);
            }
        }
    }
    printf("Filled %d/%d cells\n", num_filled, num_cells);
    return 0;
}