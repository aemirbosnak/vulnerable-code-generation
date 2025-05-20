//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

int main(int argc, char **argv) {
    int i, j, k, l;
    int **grid;
    int alive;
    int *neighbors;
    int *neighbors2;

    srand(time(NULL));

    grid = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
            alive = grid[i][j];
        }
    }

    printf("Initial grid:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    while (1) {
        alive = 0;
        neighbors = (int *)malloc(COLS * sizeof(int));
        neighbors2 = (int *)malloc(COLS * sizeof(int));
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                for (k = -1; k <= 1; k++) {
                    for (l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) {
                            continue;
                        }
                        if (i + k >= 0 && i + k < ROWS && j + l >= 0 && j + l < COLS) {
                            neighbors[j]++;
                        }
                    }
                }
                if (grid[i][j] == 1) {
                    alive++;
                }
            }
        }

        for (i = 0; i < COLS; i++) {
            if (neighbors[i] == 3 || neighbors[i] == 2 && grid[i][j] == 1) {
                grid[i][j] = 1;
            } else if (neighbors[i] == 3 && grid[i][j] == 0) {
                grid[i][j] = 0;
            } else if (neighbors[i] == 2 && grid[i][j] == 1) {
                grid[i][j] = 0;
            } else if (neighbors[i] == 2 && grid[i][j] == 0) {
                grid[i][j] = 1;
            }
        }

        printf("Next generation:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        if (alive == 0) {
            break;
        }
    }

    free(grid);
    free(neighbors);
    free(neighbors2);

    return 0;
}