//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

bool **grid;
int width, height;
int num_open;

void print_grid() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf(grid[i][j] ? " . " : " X ");
        }
        printf("\n");
    }
}

bool is_valid(int x, int y) {
    return x >= 0 && x < height && y >= 0 && y < width;
}

void dfs(int x, int y) {
    grid[x][y] = false;
    num_open--;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (is_valid(nx, ny) && grid[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

void percolate() {
    int x, y;
    do {
        x = rand() % height;
        y = rand() % width;
    } while (grid[x][y]);

    dfs(x, y);
}

int main() {
    srand(time(NULL));

    width = SIZE;
    height = SIZE;
    grid = calloc(height, sizeof(bool *));
    for (int i = 0; i < height; ++i) {
        grid[i] = calloc(width, sizeof(bool));
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }

    print_grid();

    printf("Percolation starting...\n");

    while (num_open > 0) {
        percolate();
        print_grid();
        printf("Number of open sites: %d\n", num_open);
    }

    printf("Percolation finished.\n");

    for (int i = 0; i < height; ++i) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}