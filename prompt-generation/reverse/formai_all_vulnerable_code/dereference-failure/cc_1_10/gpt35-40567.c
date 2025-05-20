//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int percolationChecker(int **grid) {
    int flag = 0;
    //Checking if anything changed in the last iteration
    int changeFlag = 0;
    do {
        changeFlag = 0;
        for (int row = 1; row < N - 1; row++) {
            for (int col = 1; col < N - 1; col++) {
                if (grid[row][col] == 0) {
                    //Checking if surrounding cells are open
                    if (grid[row - 1][col] == 1 || grid[row + 1][col] == 1 ||
                        grid[row][col - 1] == 1 || grid[row][col + 1] == 1) {
                        changeFlag = 1;
                        grid[row][col] = 1;
                    }
                }
            }
        }
        if (changeFlag == 1) {
            //If something changed, set flag to true
            flag = 1;
        }
    } while (changeFlag == 1);

    return flag;
}

int main() {
    //Setting up random number generation for grid creation
    srand(time(NULL));

    //Initializing grid with randomly generated cells
    int **grid = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    printf("Initial Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    //Checking if percolation occurs
    int flag = percolationChecker(grid);

    printf("\nFinal Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    if (flag == 1) {
        printf("\nPercolation occurred!\n");
    } else {
        printf("\nPercolation did not occur.\n");
    }

    //Freeing allocated memory for grid
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}