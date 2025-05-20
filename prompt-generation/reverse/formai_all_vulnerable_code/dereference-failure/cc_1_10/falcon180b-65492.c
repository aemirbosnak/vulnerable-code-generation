//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6
#define T 100

int **create_grid();
void percolate(int **grid);
int count_neighbours(int **grid, int x, int y);

int main() {
    int i, j;
    int **grid;
    srand(time(NULL));

    grid = create_grid();

    for (i = 0; i < T; i++) {
        percolate(grid);
        printf("Iteration %d:\n", i + 1);
        for (j = 0; j < N; j++) {
            printf("");
            for (int k = 0; k < N; k++) {
                if (grid[j][k] == 1) {
                    printf("X ");
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

int **create_grid() {
    int **grid;
    int i, j;

    grid = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        grid[i] = (int *) malloc(N * sizeof(int));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    return grid;
}

void percolate(int **grid) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1 && count_neighbours(grid, i, j) == 0) {
                grid[i][j] = 0;
            } else if (grid[i][j] == 0 && count_neighbours(grid, i, j) >= 3) {
                grid[i][j] = 1;
            }
        }
    }
}

int count_neighbours(int **grid, int x, int y) {
    int count = 0;
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && grid[x + i][y + j] == 1) {
                count++;
            }
        }
    }

    return count;
}