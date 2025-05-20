//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, rows, cols, new_cell, living_neighbors;
    int **grid;
    srand(time(NULL));
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    grid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            new_cell = rand() % 2;
            if (new_cell == 0) {
                living_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) continue;
                        living_neighbors += grid[i + k][j + l];
                    }
                }
                if (living_neighbors == 3) grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    printf("Initial Grid: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    int generation = 0;
    while (1) {
        printf("Generation %d: \n", generation);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    new_cell = rand() % 2;
                    if (new_cell == 0) {
                        living_neighbors = 0;
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if (k == 0 && l == 0) continue;
                                living_neighbors += grid[i + k][j + l];
                            }
                        }
                        if (living_neighbors == 3) grid[i][j] = 1;
                    }
                } else {
                    new_cell = rand() % 2;
                    if (new_cell == 0) {
                        living_neighbors = 0;
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if (k == 0 && l == 0) continue;
                                living_neighbors += grid[i + k][j + l];
                            }
                        }
                        if (living_neighbors == 2 || living_neighbors == 3) grid[i][j] = 1;
                    }
                }
            }
        }
        generation++;
        if (generation % 100 == 0) {
            printf("The Game has ended!\n");
            break;
        }
    }
    
    free(grid);
    return 0;
}