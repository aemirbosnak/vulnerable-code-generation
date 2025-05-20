//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 50
#define COLS 50

int main(int argc, char *argv[]) {
    int i, j;
    char c;
    int **grid = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(COLS * sizeof(int));
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 1;
        }
    }
    printf("Initial Grid:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    while (1) {
        int next_gen[ROWS][COLS];
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                next_gen[i][j] = 0;
            }
        }
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                int live_neighbors = 0;
                if (i > 0 && grid[i - 1][j] == 1) {
                    live_neighbors++;
                }
                if (i < ROWS - 1 && grid[i + 1][j] == 1) {
                    live_neighbors++;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    live_neighbors++;
                }
                if (j < COLS - 1 && grid[i][j + 1] == 1) {
                    live_neighbors++;
                }
                if (grid[i][j] == 1) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        next_gen[i][j] = 1;
                    } else if (live_neighbors == 3) {
                        next_gen[i][j] = 1;
                    }
                } else {
                    if (live_neighbors == 3) {
                        next_gen[i][j] = 1;
                    }
                }
            }
        }
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                grid[i][j] = next_gen[i][j];
            }
        }
        printf("Generation %d:\n", ++i);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        c = getchar();
        if (c == 'q') {
            break;
        }
    }
    for (i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}