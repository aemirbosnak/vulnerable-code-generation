//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int **create_grid(int n) {
    int **grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void free_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int n, Point p) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            Point q = {p.x + i, p.y + j};
            if (q.x >= 0 && q.x < n && q.y >= 0 && q.y < n && grid[q.x][q.y] == 1) {
                count++;
            }
        }
    }
    return count;
}

void percolate(int **grid, int n) {
    srand(time(NULL));
    int threshold = rand() % 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && rand() % 100 < threshold) {
                grid[i][j] = 1;
            }
        }
    }
}

int main() {
    int n = 10;
    int **grid = create_grid(n);
    percolate(grid, n);
    print_grid(grid, n);
    free_grid(grid, n);
    return 0;
}