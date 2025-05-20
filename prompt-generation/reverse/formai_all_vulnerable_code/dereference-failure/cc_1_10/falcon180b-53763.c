//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define P 0.5

int **grid;

void init_grid() {
    int i, j;
    grid = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
        for (j = 0; j < COLS; j++) {
            grid[i][j] = (rand() % 2)? 1 : 0;
        }
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate() {
    int i, j, k, count = 0;
    for (i = 1; i < ROWS - 1; i++) {
        for (j = 1; j < COLS - 1; j++) {
            if (grid[i][j] == 1) {
                count = 0;
                if (grid[i - 1][j] == 1) count++;
                if (grid[i + 1][j] == 1) count++;
                if (grid[i][j - 1] == 1) count++;
                if (grid[i][j + 1] == 1) count++;
                if (count!= 1) {
                    grid[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_grid();
    int num_perc = 0;
    while (num_perc < 1000) {
        print_grid();
        percolate();
        num_perc += count_percolations();
    }
    return 0;
}

int count_percolations() {
    int i, j, count = 0;
    for (i = 1; i < ROWS - 1; i++) {
        for (j = 1; j < COLS - 1; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}