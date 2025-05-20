//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 100
#define COLS 100
#define CELL_SIZE 100

typedef struct {
    int live;
} Cell;

int main() {
    Cell *grid = malloc(ROWS * COLS * sizeof(Cell));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i * COLS + j].live = 0;
        }
    }

    int num_gens = 0;

    while (true) {
        num_gens++;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int num_neighbors = 0;
                int live_neighbors = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        int x = i + dx;
                        int y = j + dy;

                        if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
                            continue;
                        }

                        if (grid[x * COLS + y].live == 1) {
                            num_neighbors++;
                            if (dx == 1 && dy == 1) {
                                live_neighbors++;
                            } else if (dx == 1 && dy == -1) {
                                live_neighbors++;
                            } else if (dx == -1 && dy == 1) {
                                live_neighbors++;
                            } else if (dx == -1 && dy == -1) {
                                live_neighbors++;
                            }
                        }
                    }
                }

                if (grid[i * COLS + j].live == 1) {
                    if (num_neighbors < 2 || num_neighbors > 3) {
                        grid[i * COLS + j].live = 0;
                    }
                } else {
                    if (num_neighbors == 3) {
                        grid[i * COLS + j].live = 1;
                    }
                }
            }
        }

        printf("Generation %d:\n", num_gens);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i * COLS + j].live == 1) {
                    printf("X");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        printf("\n");
    }

    free(grid);
    return 0;
}