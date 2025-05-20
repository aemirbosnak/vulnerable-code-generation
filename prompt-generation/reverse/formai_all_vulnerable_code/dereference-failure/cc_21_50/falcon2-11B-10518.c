//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRows = 20;
    int numCols = 30;
    int numAlive = 500;
    int **grid = (int **)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        grid[i] = (int *)malloc(numCols * sizeof(int));
    }
    int i, j;
    srand(time(NULL));
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            grid[i][j] = rand() % 2 == 0;
        }
    }
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            if (grid[i][j] == 1) {
                int numNeighbors = 0;
                int r = i - 1;
                while (r >= 0 && r < numRows && grid[r][j] == 1) {
                    numNeighbors++;
                    r--;
                }
                r = i + 1;
                while (r >= 0 && r < numRows && grid[r][j] == 1) {
                    numNeighbors++;
                    r++;
                }
                r = i;
                while (r >= 0 && r < numRows && grid[r][j - 1] == 1) {
                    numNeighbors++;
                    r--;
                }
                r = i;
                while (r >= 0 && r < numRows && grid[r][j + 1] == 1) {
                    numNeighbors++;
                    r++;
                }
                r = i - 1;
                while (r >= 0 && r < numRows && grid[r][j + 1] == 1) {
                    numNeighbors++;
                    r--;
                }
                r = i + 1;
                while (r >= 0 && r < numRows && grid[r][j - 1] == 1) {
                    numNeighbors++;
                    r++;
                }
                if (numNeighbors == 2 || numNeighbors == 3) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    free(grid);
    return 0;
}