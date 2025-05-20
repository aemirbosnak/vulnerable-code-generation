//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 // size of the grid
#define P 0.5 // probability of filling a cell
#define N 1000 // number of simulations

int main() {
    int i, j, count = 0;
    int **grid = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));
    for (i = 0; i < N; i++) {
        int x, y;
        x = rand() % SIZE;
        y = rand() % SIZE;

        if (grid[x][y] == 0 && rand() % 100 < P * 100) {
            grid[x][y] = 1;
            count++;
        }
    }

    printf("Percentage of filled cells: %.2f\n", (float)count / (SIZE * SIZE) * 100);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}