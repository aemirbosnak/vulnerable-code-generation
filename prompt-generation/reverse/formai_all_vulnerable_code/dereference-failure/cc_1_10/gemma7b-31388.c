//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

void solveSudoku(int **grid) {
    int i, j, k;
    for (i = 0; i < SUDO_SIZE; i++) {
        for (j = 0; j < SUDO_SIZE; j++) {
            if (grid[i][j] == 0) {
                for (k = 0; k < SUDO_SIZE; k++) {
                    if (grid[i][k] == 0 && grid[k][j] == 0 && grid[i][j] == 0) {
                        grid[i][j] = 2;
                        solveSudoku(grid);
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }

    if (checkSudoku(grid)) {
        printf("Solution:\n");
        for (i = 0; i < SUDO_SIZE; i++) {
            for (j = 0; j < SUDO_SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int checkSudoku(int **grid) {
    int i, j, k, num, count = 0;
    for (i = 0; i < SUDO_SIZE; i++) {
        for (j = 0; j < SUDO_SIZE; j++) {
            num = grid[i][j];
            if (num != 0) {
                count++;
                for (k = 0; k < SUDO_SIZE; k++) {
                    if (grid[i][k] == num) {
                        count++;
                    }
                }
                for (k = 0; k < SUDO_SIZE; k++) {
                    if (grid[k][j] == num) {
                        count++;
                    }
                }
            }
        }
    }

    return count == 9;
}

int main() {
    int **grid = (int **)malloc(SUDO_SIZE * sizeof(int *));
    for (int i = 0; i < SUDO_SIZE; i++) {
        grid[i] = (int *)malloc(SUDO_SIZE * sizeof(int));
    }

    grid[0][0] = 5;
    grid[0][1] = 3;
    grid[0][2] = 0;
    grid[0][3] = 0;
    grid[0][4] = 0;
    grid[0][5] = 0;
    grid[0][6] = 0;
    grid[0][7] = 0;
    grid[0][8] = 0;

    grid[1][0] = 6;
    grid[1][1] = 0;
    grid[1][2] = 0;
    grid[1][3] = 0;
    grid[1][4] = 0;
    grid[1][5] = 0;
    grid[1][6] = 0;
    grid[1][7] = 0;
    grid[1][8] = 0;

    grid[2][0] = 0;
    grid[2][1] = 0;
    grid[2][2] = 0;
    grid[2][3] = 0;
    grid[2][4] = 0;
    grid[2][5] = 0;
    grid[2][6] = 0;
    grid[2][7] = 0;
    grid[2][8] = 0;

    solveSudoku(grid);

    free(grid);
    return 0;
}